#ifndef SHOOTING_STRATEGY_HPP
#define SHOOTING_STRATEGY_HPP

#include <vector>
#include <memory>
#include "Bullet.hpp" // PowerUpType is defined in Bullet.hpp or PowerUp.hpp included by Bullet.hpp
#include <glm/glm.hpp>

// Forward declarations
class Character;
class Enemy;

class ShootingStrategy
{
public:
    virtual ~ShootingStrategy() = default;

    virtual void Shoot(const glm::vec2& characterPosition, const glm::vec2& MuzzlePosition,
                       std::vector<std::shared_ptr<Bullet>>& bullets, PowerUpType type,
                       Character* character, const std::vector<std::shared_ptr<Enemy>>& enemies) = 0;
};


// Red PowerUp Strategies
class RedPowerUpStage1Strategy : public ShootingStrategy
{
public:
    void Shoot(const glm::vec2& characterPosition, const glm::vec2& MuzzlePosition,
               std::vector<std::shared_ptr<Bullet>>& bullets, PowerUpType type,
               Character* character, const std::vector<std::shared_ptr<Enemy>>& enemies) override;
};

class RedPowerUpStage2Strategy : public ShootingStrategy
{
public:
    void Shoot(const glm::vec2& characterPosition, const glm::vec2& MuzzlePosition,
               std::vector<std::shared_ptr<Bullet>>& bullets, PowerUpType type,
               Character* character, const std::vector<std::shared_ptr<Enemy>>& enemies) override;
};

class RedPowerUpStage3Strategy : public ShootingStrategy
{
public:
    void Shoot(const glm::vec2& characterPosition, const glm::vec2& MuzzlePosition,
               std::vector<std::shared_ptr<Bullet>>& bullets, PowerUpType type,
               Character* character, const std::vector<std::shared_ptr<Enemy>>& enemies) override;
};

// Purple PowerUp Strategies
class PurplePowerUpStage1Strategy : public ShootingStrategy
{
public:
    void Shoot(const glm::vec2& characterPosition, const glm::vec2& MuzzlePosition,
               std::vector<std::shared_ptr<Bullet>>& bullets, PowerUpType type,
               Character* character, const std::vector<std::shared_ptr<Enemy>>& enemies) override;
};

class PurplePowerUpStage2Strategy : public ShootingStrategy
{
public:
    void Shoot(const glm::vec2& characterPosition, const glm::vec2& MuzzlePosition,
               std::vector<std::shared_ptr<Bullet>>& bullets, PowerUpType type,
               Character* character, const std::vector<std::shared_ptr<Enemy>>& enemies) override;
};

class PurplePowerUpStage3Strategy : public ShootingStrategy
{
public:
    void Shoot(const glm::vec2& characterPosition, const glm::vec2& MuzzlePosition,
               std::vector<std::shared_ptr<Bullet>>& bullets, PowerUpType type,
               Character* character, const std::vector<std::shared_ptr<Enemy>>& enemies) override;
};

// Blue PowerUp Strategies
class BluePowerUpStage1Strategy : public ShootingStrategy
{
public:
    void Shoot(const glm::vec2& characterPosition, const glm::vec2& MuzzlePosition,
               std::vector<std::shared_ptr<Bullet>>& bullets, PowerUpType type,
               Character* character, const std::vector<std::shared_ptr<Enemy>>& enemies) override;
};

class BluePowerUpStage2Strategy : public ShootingStrategy
{
public:
    void Shoot(const glm::vec2& characterPosition, const glm::vec2& MuzzlePosition,
               std::vector<std::shared_ptr<Bullet>>& bullets, PowerUpType type,
               Character* character, const std::vector<std::shared_ptr<Enemy>>& enemies) override;
};

class BluePowerUpStage3Strategy : public ShootingStrategy
{
public:
    void Shoot(const glm::vec2& characterPosition, const glm::vec2& MuzzlePosition,
               std::vector<std::shared_ptr<Bullet>>& bullets, PowerUpType type,
               Character* character, const std::vector<std::shared_ptr<Enemy>>& enemies) override;
};

# endif // SHOOTING_STRATEGY_HPP