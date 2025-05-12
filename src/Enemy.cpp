#include "Enemy.hpp"
#include "Util/Logger.hpp"
#include <cmath>   // For std::sin, std::rand
#include <cstdlib> // For std::rand, std::srand
#include <glm/gtx/vector_angle.hpp> // For aiming logic if needed, or just normalize

// Base Enemy Class Implementation
Enemy::Enemy(const glm::vec2& position, const std::string& imagePath, float speed)
    : Util::GameObject(std::make_shared<Util::Image>(imagePath), 10), // Default ZIndex for enemies
      m_Speed(speed),
      m_LastShootTime(std::chrono::steady_clock::now()),
      m_ShootIntervalSeconds(2.0f)
{
    // Default shoot interval: 2 seconds
    m_Transform.translation = position;
    SetVisible(true); // Enemies are visible by default when created
}

void Enemy::RmBullets(const std::shared_ptr<Bullet>& bullet)
{
    auto it = std::find(m_Bullets.begin(), m_Bullets.end(), bullet);
    if (it != m_Bullets.end())
    {
        m_Bullets.erase(it);
    }
}

bool Enemy::IsOutOfScreen() const
{
    // Define screen boundaries (example values, adjust to your game's screen size)
    // Assuming Y increases upwards, X increases to the right. Origin at center.
    // Player moves between y -300 to 300, x -400 to 400.
    // Enemies spawn at y=350 (original) or y=400 (my suggestion).
    // Let's use a generous boundary.
    const float screenTop = 450.0f;
    const float screenBottom = -450.0f;
    const float screenLeft = -450.0f;
    const float screenRight = 450.0f;

    return m_Transform.translation.y < screenBottom || m_Transform.translation.y > screenTop ||
        m_Transform.translation.x < screenLeft || m_Transform.translation.x > screenRight;
}

bool Enemy::CanShoot()
{
    auto now = std::chrono::steady_clock::now();
    if (std::chrono::duration_cast<std::chrono::milliseconds>(now - m_LastShootTime).count() >= static_cast<long long>(
        m_ShootIntervalSeconds * 1000.0f))
    {
        m_LastShootTime = now;
        return true;
    }
    return false;
}

glm::vec2 Enemy::GetBulletStartPosition() const
{
    // Default: front of enemy (assuming enemy image points "up" or "forward" along positive Y axis locally)
    // If enemies shoot "down" the screen, this might be GetPosition() + glm::vec2(0, -Height/2 - offset)
    // Original enemy bullet spawn: enemyPos + glm::vec2(0, -50);
    return GetPosition() + glm::vec2(0.0f, -30.0f); // Offset slightly below the enemy center
}

glm::vec2 Enemy::GetBulletVelocity(glm::vec2 playerPosition) const
{
    // Default: shoots straight down the screen
    (void)playerPosition; // Mark as unused for default non-homing bullets
    return glm::vec2(0.0f, -10.0f); // Velocity for downward movement (Y decreases)
}

void Enemy::Shoot(glm::vec2 playerPosition)
{
    glm::vec2 bulletStartPos = GetBulletStartPosition();
    glm::vec2 bulletVelocity = GetBulletVelocity(playerPosition);

    auto bullet = std::make_shared<Bullet>(bulletStartPos, bulletVelocity);
    m_Bullets.push_back(bullet);
    // Bullet visibility and adding to renderer is typically handled by App or a GameManager
    // For now, let's assume bullet becomes visible.
    bullet->SetVisible(true);
    // LOG_INFO("Base Enemy Shoot at ({}, {})", bulletStartPos.x, bulletStartPos.y);
}

// StraightEnemy Implementation
StraightEnemy::StraightEnemy(const glm::vec2& position)
    : Enemy(position, RESOURCE_DIR "/enemy/enemy_plane.png", 3.5f)
{
    // Slightly faster
    m_ShootIntervalSeconds = 2.5f;
}

void StraightEnemy::Update(glm::vec2 playerPosition)
{
    m_Transform.translation.y -= m_Speed; // Moves straight down
    if (CanShoot())
    {
        Shoot(playerPosition);
    }
    for (auto& bullet : m_Bullets)
    {
        bullet->Update();
    }
}

// WaveEnemy Implementation
WaveEnemy::WaveEnemy(const glm::vec2& position)
    : Enemy(position, RESOURCE_DIR "/enemy/e_tank2.png", 3.0f), m_WaveAngle(0.0f)
{
    m_ShootIntervalSeconds = 2.0f;
}

void WaveEnemy::Update(glm::vec2 playerPosition)
{
    m_Transform.translation.y -= m_Speed; // Moves down
    m_Transform.translation.x += std::sin(m_WaveAngle) * 4.0f; // Horizontal wave motion
    m_WaveAngle += 0.08f; // Adjust for wave frequency
    if (CanShoot())
    {
        Shoot(playerPosition);
    }
    for (auto& bullet : m_Bullets)
    {
        bullet->Update();
    }
}

// TrackEnemy Implementation
TrackEnemy::TrackEnemy(const glm::vec2& position)
    : Enemy(position, RESOURCE_DIR "/enemy/enemy_plane.png", 2.5f)
{
    // Slower for tracking
    m_ShootIntervalSeconds = 3.0f;
}

void TrackEnemy::Update(glm::vec2 playerPosition)
{
    // Move generally downwards
    m_Transform.translation.y -= m_Speed * 0.7f;

    // Track player's X position
    float trackspeed_x = m_Speed * 0.3f; // Speed for horizontal tracking
    if (playerPosition.x > m_Transform.translation.x)
    {
        m_Transform.translation.x += trackspeed_x;
    }
    else if (playerPosition.x < m_Transform.translation.x)
    {
        m_Transform.translation.x -= trackspeed_x;
    }
    // Clamp X to prevent excessive sideways movement (optional)
    // m_Transform.translation.x = glm::clamp(m_Transform.translation.x, -380.f, 380.f);


    if (CanShoot())
    {
        Shoot(playerPosition); // Could override Shoot to aim at player
    }
    for (auto& bullet : m_Bullets)
    {
        bullet->Update();
    }
}

// Example of TrackEnemy custom Shoot (aiming at player)
// void TrackEnemy::Shoot(glm::vec2 playerPosition) {
//     glm::vec2 startPos = GetBulletStartPosition();
//     glm::vec2 directionToPlayer = glm::normalize(playerPosition - startPos);
//     glm::vec2 bulletVelocity = directionToPlayer * 10.0f; // Bullet speed 10

//     auto bullet = std::make_shared<Bullet>(startPos, bulletVelocity);
//     m_Bullets.push_back(bullet);
//     bullet->SetVisible(true);
//     // LOG_INFO("TrackEnemy aimed shot");
// }


// ZigzagEnemy Implementation
ZigzagEnemy::ZigzagEnemy(const glm::vec2& position)
    : Enemy(position, RESOURCE_DIR "/enemy/e_tank1.png", 3.0f), m_ZigzagDirection(1), m_ZigzagCounter(0)
{
    m_ShootIntervalSeconds = 3.5f;
    if (std::rand() % 2 == 0) m_ZigzagDirection = -1; // Random initial direction
}

void ZigzagEnemy::Update(glm::vec2 playerPosition)
{
    m_Transform.translation.y -= m_Speed; // Moves down
    m_Transform.translation.x += m_ZigzagDirection * m_Speed * 0.5f; // Zigzag horizontally

    m_ZigzagCounter++;
    if (m_ZigzagCounter > 60)
    {
        // Change direction every ~1 second (60 frames)
        m_ZigzagDirection *= -1;
        m_ZigzagCounter = 0;
    }
    // Keep within bounds (optional, or let IsOutOfScreen handle it)
    // if (m_Transform.translation.x > 380.0f || m_Transform.translation.x < -380.0f) {
    //    m_ZigzagDirection *= -1;
    //    m_Transform.translation.x = glm::clamp(m_Transform.translation.x, -380.f, 380.f);
    // }

    if (CanShoot())
    {
        Shoot(playerPosition);
    }
    for (auto& bullet : m_Bullets)
    {
        bullet->Update();
    }
}

// RandomEnemy Implementation
RandomEnemy::RandomEnemy(const glm::vec2& position)
    : Enemy(position, RESOURCE_DIR "/enemy/enemy_plane.png", 2.8f)
{
    m_ShootIntervalSeconds = 2.2f;
}

void RandomEnemy::Update(glm::vec2 playerPosition)
{
    m_Transform.translation.y -= m_Speed; // Moves down
    // Small random horizontal drift
    m_Transform.translation.x += (static_cast<float>(std::rand() % 200 - 100) / 100.0f) * 1.5f;
    // Random drift between -1.5 and +1.5
    // Clamp X to prevent drifting too far (optional)
    // m_Transform.translation.x = glm::clamp(m_Transform.translation.x, -380.f, 380.f);

    if (CanShoot())
    {
        Shoot(playerPosition);
    }
    for (auto& bullet : m_Bullets)
    {
        bullet->Update();
    }
}