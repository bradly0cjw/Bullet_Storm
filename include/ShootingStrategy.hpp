#ifndef SHOOTING_STRATEGY_HPP
#define SHOOTING_STRATEGY_HPP

#include <vector>
#include <memory>
#include "Bullet.hpp"
#include <glm/glm.hpp>

// Forward declaration to avoid circular dependency
// Character.hpp will include ShootingStrategy.hpp, so Character definition will be available in .cpp
// class Character;

class ShootingStrategy
{
public:
    virtual ~ShootingStrategy() = default;
    // MuzzlePosition is where the bullets originate from the character
    // Bullets vector is the character's list of active bullets to add to
    virtual void Shoot(const glm::vec2& characterPosition, const glm::vec2& MuzzlePosition,
                       std::vector<std::shared_ptr<Bullet>>& bullets) = 0;
};


// Red PowerUp Strategies
class RedPowerUpStage1Strategy : public ShootingStrategy
{
public:
    void Shoot(const glm::vec2& characterPosition, const glm::vec2& MuzzlePosition,
               std::vector<std::shared_ptr<Bullet>>& bullets) override;
};

class RedPowerUpStage2Strategy : public ShootingStrategy
{
public:
    void Shoot(const glm::vec2& characterPosition, const glm::vec2& MuzzlePosition,
               std::vector<std::shared_ptr<Bullet>>& bullets) override;
};

class RedPowerUpStage3Strategy : public ShootingStrategy
{
public:
    void Shoot(const glm::vec2& characterPosition, const glm::vec2& MuzzlePosition,
               std::vector<std::shared_ptr<Bullet>>& bullets) override;
};

// Purple PowerUp Strategies (Placeholders)
class PurplePowerUpStage1Strategy : public ShootingStrategy
{
public:
    void Shoot(const glm::vec2& characterPosition, const glm::vec2& MuzzlePosition,
               std::vector<std::shared_ptr<Bullet>>& bullets) override;
};

class PurplePowerUpStage2Strategy : public ShootingStrategy
{
public:
    void Shoot(const glm::vec2& characterPosition, const glm::vec2& MuzzlePosition,
               std::vector<std::shared_ptr<Bullet>>& bullets) override;
};

class PurplePowerUpStage3Strategy : public ShootingStrategy
{
public:
    void Shoot(const glm::vec2& characterPosition, const glm::vec2& MuzzlePosition,
               std::vector<std::shared_ptr<Bullet>>& bullets) override;
};

// Blue PowerUp Strategies (Placeholders)
class BluePowerUpStage1Strategy : public ShootingStrategy
{
public:
    void Shoot(const glm::vec2& characterPosition, const glm::vec2& MuzzlePosition,
               std::vector<std::shared_ptr<Bullet>>& bullets) override;
};

class BluePowerUpStage2Strategy : public ShootingStrategy
{
public:
    void Shoot(const glm::vec2& characterPosition, const glm::vec2& MuzzlePosition,
               std::vector<std::shared_ptr<Bullet>>& bullets) override;
};

class BluePowerUpStage3Strategy : public ShootingStrategy
{
public:
    void Shoot(const glm::vec2& characterPosition, const glm::vec2& MuzzlePosition,
               std::vector<std::shared_ptr<Bullet>>& bullets) override;
};

#endif // SHOOTING_STRATEGY_HPP
