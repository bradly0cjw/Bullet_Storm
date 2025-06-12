#include "Boss.hpp"
#include "Util/Logger.hpp"
#include "Util/Image.hpp" // For Drawable
#include "Enemy.hpp"      // For ChargerEnemy
#include <limits>        // For std::numeric_limits
#include <glm/gtx/rotate_vector.hpp>


Boss::Boss(const glm::vec2& position)
    : Enemy(position, RESOURCE_DIR "/enemy/boss.png", 0.0f, 1), // Base enemy constructor now takes level
      m_Health(150), // Boss health
      m_Active(false),
      m_CurrentLevel(1), // Start at level 1
      m_MaxLevel(3), // Maximum of 3 levels
      m_HitboxWidth_Private(600.0f),
      m_HitboxHeight_Private(291.0f),
      m_AttackPhase(0),
      m_PhaseTimer(0.0f),
      m_LastMinionSpawnTime(std::chrono::steady_clock::now()),
      m_MinionSpawnIntervalSeconds(2.0f) // Example: spawn a minion every 3 seconds for L2
{
    SetVisible(false); // Initially invisible
    SetZIndex(100); // Ensure boss is rendered on top
    m_ShootIntervalSeconds = 1.0f; // Default shoot interval for L1 and L3
}

void Boss::Activate()
{
    m_Active = true;
    SetVisible(true);
    LOG_INFO("Boss Activated!");
    m_Transform.translation.y = 350;
    m_Health = 250 * m_CurrentLevel;
    m_AttackPhase = 0; // Reset phase for L1/L3 entry
    m_PhaseTimer = 0.0f;
    // ClearMinions(); // Clear any existing minions

    if (m_CurrentLevel == 2)
    {
        // For Level 2, we don't use phases in the same way.
        // The boss might have a simple movement pattern, and continuously spawns minions.
        // No bullets will be shot by the boss itself in L2.
        m_ShootIntervalSeconds = std::numeric_limits<float>::infinity(); // Disable standard shooting for L2
        LOG_INFO("Boss Level 2 activated: Minion summoning mode.");
    }
    else
    {
        // Reset shoot interval for L1/L3
        m_ShootIntervalSeconds = std::max(0.3f, 1.0f - (m_CurrentLevel - 1) * 0.2f);
    }
}

std::vector<std::shared_ptr<Enemy>> Boss::GetSpawnedMinions()
{
    return m_NewlySpawnedMinions;
}

void Boss::Update(glm::vec2 playerPosition)
{
    m_NewlySpawnedMinions.clear();
    LOG_INFO("Current Boss Level: {}", m_CurrentLevel);
    LOG_INFO("Current Attack Phase: {}", m_AttackPhase);
    if (!m_Active || IsDead())
    {
        // If dead, clear minions and bullets
        if (IsDead())
        {
            // ClearMinions();
            m_Bullets.clear(); // Clear boss's own bullets
        }
        return;
    }

    if (m_CurrentLevel == 2)
    {
        // Phase 0: Entry - move to position
        if (m_AttackPhase == 0)
        {
            if (m_Transform.translation.y > 150)
            {
                m_Transform.translation.y -= 1.0f;
            }
            else
            {
                m_AttackPhase = 1;
                m_PhaseTimer = 0.0f;
                LOG_INFO("Boss reached position, starting attack phase 1 for level {}.", m_CurrentLevel);
            }
        }
        m_PhaseTimer += 1.0f / 60.0f; // Assuming 60 FPS, increment timer for L2
        Level2ContinuousAttack(playerPosition);
    }
    else // Levels 1 and 3 use phase-based attacks
    {
        // Phase 0: Entry - move to position
        if (m_AttackPhase == 0)
        {
            if (m_Transform.translation.y > 150)
            {
                m_Transform.translation.y -= 1.0f;
            }
            else
            {
                m_AttackPhase = 1;
                m_PhaseTimer = 0.0f;
                LOG_INFO("Boss reached position, starting attack phase 1 for level {}.", m_CurrentLevel);
            }
        }
        // Regular attack phases
        else if (m_AttackPhase >= 1 && m_AttackPhase <= PHASES_PER_LEVEL)
        {
            m_PhaseTimer += 1.0f / 60.0f; // Assuming 60 FPS

            ExecuteAttackPattern(m_CurrentLevel, m_AttackPhase, playerPosition);

            // if (m_PhaseTimer > PHASE_DURATION || true) //Disable Timer
            // {
            //     m_PhaseTimer = 0.0f;
            //     m_AttackPhase = (m_AttackPhase % PHASES_PER_LEVEL) + 1;
            //     LOG_INFO("Boss switching to attack phase {} for level {}.", m_AttackPhase, m_CurrentLevel);
            // }
        }
    }

    // Update all boss bullets (if any, L2 boss won't shoot)
    for (auto it = m_Bullets.begin(); it != m_Bullets.end();)
    {
        (*it)->Update();
        if (!(*it)->InBound())
        {
            it = m_Bullets.erase(it);
        }
        else
        {
            ++it;
        }
    }

    // Update all minions
    // for (auto it = m_Minions.begin(); it != m_Minions.end(); ) {
    //     (*it)->Update(playerPosition);
    //     if (!(*it)->IsAlive() || (*it)->IsOutOfScreen()) { // Remove dead or off-screen minions
    //         it = m_Minions.erase(it);
    //     } else {
    //         ++it;
    //     }
    // }
}

// Standard shoot, but Level 2 boss will not use this.
void Boss::Shoot(glm::vec2 playerPosition)
{
    if (m_CurrentLevel == 2) return; // Level 2 boss does not shoot bullets.

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

void Boss::TakeDamage(int amount) // Parameter name changed to amount
{
    if (!m_Active || IsDead()) return;

    m_Health -= amount;
    LOG_INFO("Boss hit! Health: {}", m_Health);
    if (m_Health <= 0)
    {
        m_Health = 0;
        LOG_INFO("Boss defeated!");
        // Actual deactivation or "death sequence" might be handled by App based on IsDead()
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
        m_Health = 100 * m_CurrentLevel; // Base health scales with level
        // ClearMinions(); // Clear minions when level changes
        m_Bullets.clear(); // Clear existing bullets

        if (m_CurrentLevel == 2)
        {
            m_ShootIntervalSeconds = std::numeric_limits<float>::infinity(); // Disable standard shooting
            m_AttackPhase = 0; // Level 2 doesn't use phases, reset for safety
            m_PhaseTimer = 0.0f;
            LOG_INFO("Boss level set to: {}. Minion summoning mode.", m_CurrentLevel);
        }
        else
        {
            // Reset shoot interval and phase logic for L1/L3
            m_ShootIntervalSeconds = std::max(0.3f, 1.0f - (m_CurrentLevel - 1) * 0.2f);
            m_AttackPhase = 0; // Reset to entry phase for L1/L3
            m_PhaseTimer = 0.0f;
            LOG_INFO("Boss level set to: {}. Phase attack mode.", m_CurrentLevel);
        }
        // If boss is already active, these changes will apply on next Update.
        // If not active, Activate() will also apply these settings.
    }
}

void Boss::ExecuteAttackPattern(int level, int phase, glm::vec2 playerPosition)
{
    LOG_WARN("Current Level: {}, Phase: {}", level, phase);
    switch (level)
    {
    case 1:
        switch (phase)
        {
        case 1:
            Level1Phase1(playerPosition);
            break;
        case 2:
            Level1Phase2(playerPosition);
            break;
        case 3:
            Level1Phase3(playerPosition);
            break;
        default:
            LOG_ERROR("Invalid phase {} for level {}", phase, level);
        }
        m_AttackPhase = (m_AttackPhase % PHASES_PER_LEVEL) + 1;
        break;

    case 2:
        // Level 2 does not use phased attacks via ExecuteAttackPattern.
        // Its logic is self-contained in Level2ContinuousAttack, called from Update.
        // This case should ideally not be reached if Update() is structured correctly.
        Level2ContinuousAttack(playerPosition); // Fallback, though Update should handle L2 directly
        break;

    case 3:
        switch (phase)
        {
        case 1:
            Level1Phase1(playerPosition);
            Level2ContinuousAttack(playerPosition);
            break;
        case 2:
            Level1Phase2(playerPosition);
            Level2ContinuousAttack(playerPosition);
            break;
        case 3:
            Level1Phase3(playerPosition);
            Level2ContinuousAttack(playerPosition);
            break;
        default:
            LOG_ERROR("Invalid phase {} for level {}", phase, level);
        }
        m_AttackPhase = (m_AttackPhase % PHASES_PER_LEVEL) + 1;
        break;

    default:
        LOG_ERROR("Invalid boss level: {}", level);
        ExecuteAttackPattern(1, phase, playerPosition); // Fallback
    }
}

// Level 1 attack patterns (unchanged)
// void Boss::Level3Phase1(glm::vec2 playerPosition)
// {
//     // Simple horizontal patrol with basic shooting
//     m_Transform.translation.x = std::sin(m_PhaseTimer * 0.5f) * 100.0f;
//
//     if (CanShoot())
//     {
//         Shoot(playerPosition); // Standard 2-bullet pattern
//     }
// }
//
// void Boss::Level3Phase2(glm::vec2 playerPosition)
// {
//     // Faster horizontal movement with 3-bullet spread
//     m_Transform.translation.x = std::cos(m_PhaseTimer * 0.8f) * 50.0f;
//
//     if (CanShoot())
//     {
//         glm::vec2 baseStartPos = GetPosition() + glm::vec2(0, -m_HitboxHeight_Private / 2.0f - 10.0f);
//         glm::vec2 vel = glm::vec2(0.0f, -10.0f);
//
//         // 3-bullet spread
//         m_Bullets.push_back(std::make_shared<Bullet>(baseStartPos + glm::vec2(-40.0f, 0.0f),
//                                                      vel + glm::vec2(-2.0f, 0.0f), PowerUpType::RED, true));
//         m_Bullets.push_back(std::make_shared<Bullet>(baseStartPos, vel, PowerUpType::RED, true));
//         m_Bullets.push_back(std::make_shared<Bullet>(baseStartPos + glm::vec2(40.0f, 0.0f), vel + glm::vec2(2.0f, 0.0f),
//                                                      PowerUpType::RED, true));
//
//         for (size_t i = m_Bullets.size() - 3; i < m_Bullets.size(); ++i)
//         {
//             if (i < m_Bullets.size()) m_Bullets[i]->SetVisible(true);
//         }
//     }
// }
//
// void Boss::Level3Phase3(glm::vec2 playerPosition)
// {
//     // Zigzag movement with targeted shots
//     static float zigzagTimer = 0.0f; // This static might cause issues if boss is reset/reactivated
//     zigzagTimer += 0.02f;            // Consider making it a member if problematic
//
//     m_Transform.translation.x = std::sin(zigzagTimer * 2.0f) * 120.0f;
//
//     if (CanShoot())
//     {
//         glm::vec2 bulletStartPos = GetBulletStartPosition() + glm::vec2(0.0f, -m_HitboxHeight_Private / 2.0f + 20.0f);
//         glm::vec2 dirToPlayer = glm::normalize(playerPosition - bulletStartPos);
//         glm::vec2 bulletVelocity = dirToPlayer * 10.0f;
//
//         auto bullet = std::make_shared<Bullet>(bulletStartPos, bulletVelocity, PowerUpType::RED, true);
//         m_Bullets.push_back(bullet);
//         bullet->SetVisible(true);
//     }
// }


// New Level 2 Continuous Attack
void Boss::Level2ContinuousAttack(glm::vec2 playerPosition)
{
    // Simple movement for the boss in Level 2 (e.g., slow horizontal patrol)
    // Use m_PhaseTimer which is now updated for Level 2 in the Update() method.
    // m_Transform.translation.x = std::sin(m_PhaseTimer * 0.3f) * 150.0f;

    // Spawn Charger minions
    if (CanSpawnMinion())
    {
        SpawnChargerMinion(playerPosition);
    }
    // Boss does not shoot bullets itself in this level.
}

// Remove Old Level 2 phase implementations
// void Boss::Level2Phase1(glm::vec2 playerPosition) { /* ... old code ... */ }
// void Boss::Level2Phase2(glm::vec2 playerPosition) { /* ... old code ... */ }
// void Boss::Level2Phase3(glm::vec2 playerPosition) { /* ... old code ... */ }


// Level 1 attack patterns (unchanged)
void Boss::Level1Phase1(glm::vec2 playerPosition)
{
    // MOVEMENT REMOVED: The boss is now stationary in this phase.

    // SHOOTING: Fire a 5-bullet spread aimed at the player.
    if (CanShoot())
    {
        glm::vec2 bulletStartPos = GetPosition() + glm::vec2(0, -m_HitboxHeight_Private / 2.0f - 10.0f);

        // Calculate the central direction towards the player.
        glm::vec2 dirToPlayer = glm::normalize(playerPosition - bulletStartPos);
        float bulletSpeed = 10.0f;

        // Create 5 bullets in a cone aimed at the player.
        // The angles are in radians. 15 degrees = 0.26 radians.
        m_Bullets.push_back(std::make_shared<Bullet>(bulletStartPos, glm::rotate(dirToPlayer, -0.52f) * bulletSpeed,
                                                     PowerUpType::RED, true)); // -30 deg
        m_Bullets.push_back(std::make_shared<Bullet>(bulletStartPos, glm::rotate(dirToPlayer, -0.26f) * bulletSpeed,
                                                     PowerUpType::RED, true)); // -15 deg
        m_Bullets.push_back(std::make_shared<Bullet>(bulletStartPos, dirToPlayer * bulletSpeed, PowerUpType::RED,
                                                     true)); //   0 deg
        m_Bullets.push_back(std::make_shared<Bullet>(bulletStartPos, glm::rotate(dirToPlayer, 0.26f) * bulletSpeed,
                                                     PowerUpType::RED, true)); // +15 deg
        m_Bullets.push_back(std::make_shared<Bullet>(bulletStartPos, glm::rotate(dirToPlayer, 0.52f) * bulletSpeed,
                                                     PowerUpType::RED, true)); // +30 deg

        // Make the new bullets visible
        for (size_t i = m_Bullets.size() - 5; i < m_Bullets.size(); ++i)
        {
            if (i < m_Bullets.size()) m_Bullets[i]->SetVisible(true);
        }
    }
}

void Boss::Level1Phase2(glm::vec2 playerPosition)
{
    // MOVEMENT REMOVED: The boss no longer teleports.

    // SHOOTING: Fire a "shotgun blast" of 8 bullets in the player's general direction.
    if (CanShoot())
    {
        glm::vec2 baseStartPos = GetPosition();
        float bulletSpeed = 10.0f;

        // Calculate the central direction towards the player.
        glm::vec2 dirToPlayer = glm::normalize(playerPosition - baseStartPos);

        // The total angle for the spread (e.g., 60 degrees = 1.047 radians).
        const float spreadAngle = 1.047f;

        for (int i = 0; i < 8; i++)
        {
            // Get a random angle within the spread.
            float randomOffset = (static_cast<float>(std::rand()) / RAND_MAX - 0.5f) * spreadAngle;

            // Rotate the base direction vector by the random offset.
            glm::vec2 velocity = glm::rotate(dirToPlayer, randomOffset) * bulletSpeed;

            m_Bullets.push_back(std::make_shared<Bullet>(baseStartPos, velocity, PowerUpType::RED, true));
        }

        // Make the new bullets visible
        for (size_t i = m_Bullets.size() - 8; i < m_Bullets.size(); ++i)
        {
            if (i < m_Bullets.size()) m_Bullets[i]->SetVisible(true);
        }
    }
}

void Boss::Level1Phase3(glm::vec2 playerPosition)
{
    // MOVEMENT REMOVED: The boss no longer moves in a spiral.

    // SHOOTING: This pattern already aims at the player, so the logic is kept.
    // It fires one bullet directly at the player and two perpendicular to that shot.
    if (CanShoot())
    {
        glm::vec2 bulletStartPos = GetBulletStartPosition();
        glm::vec2 dirToPlayer = glm::normalize(playerPosition - bulletStartPos);

        // Bullet 1: Aims directly at the player.
        glm::vec2 aimedVelocity = dirToPlayer * 12.0f;
        m_Bullets.push_back(std::make_shared<Bullet>(bulletStartPos, aimedVelocity, PowerUpType::RED, true));

        // Bullets 2 & 3: Fire perpendicular to the aimed shot.
        glm::vec2 perpendicular = glm::vec2(-dirToPlayer.y, dirToPlayer.x);
        m_Bullets.push_back(std::make_shared<Bullet>(bulletStartPos, perpendicular * 8.0f, PowerUpType::RED, true));
        m_Bullets.push_back(std::make_shared<Bullet>(bulletStartPos, -perpendicular * 8.0f, PowerUpType::RED, true));

        // Make the new bullets visible
        for (size_t i = m_Bullets.size() - 3; i < m_Bullets.size(); ++i)
        {
            if (i < m_Bullets.size()) m_Bullets[i]->SetVisible(true);
        }
    }
}


// Minion Spawning Helper Methods
bool Boss::CanSpawnMinion()
{
    if (m_CurrentLevel < 2) return false; // Only L2  L3 boss spawns minions this way

    auto now = std::chrono::steady_clock::now();
    if (std::chrono::duration_cast<std::chrono::milliseconds>(now - m_LastMinionSpawnTime).count() >=
        static_cast<long long>(m_MinionSpawnIntervalSeconds * 1000.0f))
    {
        m_LastMinionSpawnTime = now;
        return true;
    }
    return false;
}

void Boss::SpawnChargerMinion(const glm::vec2& playerPosition)
{
    // Spawn 5 charger minions spread horizontally
    int numMinions = 5;
    float totalWidth = m_HitboxWidth_Private + 200.0f; // Total width for minions to spread
    float spacing = totalWidth / (numMinions - 1); // Spacing between minions

    glm::vec2 baseSpawnPos = GetPosition() + glm::vec2(-totalWidth / 2.0f, 0.0f); // Start from the left

    for (int i = 0; i < numMinions; ++i)
    {
        glm::vec2 spawnPos = baseSpawnPos + glm::vec2(i * spacing, 0.0f);

        // ChargerEnemy level could be fixed or based on boss's current state/level
        auto charger = std::make_shared<ChargerEnemy>(spawnPos, 1); // Spawn level 1 chargers for now
        charger->SetVisible(true);
        m_NewlySpawnedMinions.push_back(charger);
        LOG_INFO("Boss spawned a Charger minion at ({}, {}). Player at ({},{})", spawnPos.x, spawnPos.y,
                 playerPosition.x, playerPosition.y);
    }
}

// void Boss::ClearMinions()
// {
//     m_Minions.clear();
//     LOG_INFO("Boss minions cleared.");
// }

// Need to ensure Util::Time::GetElapsedTimeSeconds() is available. If not, use m_PhaseTimer or another timer.
// For Level1Phase3 and Level3Phase2, static timers (zigzagTimer, teleportTimer) might cause issues
// if the boss is deactivated and reactivated, or if multiple boss instances were ever a thing.
// It's safer to make them member variables if they need to persist reliably across activations for a single boss instance.
// For now, assuming they are reset implicitly or their behavior is acceptable with static.
