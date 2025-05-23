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
    Enemy(const glm::vec2& position, const std::string& imagePath, float speed);
    virtual ~Enemy() = default;

    virtual void Update(glm::vec2 playerPosition) = 0; // Pure virtual: subclasses must implement
    virtual void Shoot(glm::vec2 playerPosition); // Virtual: can be overridden, provides a default implementation

    std::vector<std::shared_ptr<Bullet>>& GetBullets() { return m_Bullets; }
    void RmBullets(const std::shared_ptr<Bullet>& bullet);
    bool IsVisible() const { return m_Visible; } // Inherited from Util::GameObject
    bool IsOutOfScreen() const;
    bool CanShoot();


    glm::vec2 GetPosition() const { return m_Transform.translation; } // Get position of the enemy


    // Using Util::GameObject::GetPosition(), no need to override typically unless custom logic.
    // [[nodiscard]] const glm::vec2 &GetPosition() const override { return m_Transform.translation; }

protected:
    float m_Speed;
    std::vector<std::shared_ptr<Bullet>> m_Bullets;
    std::chrono::steady_clock::time_point m_LastShootTime;
    float m_ShootIntervalSeconds; // Shoot interval in seconds

    // Helper methods for shooting, can be overridden by subclasses for custom bullet behavior
    virtual glm::vec2 GetBulletStartPosition() const;
    virtual glm::vec2 GetBulletVelocity(glm::vec2 playerPosition) const; // playerPosition for homing etc.
};

// Derived Enemy Types

class StraightEnemy : public Enemy
{
public:
    StraightEnemy(const glm::vec2& position);
    void Update(glm::vec2 playerPosition) override;
    // Optionally override Shoot for a unique pattern
};

class WaveEnemy : public Enemy
{
public:
    WaveEnemy(const glm::vec2& position);
    void Update(glm::vec2 playerPosition) override;

private:
    float m_WaveAngle;
};

class TrackEnemy : public Enemy
{
public:
    TrackEnemy(const glm::vec2& position);
    void Update(glm::vec2 playerPosition) override;
    // Example: Override Shoot for aiming at the player
    // void Shoot(glm::vec2 playerPosition) override; 
};

class ZigzagEnemy : public Enemy
{
public:
    ZigzagEnemy(const glm::vec2& position);
    void Update(glm::vec2 playerPosition) override;

private:
    int m_ZigzagDirection; // To make zigzag more deterministic than pure random
    int m_ZigzagCounter;
};

class RandomEnemy : public Enemy
{
public:
    RandomEnemy(const glm::vec2& position);
    void Update(glm::vec2 playerPosition) override;
};

#endif //ENEMY_HPP