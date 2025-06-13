#include "Bullet.hpp"
#include "Util/Logger.hpp"
#include "Boss.hpp"   // For dynamic_pointer_cast
#include "Enemy.hpp"  // For std::shared_ptr<Enemy>
#include <cmath>      // for std::atan2, M_PI (though not used in current snippet directly)
#include "Util/Image.hpp" // Ensure this is included for std::make_shared<Util::Image>

// Anonymous namespace for helper function
namespace
{
    std::string GetImagePathForBullet(PowerUpType type, bool isEnemyBullet)
    {
        std::string path;
        if (isEnemyBullet)
        {
            path = RESOURCE_DIR "/enemy/bullet_enemy.png";
        }
        else
        {
            // Player's bullet
            switch (type)
            {
            case PowerUpType::RED:
                path = RESOURCE_DIR "/character/bullet_R.png";
                break;
            case PowerUpType::BLUE:
                path = RESOURCE_DIR "/character/bullet_B1.png";
                break;
            case PowerUpType::PURPLE: // This will be used by purple homing bullets
                path = RESOURCE_DIR "/character/bullet_P.png";
                break;
            case PowerUpType::M:
                path = RESOURCE_DIR "/character/missiles.png"; // Assuming M is a special bullet type
                break;
            default:
                LOG_WARN(
                    "GetImagePathForBullet: Unexpected PowerUpType {} for player bullet. Using default red bullet image.",
                    static_cast<int>(type));
                path = RESOURCE_DIR "/character/bullet_R.png"; // Fallback player bullet
                break;
            }
        }
        return path;
    }
} // end anonymous namespace
int GetDamageForType(PowerUpType type)
{
    switch (type)
    {
    case PowerUpType::BLUE:
        return 20; // Powerful
    case PowerUpType::RED:
        return 2; // Normal
    case PowerUpType::PURPLE:
        return 1; // Weak
    case PowerUpType::M: // Missile
        return 5; // Extra powerful
    default:
        return 1; // Default/fallback for other types like H, P, B
    }
}

// Constructor for normal (non-homing) bullets
Bullet::Bullet(const glm::vec2& position, const glm::vec2& velocity, PowerUpType type, bool isEnemyBullet)
    : Util::GameObject(std::make_shared<Util::Image>(GetImagePathForBullet(type, isEnemyBullet)), 1), // zIndex 1
      m_Velocity(velocity),
      m_IsHoming(false),
      m_HomingSpeed(0.0f)
{
    m_Transform.translation = position;
    SetVisible(true); // Ensure visibility
    m_Damage = isEnemyBullet ? 1 : GetDamageForType(type);
    // Check if drawable loaded successfully (example check, your Image class might differ)
    auto imageDrawable = std::dynamic_pointer_cast<Util::Image>(m_Drawable);
}

// Constructor for homing bullets/missiles
Bullet::Bullet(const glm::vec2& position, float speed, const std::shared_ptr<Enemy>& target,
               PowerUpType visualTypeForHomingPlayerBullet)
    : Util::GameObject(std::make_shared<Util::Image>(GetImagePathForBullet(visualTypeForHomingPlayerBullet, false)), 1),
      // isEnemyBullet is false for player's homing bullets
      m_Velocity(glm::vec2(0.0f)), // Initialized properly below
      m_HomingSpeed(speed),
      m_HomingTarget(target),
      m_IsHoming(true)
{
    m_Transform.translation = position;
    SetVisible(true); // Ensure visibility
    m_Damage = GetDamageForType(visualTypeForHomingPlayerBullet);
    auto imageDrawable = std::dynamic_pointer_cast<Util::Image>(m_Drawable);

    if (auto t_ptr = m_HomingTarget.lock())
    {
        // Check if target still exists
        glm::vec2 dir = glm::normalize(t_ptr->GetTransform().translation - m_Transform.translation);
        m_Velocity = dir * m_HomingSpeed;
    }
    else
    {
        // If no target, or target is gone, define a default behavior (e.g., fly straight "up")
        // Assuming positive Y is "up" for player bullets based on strategy code (e.g., glm::vec2(0, 10.0f))
        m_Velocity = glm::vec2(0.0f, m_HomingSpeed);
    }
}

bool Bullet::CollidesWith(const std::shared_ptr<Util::GameObject>& other) const {
    glm::vec2 bulletPos = m_Transform.translation;
    glm::vec2 targetPos = other->GetTransform().translation;

    float halfW = 32.0f; // Default hitbox half-width
    float halfH = 32.0f; // Default hitbox half-height

    if (auto boss = std::dynamic_pointer_cast<Boss>(other)) {
        halfW = boss->GetHitboxWidth() / 2.0f;
        halfH = boss->GetHitboxHeight() / 2.0f;
    }
    // TODO: Consider adding similar specific hitbox logic for Enemy if its visual size varies significantly from 64x64

    return (
        bulletPos.x > targetPos.x - halfW &&
        bulletPos.x < targetPos.x + halfW &&
        bulletPos.y > targetPos.y - halfH &&
        bulletPos.y < targetPos.y + halfH
    );
}

void Bullet::Update()
{
    if (m_IsHoming)
    {
        if (auto t = m_HomingTarget.lock()) { // Target still exists
            glm::vec2 dir = glm::normalize(t->GetTransform().translation - m_Transform.translation);
            m_Velocity = dir * m_HomingSpeed;
        }
        else
        {
            // Target lost, continue in the last known direction or stop homing
            // Current behavior: continues in the last calculated velocity direction
        }
    }
    m_Transform.translation += m_Velocity;
}

[[nodiscard]] bool Bullet::InBound()
{
    // Marked [[nodiscard]] in .hpp
    // Screen boundaries (approximate, adjust to your game's world coordinates)
    const float screenTop = 400.0f;
    const float screenBottom = -400.0f;
    const float screenLeft = -450.0f; // Wider for horizontal movement
    const float screenRight = 450.0f;

    if (m_Transform.translation.y < screenBottom || m_Transform.translation.y > screenTop ||
        m_Transform.translation.x < screenLeft || m_Transform.translation.x > screenRight)
    {
        SetVisible(false); // Hide if out of bounds
        return false;
    }
    return true;
}