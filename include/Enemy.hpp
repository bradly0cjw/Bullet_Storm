#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Util/GameObject.hpp"
#include "Util/Image.hpp"
#include "Bullet.hpp"
#include <chrono>
#include <string>
#include <vector>
#include <memory> // Required for std::shared_ptr


class Bullet;
// Enum for App.cpp to decide which enemy type to spawn
enum class EnemyType
{
    STRAIGHT,
    WAVE,
    TRACK,
    ZIGZAG,
    RANDOM
};

class Enemy : public Util::GameObject {
public:
    // Constants for enemy speed scaling
    static constexpr float BASE_MOVE_SPEED = 5.0f;  // Base movement speed
    static constexpr float SPEED_LEVEL_INCREMENT = 2.0f;  // Speed increase per level

    explicit Enemy(const glm::vec2& position, const std::string& imagePath, float speed, int level = 1); // Added level parameter with default
    ~Enemy() override = default;

    virtual void Update(glm::vec2 playerPosition) = 0; // Pure virtual: subclasses must implement
    virtual void Shoot(glm::vec2 playerPosition); // Virtual: can be overridden, provides a default implementation

    std::vector<std::shared_ptr<Bullet>>& GetBullets() { return m_Bullets; }
    void RmBullets(const std::shared_ptr<Bullet>& bullet);
    [[nodiscard]] bool IsVisible() const { return m_Visible; } // Inherited from Util::GameObject
    [[nodiscard]] bool IsOutOfScreen() const;
    bool CanShoot();
    void TakeDamage(int damage);
    [[nodiscard]] bool IsAlive() const;
    [[nodiscard]] int GetLevel() const { return m_Level; }


    [[nodiscard]] glm::vec2 GetPosition() const { return m_Transform.translation; } // Get position of the enemy


    // Using Util::GameObject::GetPosition(), no need to override typically unless custom logic.
    // [[nodiscard]] const glm::vec2 &GetPosition() const override { return m_Transform.translation; }

protected:
    float m_Speed;
    int m_HitPoints;
    int m_Level; // Added level member
    std::vector<std::shared_ptr<Bullet>> m_Bullets;
    std::chrono::steady_clock::time_point m_LastShootTime;
    float m_ShootIntervalSeconds; // Shoot interval in seconds

    // Helper methods for shooting, can be overridden by subclasses for custom bullet behavior
    [[nodiscard]] virtual glm::vec2 GetBulletStartPosition() const;
    [[nodiscard]] virtual glm::vec2 GetBulletVelocity(glm::vec2 playerPosition) const; // playerPosition for homing etc.
};

// Derived Enemy Types

class StraightEnemy : public Enemy
{
public:
    explicit StraightEnemy(const glm::vec2& position, int level = 1); // Added level parameter
    void Update(glm::vec2 playerPosition) override;
    // Optionally override Shoot for a unique pattern
};

class WaveEnemy : public Enemy
{
public:
    explicit WaveEnemy(const glm::vec2& position, int level = 1); // Added level parameter
    void Update(glm::vec2 playerPosition) override;

private:
    float m_WaveAngle;
};

class TrackEnemy : public Enemy
{
public:
    explicit TrackEnemy(const glm::vec2& position, int level = 1); // Added level parameter
    void Update(glm::vec2 playerPosition) override;
    // Example: Override Shoot for aiming at the player
    // void Shoot(glm::vec2 playerPosition) override; 
};

class ZigzagEnemy : public Enemy
{
public:
    explicit ZigzagEnemy(const glm::vec2& position, int level = 1);
    void Update(glm::vec2 playerPosition) override;

private:
    int m_ZigzagDirection; // To make zigzag more deterministic than pure random
    int m_ZigzagCounter;
};

class RandomEnemy : public Enemy
{
public:
    explicit RandomEnemy(const glm::vec2& position, int level = 1);
    void Update(glm::vec2 playerPosition) override;
};

#endif //ENEMY_HPP

