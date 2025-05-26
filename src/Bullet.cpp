#include "Bullet.hpp"
#include "Util/Logger.hpp"
#include "Boss.hpp" // For dynamic_pointer_cast, consider forward declaration if only type is needed
#include "Enemy.hpp"  // For std::shared_ptr<Enemy> in homing constructor
#include <cmath>    // for std::atan2, M_PI

// Constructor for normal bullets, now selects image based on PowerUpType and isEnemyBullet flag
Bullet::Bullet(const glm::vec2& position, const glm::vec2& velocity, PowerUpType type, bool isEnemyBullet)
    : m_Velocity(velocity), m_IsHoming(false), m_HomingSpeed(0.0f)
{
    // Initialize all members
    std::string bulletImagePath;
    if (isEnemyBullet)
    {
        bulletImagePath = RESOURCE_DIR "/enemy/bullet_enemy.png"; // Use enemy_plane.png for enemy bullets
    }
    else
    {
        switch (type)
        {
        case PowerUpType::RED:
            bulletImagePath = RESOURCE_DIR "/character/bullet_R.png";
            break;
        case PowerUpType::BLUE:
            bulletImagePath = RESOURCE_DIR "/character/bullet_B.png";
            break;
        case PowerUpType::PURPLE:
            bulletImagePath = RESOURCE_DIR "/character/bullet_P.png";
            break;
        default:
            bulletImagePath = RESOURCE_DIR "/character/bullet_R.png"; // Default for player
            break;
        }
    }
    m_Drawable = std::make_shared<Util::Image>(bulletImagePath);
    m_Transform.translation = position;
    SetVisible(true);
    SetZIndex(1); // Ensure z-index is set

    if (!m_Drawable)
    {
        LOG_ERROR("Bullet image failed to load: {}", bulletImagePath);
    }
}

// Constructor for homing missiles
Bullet::Bullet(const glm::vec2& position, float speed, const std::shared_ptr<Enemy>& target)
    : Util::GameObject(
          std::make_shared<Util::Image>(RESOURCE_DIR "/character/missiles.png"),
          /*zIndex=*/1 // Corrected comment for zIndex
      ),
      m_Velocity(0.0f, 0.0f), // m_Velocity is initialized below
      m_HomingSpeed(speed),
      m_HomingTarget(target),
      m_IsHoming(true)
{
    m_Transform.translation = position;
    SetVisible(true); // Ensure visibility is set

    // Initialize velocity for homing missiles
    if (auto t = m_HomingTarget.lock()) {
        glm::vec2 dir = glm::normalize(t->GetTransform().translation - position);
        m_Velocity = dir * speed; // Simplified velocity calculation
    }
    else {
        // Default velocity if no target (e.g., straight up)
        m_Velocity = glm::vec2(0.0f, speed);
    }
    if (!m_Drawable)
    {
        LOG_ERROR("Homing missile image failed to load!");
    }
}

bool Bullet::CollidesWith(const std::shared_ptr<Util::GameObject>& other) const {
    glm::vec2 bulletPos = m_Transform.translation;
    glm::vec2 targetPos = other->GetTransform().translation;

    // 取得對方 hitbox（如果是 Boss，就用自定義範圍；否則預設）
    float halfW = 32.0f;
    float halfH = 32.0f;

    // 判斷是否是 Boss 並轉型
    if (auto boss = std::dynamic_pointer_cast<Boss>(other)) {
        halfW = boss->GetHitboxWidth() / 2.0f;
        halfH = boss->GetHitboxHeight() / 2.0f;
    }

    return (
        bulletPos.x > targetPos.x - halfW &&
        bulletPos.x < targetPos.x + halfW &&
        bulletPos.y > targetPos.y - halfH &&
        bulletPos.y < targetPos.y + halfH
    );
}


void Bullet::Update() {
    if (m_IsHoming) {
        if (auto t = m_HomingTarget.lock()) {
            // 取當前位置跟目標方向
            glm::vec2 dir = glm::normalize(t->GetTransform().translation - m_Transform.translation);
            // 分量乘速率
            m_Velocity = glm::vec2(dir.x * m_HomingSpeed, dir.y * m_HomingSpeed);
        }
    }
    m_Transform.translation += m_Velocity;


    //LOG_INFO("Bullet position: ({}, {})", m_Transform.translation.x, m_Transform.translation.y);
}

[[nodiscard]] bool Bullet::InBound()
{
    // Added [[nodiscard]] here as well, as it was in the .hpp
    if (m_Transform.translation.y < -400 || m_Transform.translation.y > 400) {
        SetVisible(false);
        return false;
    }
    return true;
}

