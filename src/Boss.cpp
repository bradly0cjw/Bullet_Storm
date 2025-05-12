#include "Boss.hpp"
#include "Util/Logger.hpp"
#include "Util/Image.hpp" // For Drawable

Boss::Boss(const glm::vec2& position)
    : Enemy(position, RESOURCE_DIR "/enemy/boss.png", 0.0f), // Speed 0, boss controls its own movement logic
      m_Health(150), // Boss health
      m_Active(false),
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
    m_Health = 150; // Reset health if re-activating
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

    // Phase 1: Entry - move to position
    if (m_AttackPhase == 0)
    {
        if (m_Transform.translation.y > 150)
        {
            // Target Y position
            m_Transform.translation.y -= 1.0f; // Slow entry speed
        }
        else
        {
            m_AttackPhase = 1; // Reached position, start next phase
            m_PhaseTimer = 0.0f;
            LOG_INFO("Boss reached position, starting attack phase 1.");
        }
    }
    // Phase 1 actions (e.g., regular shooting, slight horizontal movement)
    else if (m_AttackPhase == 1)
    {
        m_PhaseTimer += 1.0f / 60.0f; // Assuming 60 FPS, increment timer
        // Simple horizontal patrol
        m_Transform.translation.x = std::sin(m_PhaseTimer * 0.5f) * 100.0f; // Patrols +/- 100 units horizontally

        if (CanShoot())
        {
            Shoot(playerPosition); // Standard shoot pattern
        }
        if (m_PhaseTimer > 15.0f)
        {
            // After 15 seconds, switch phase (example)
            m_AttackPhase = 2;
            m_PhaseTimer = 0.0f;
            LOG_INFO("Boss switching to attack phase 2.");
            m_ShootIntervalSeconds = 0.5f; // Faster shooting for phase 2
        }
    }
    // Phase 2 actions (e.g., faster shooting, different pattern)
    else if (m_AttackPhase == 2)
    {
        m_PhaseTimer += 1.0f / 60.0f;
        m_Transform.translation.x = std::cos(m_PhaseTimer * 0.8f) * 50.0f;


        if (CanShoot())
        {
            // More aggressive shoot pattern for phase 2
            // Example: Shoots 3 bullets in a spread
            glm::vec2 baseStartPos = GetPosition() + glm::vec2(0, -m_HitboxHeight_Private / 2.0f - 10.0f);
            glm::vec2 vel = glm::vec2(0.0f, -12.0f); // Faster bullets

            m_Bullets.push_back(
                std::make_shared<Bullet>(baseStartPos + glm::vec2(-40.0f, 0.0f), vel + glm::vec2(-2.0f, 0.0f)));
            m_Bullets.push_back(std::make_shared<Bullet>(baseStartPos, vel));
            m_Bullets.push_back(
                std::make_shared<Bullet>(baseStartPos + glm::vec2(40.0f, 0.0f), vel + glm::vec2(2.0f, 0.0f)));
            for (size_t i = m_Bullets.size() - 3; i < m_Bullets.size(); ++i)
            {
                // Make new bullets visible
                if (i < m_Bullets.size()) m_Bullets[i]->SetVisible(true);
            }
        }
        if (m_PhaseTimer > 20.0f)
        {
            // After 20 seconds, loop back to phase 1 (example)
            m_AttackPhase = 1;
            m_PhaseTimer = 0.0f;
            LOG_INFO("Boss looping back to attack phase 1.");
            m_ShootIntervalSeconds = 1.0f; // Reset shoot interval
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
    auto bulletL = std::make_shared<Bullet>(bulletStartPos + glm::vec2(-50, 0), glm::vec2(-1.5f, -9.0f));
    auto bulletR = std::make_shared<Bullet>(bulletStartPos + glm::vec2(50, 0), glm::vec2(1.5f, -9.0f));

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