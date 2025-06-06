#include "Boss.hpp"
#include "Util/Logger.hpp"
#include "Util/Image.hpp" // For Drawable

Boss::Boss(const glm::vec2& position)
    : Enemy(position, RESOURCE_DIR "/enemy/boss.png", 0.0f), // Speed 0, boss controls its own movement logic
      m_Health(150), // Boss health
      m_Active(false),
      m_CurrentLevel(1), // Start at level 1
      m_MaxLevel(3), // Maximum of 3 levels
      m_HitboxWidth_Private(600.0f), // Using dimensions from your snippet
      m_HitboxHeight_Private(291.0f),
      m_AttackPhase(0),
      m_PhaseTimer(0.0f)
{
    SetVisible(false); // Initially invisible
    SetZIndex(100); // Ensure boss is rendered on top
    m_ShootIntervalSeconds = 1.0f; // Boss shoots frequently
}

void Boss::Activate()
{
    m_Active = true;
    SetVisible(true);
    LOG_INFO("Boss Activated!");
    // Reset any boss specific state if re-activating
    m_Transform.translation.y = 350; // Reset to entry Y if needed (original spawn Y was 350)
    m_Health = 100 * m_CurrentLevel; // Health scales with level
    m_AttackPhase = 0;
    m_PhaseTimer = 0.0f;
}

void Boss::Update(glm::vec2 playerPosition)
{
    if (!m_Active || IsDead())
    {
        // If dead, maybe trigger an explosion animation then SetVisible(false) after a delay.
        // For now, if dead and active, it might just stop.
        // If simply not active, do nothing.
        return;
    }

    // Phase 0: Entry - move to position
    if (m_AttackPhase == 0)
    {
        if (m_Transform.translation.y > 150)
        {
            // Target Y position
            m_Transform.translation.y -= 1.0f; // Slow entry speed
        }
        else
        {
            m_AttackPhase = 1; // Reached position, start first attack phase
            m_PhaseTimer = 0.0f;
            LOG_INFO("Boss reached position, starting attack phase 1 for level {}.", m_CurrentLevel);
        }
    }
    // Regular attack phases (1-3)
    else if (m_AttackPhase >= 1 && m_AttackPhase <= PHASES_PER_LEVEL)
    {
        // Update the phase timer
        m_PhaseTimer += 1.0f / 60.0f; // Assuming 60 FPS

        // Execute the appropriate attack pattern based on current level and phase
        ExecuteAttackPattern(m_CurrentLevel, m_AttackPhase, playerPosition);

        // Check if it's time to switch to next phase
        if (m_PhaseTimer > PHASE_DURATION)
        {
            m_PhaseTimer = 0.0f;
            m_AttackPhase = (m_AttackPhase % PHASES_PER_LEVEL) + 1; // Cycle through phases 1-3
            LOG_INFO("Boss switching to attack phase {} for level {}.", m_AttackPhase, m_CurrentLevel);
        }
    }

    // Update all boss bullets
    for (auto& bullet : m_Bullets)
    {
        bullet->Update();
    }
}

// Default Boss Shoot (can be simple, overridden by phase logic in Update if needed)
void Boss::Shoot(glm::vec2 playerPosition)
{
    // This is the "standard" shoot, specific phases might have their own logic in Update
    glm::vec2 bulletStartPos = GetBulletStartPosition() + glm::vec2(0.0f, -m_HitboxHeight_Private / 2.0f + 20.0f);
    // Adjust Y based on boss sprite

    // Example: Fire two bullets slightly angled
    // Pass true for isEnemyBullet and a default PowerUpType
    auto bulletL = std::make_shared<Bullet>(bulletStartPos + glm::vec2(-50, 0), glm::vec2(-1.5f, -9.0f),
                                            PowerUpType::RED, true);
    auto bulletR = std::make_shared<Bullet>(bulletStartPos + glm::vec2(50, 0), glm::vec2(1.5f, -9.0f), PowerUpType::RED, true);

    m_Bullets.push_back(bulletL);
    m_Bullets.push_back(bulletR);
    bulletL->SetVisible(true);
    bulletR->SetVisible(true);

    // LOG_INFO("Boss standard shot");
}

void Boss::TakeDamage(int amount)
{
    if (!m_Active || IsDead()) return;

    m_Health -= amount;
    LOG_INFO("Boss hit! Health: {}", m_Health);
    if (m_Health <= 0)
    {
        m_Health = 0;
        // SetVisible(false); // Or trigger death animation then hide
        LOG_INFO("Boss defeated!");
        // m_Active = false; // Stop boss logic, or let game state handle it
        // Death handling (like setting visible false, stopping activity) might be better done
        // in App.cpp when IsDead() becomes true, to allow for death animations/effects.
    }
}

bool Boss::IsDead() const {
    return m_Health <= 0;
}

void Boss::SetLevel(int level)
{
    if (level > 0 && level <= m_MaxLevel)
    {
        m_CurrentLevel = level;
        // Adjust boss health and other attributes based on level
        m_Health = 100 * m_CurrentLevel;
        m_ShootIntervalSeconds = std::max(0.3f, 1.0f - (m_CurrentLevel - 1) * 0.2f); // Shoots faster at higher levels
        LOG_INFO("Boss level set to: {}", m_CurrentLevel);
    }
}

void Boss::ExecuteAttackPattern(int level, int phase, glm::vec2 playerPosition)
{
    // Route to the proper attack pattern based on level and phase
    switch (level)
    {
    case 1:
        switch (phase)
        {
        case 1: Level1Phase1(playerPosition);
            break;
        case 2: Level1Phase2(playerPosition);
            break;
        case 3: Level1Phase3(playerPosition);
            break;
        default: LOG_ERROR("Invalid phase {} for level {}", phase, level);
        }
        break;

    case 2:
        switch (phase)
        {
        case 1: Level2Phase1(playerPosition);
            break;
        case 2: Level2Phase2(playerPosition);
            break;
        case 3: Level2Phase3(playerPosition);
            break;
        default: LOG_ERROR("Invalid phase {} for level {}", phase, level);
        }
        break;

    case 3:
        switch (phase)
        {
        case 1: Level3Phase1(playerPosition);
            break;
        case 2: Level3Phase2(playerPosition);
            break;
        case 3: Level3Phase3(playerPosition);
            break;
        default: LOG_ERROR("Invalid phase {} for level {}", phase, level);
        }
        break;

    default:
        LOG_ERROR("Invalid boss level: {}", level);
        // Fallback to level 1 patterns
        ExecuteAttackPattern(1, phase, playerPosition);
    }
}

// Level 1 attack patterns

void Boss::Level1Phase1(glm::vec2 playerPosition)
{
    // Simple horizontal patrol with basic shooting
    m_Transform.translation.x = std::sin(m_PhaseTimer * 0.5f) * 100.0f;

    if (CanShoot())
    {
        Shoot(playerPosition); // Standard 2-bullet pattern
    }
}

void Boss::Level1Phase2(glm::vec2 playerPosition)
{
    // Faster horizontal movement with 3-bullet spread
    m_Transform.translation.x = std::cos(m_PhaseTimer * 0.8f) * 50.0f;

    if (CanShoot())
    {
        glm::vec2 baseStartPos = GetPosition() + glm::vec2(0, -m_HitboxHeight_Private / 2.0f - 10.0f);
        glm::vec2 vel = glm::vec2(0.0f, -10.0f);

        // 3-bullet spread
        m_Bullets.push_back(std::make_shared<Bullet>(baseStartPos + glm::vec2(-40.0f, 0.0f),
                                                     vel + glm::vec2(-2.0f, 0.0f), PowerUpType::RED, true));
        m_Bullets.push_back(std::make_shared<Bullet>(baseStartPos, vel, PowerUpType::RED, true));
        m_Bullets.push_back(std::make_shared<Bullet>(baseStartPos + glm::vec2(40.0f, 0.0f), vel + glm::vec2(2.0f, 0.0f),
                                                     PowerUpType::RED, true));

        for (size_t i = m_Bullets.size() - 3; i < m_Bullets.size(); ++i)
        {
            if (i < m_Bullets.size()) m_Bullets[i]->SetVisible(true);
        }
    }
}

void Boss::Level1Phase3(glm::vec2 playerPosition)
{
    // Zigzag movement with targeted shots
    static float zigzagTimer = 0.0f;
    zigzagTimer += 0.02f;

    // Zigzag pattern
    m_Transform.translation.x = std::sin(zigzagTimer * 2.0f) * 120.0f;

    if (CanShoot())
    {
        glm::vec2 bulletStartPos = GetBulletStartPosition() + glm::vec2(0.0f, -m_HitboxHeight_Private / 2.0f + 20.0f);

        // Calculate direction to player for aiming
        glm::vec2 dirToPlayer = glm::normalize(playerPosition - bulletStartPos);
        glm::vec2 bulletVelocity = dirToPlayer * 10.0f; // Directed bullet

        auto bullet = std::make_shared<Bullet>(bulletStartPos, bulletVelocity, PowerUpType::RED, true);
        m_Bullets.push_back(bullet);
        bullet->SetVisible(true);
    }
}

// Level 2 attack patterns

void Boss::Level2Phase1(glm::vec2 playerPosition)
{
    // Circle movement pattern
    float radius = 80.0f;
    m_Transform.translation.x = std::sin(m_PhaseTimer) * radius;
    m_Transform.translation.y = 150.0f + std::cos(m_PhaseTimer) * radius * 0.5f; // Oval motion

    if (CanShoot())
    {
        // Dual spread shots - 4 bullets
        glm::vec2 baseStartPos = GetPosition() + glm::vec2(0, -m_HitboxHeight_Private / 2.0f - 10.0f);

        // Left spread
        m_Bullets.push_back(std::make_shared<Bullet>(baseStartPos + glm::vec2(-30.0f, 0.0f),
                                                     glm::vec2(-3.0f, -10.0f), PowerUpType::RED, true));
        m_Bullets.push_back(std::make_shared<Bullet>(baseStartPos + glm::vec2(-10.0f, 0.0f),
                                                     glm::vec2(-1.0f, -10.0f), PowerUpType::RED, true));

        // Right spread
        m_Bullets.push_back(std::make_shared<Bullet>(baseStartPos + glm::vec2(10.0f, 0.0f),
                                                     glm::vec2(1.0f, -10.0f), PowerUpType::RED, true));
        m_Bullets.push_back(std::make_shared<Bullet>(baseStartPos + glm::vec2(30.0f, 0.0f),
                                                     glm::vec2(3.0f, -10.0f), PowerUpType::RED, true));

        for (size_t i = m_Bullets.size() - 4; i < m_Bullets.size(); ++i)
        {
            if (i < m_Bullets.size()) m_Bullets[i]->SetVisible(true);
        }
    }
}

void Boss::Level2Phase2(glm::vec2 playerPosition)
{
    // Quick charging movement pattern
    static int chargeDirection = 1;
    static float chargeTimer = 0.0f;

    chargeTimer += 1.0f / 60.0f;

    // Alternates between pausing and charging horizontally
    if (chargeTimer > 2.0f)
    {
        chargeDirection *= -1;
        chargeTimer = 0.0f;
    }

    // Fast horizontal movement with brief pauses
    if (chargeTimer < 0.5f)
    {
        // Pause
    }
    else
    {
        // Charge
        m_Transform.translation.x += chargeDirection * 5.0f;

        // Keep within screen bounds
        if (m_Transform.translation.x > 300.0f) m_Transform.translation.x = 300.0f;
        if (m_Transform.translation.x < -300.0f) m_Transform.translation.x = -300.0f;
    }

    if (CanShoot())
    {
        // Burst of bullets during charge
        glm::vec2 baseStartPos = GetPosition() + glm::vec2(0, -m_HitboxHeight_Private / 2.0f - 10.0f);

        // Create 5 bullets in a vertical line
        for (int i = 0; i < 5; i++)
        {
            float offsetY = -20.0f * i;
            m_Bullets.push_back(std::make_shared<Bullet>(
                baseStartPos + glm::vec2(0.0f, offsetY),
                glm::vec2(0.0f, -8.0f - i * 0.5f), // Increasing speed
                PowerUpType::RED,
                true
            ));
        }

        for (size_t i = m_Bullets.size() - 5; i < m_Bullets.size(); ++i)
        {
            if (i < m_Bullets.size()) m_Bullets[i]->SetVisible(true);
        }
    }
}

void Boss::Level2Phase3(glm::vec2 playerPosition)
{
    // Wave pattern with alternating side shots
    m_Transform.translation.x = std::sin(m_PhaseTimer * 0.4f) * 150.0f;

    if (CanShoot())
    {
        glm::vec2 baseStartPos = GetPosition() + glm::vec2(0, -m_HitboxHeight_Private / 2.0f - 10.0f);

        // Determine which side to shoot from based on timer
        bool shootLeft = static_cast<int>(m_PhaseTimer) % 2 == 0;
        glm::vec2 sideOffset = shootLeft ? glm::vec2(-60.0f, 0.0f) : glm::vec2(60.0f, 0.0f);
        glm::vec2 sideVelocity = shootLeft ? glm::vec2(-2.0f, -10.0f) : glm::vec2(2.0f, -10.0f);

        // Side shot
        m_Bullets.push_back(std::make_shared<Bullet>(baseStartPos + sideOffset, sideVelocity, PowerUpType::RED, true));

        // Center shot always fires
        m_Bullets.push_back(std::make_shared<Bullet>(baseStartPos, glm::vec2(0.0f, -10.0f), PowerUpType::RED, true));

        for (size_t i = m_Bullets.size() - 2; i < m_Bullets.size(); ++i)
        {
            if (i < m_Bullets.size()) m_Bullets[i]->SetVisible(true);
        }
    }
}

// Level 3 attack patterns

void Boss::Level3Phase1(glm::vec2 playerPosition)
{
    // Aggressive tracking movement that follows player's X position
    float targetX = playerPosition.x;
    float currentX = m_Transform.translation.x;
    float moveSpeed = 2.5f;

    // Move toward player's X position
    if (std::abs(targetX - currentX) > 10.0f)
    {
        if (targetX > currentX)
        {
            m_Transform.translation.x += moveSpeed;
        }
        else
        {
            m_Transform.translation.x -= moveSpeed;
        }
    }

    if (CanShoot())
    {
        // Cross-pattern with 5 bullets
        glm::vec2 baseStartPos = GetPosition() + glm::vec2(0, -m_HitboxHeight_Private / 2.0f - 10.0f);

        // Center bullet
        m_Bullets.push_back(std::make_shared<Bullet>(baseStartPos, glm::vec2(0.0f, -12.0f), PowerUpType::RED, true));

        // Cross pattern
        m_Bullets.push_back(std::make_shared<Bullet>(baseStartPos, glm::vec2(-3.0f, -9.0f), PowerUpType::RED, true));
        m_Bullets.push_back(std::make_shared<Bullet>(baseStartPos, glm::vec2(3.0f, -9.0f), PowerUpType::RED, true));
        m_Bullets.push_back(std::make_shared<Bullet>(baseStartPos, glm::vec2(-6.0f, -6.0f), PowerUpType::RED, true));
        m_Bullets.push_back(std::make_shared<Bullet>(baseStartPos, glm::vec2(6.0f, -6.0f), PowerUpType::RED, true));

        for (size_t i = m_Bullets.size() - 5; i < m_Bullets.size(); ++i)
        {
            if (i < m_Bullets.size()) m_Bullets[i]->SetVisible(true);
        }
    }
}

void Boss::Level3Phase2(glm::vec2 playerPosition)
{
    // Rapid teleport pattern (quickly jump between positions)
    static float teleportTimer = 0.0f;
    teleportTimer += 1.0f / 60.0f;

    if (teleportTimer > 1.5f)
    {
        // "Teleport" to a new position
        m_Transform.translation.x = std::rand() % 500 - 250.0f; // Random X between -250 and 250
        teleportTimer = 0.0f;
    }

    if (CanShoot() && teleportTimer < 0.5f) // Only shoot right after teleporting
    {
        // 360-degree bullet spread (8 directions)
        glm::vec2 baseStartPos = GetPosition();
        float bulletSpeed = 10.0f;

        for (int i = 0; i < 8; i++)
        {
            float angle = i * (2.0f * M_PI / 8.0f);
            glm::vec2 velocity(std::cos(angle) * bulletSpeed, std::sin(angle) * bulletSpeed);

            m_Bullets.push_back(std::make_shared<Bullet>(baseStartPos, velocity, PowerUpType::RED, true));
        }

        for (size_t i = m_Bullets.size() - 8; i < m_Bullets.size(); ++i)
        {
            if (i < m_Bullets.size()) m_Bullets[i]->SetVisible(true);
        }
    }
}

void Boss::Level3Phase3(glm::vec2 playerPosition)
{
    // Spiral attack pattern with both movement and bullets
    m_PhaseTimer += 1.0f / 60.0f;

    // Aggressive spiral movement
    float spiralRadius = 100.0f + std::sin(m_PhaseTimer * 0.5f) * 50.0f; // Changing radius
    m_Transform.translation.x = std::sin(m_PhaseTimer * 2.0f) * spiralRadius;
    m_Transform.translation.y = 150.0f + std::cos(m_PhaseTimer * 2.0f) * spiralRadius * 0.5f;

    if (CanShoot())
    {
        // Aimed shots plus side shots
        glm::vec2 bulletStartPos = GetBulletStartPosition();

        // Aimed bullet at player
        glm::vec2 dirToPlayer = glm::normalize(playerPosition - bulletStartPos);
        glm::vec2 aimedVelocity = dirToPlayer * 12.0f;

        // Main aimed shot
        m_Bullets.push_back(std::make_shared<Bullet>(bulletStartPos, aimedVelocity, PowerUpType::RED, true));

        // Two side shots perpendicular to aim direction
        glm::vec2 perpendicular(-dirToPlayer.y, dirToPlayer.x);
        m_Bullets.push_back(std::make_shared<Bullet>(bulletStartPos, perpendicular * 8.0f, PowerUpType::RED, true));
        m_Bullets.push_back(std::make_shared<Bullet>(bulletStartPos, -perpendicular * 8.0f, PowerUpType::RED, true));

        for (size_t i = m_Bullets.size() - 3; i < m_Bullets.size(); ++i)
        {
            if (i < m_Bullets.size()) m_Bullets[i]->SetVisible(true);
        }
    }
}
