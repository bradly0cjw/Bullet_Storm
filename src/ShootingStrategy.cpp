#include "ShootingStrategy.hpp"
#include "Character.hpp" // Required for Character class definition
#include "Enemy.hpp"     // Required for Enemy class definition and std::vector<std::shared_ptr<Enemy>>
#include "Bullet.hpp"    // For std::make_shared<Bullet>
#include "Util/Logger.hpp" // For LOG_INFO


// RedPowerUpStage1Strategy: Shoots two bullets side-by-side
void RedPowerUpStage1Strategy::Shoot(const glm::vec2& characterPosition, const glm::vec2& MuzzlePosition,
                                     std::vector<std::shared_ptr<Bullet>>& bullets, PowerUpType type,
                                     Character* character, const std::vector<std::shared_ptr<Enemy>>& enemies)
{
    (void)character; // Unused
    (void)enemies;   // Unused
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition + glm::vec2(-10.0f, 0.0f), glm::vec2(0, 10.0f), type));
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition + glm::vec2(10.0f, 0.0f), glm::vec2(0, 10.0f), type));
    LOG_INFO("RedPowerUpStage1Strategy: Fired 2 bullets.");
}

// RedPowerUpStage2Strategy: Shoots more bullets
void RedPowerUpStage2Strategy::Shoot(const glm::vec2& characterPosition, const glm::vec2& MuzzlePosition,
                                     std::vector<std::shared_ptr<Bullet>>& bullets, PowerUpType type,
                                     Character* character, const std::vector<std::shared_ptr<Enemy>>& enemies)
{
    (void)character; // Unused
    (void)enemies;   // Unused
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition + glm::vec2(-10.0f, 0.0f), glm::vec2(0, 10.0f), type));
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition + glm::vec2(10.0f, 0.0f), glm::vec2(0, 10.0f), type));
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition + glm::vec2(-5.0f, 0.0f), glm::vec2(-0.5f, 10.0f), type));
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition + glm::vec2(-7.0f, 0.0f), glm::vec2(-0.5f, 10.0f), type));
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition + glm::vec2(5.0f, 0.0f), glm::vec2(0.5f, 10.0f), type));
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition + glm::vec2(7.0f, 0.0f), glm::vec2(0.5f, 10.0f), type));
    LOG_INFO("RedPowerUpStage2Strategy: Fired 6 bullets (spread).");
}

// RedPowerUpStage3Strategy: Shoots even more bullets
void RedPowerUpStage3Strategy::Shoot(const glm::vec2& characterPosition, const glm::vec2& MuzzlePosition,
                                     std::vector<std::shared_ptr<Bullet>>& bullets, PowerUpType type,
                                     Character* character, const std::vector<std::shared_ptr<Enemy>>& enemies)
{
    (void)character; // Unused
    (void)enemies;   // Unused
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition + glm::vec2(-10.0f, 0.0f), glm::vec2(0, 10.0f), type));
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition + glm::vec2(10.0f, 0.0f), glm::vec2(0, 10.0f), type));
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition + glm::vec2(-15.0f, 0.0f), glm::vec2(-1.5f, 10.0f), type));
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition + glm::vec2(-5.0f, 0.0f), glm::vec2(-1.5f, 10.0f), type));
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition + glm::vec2(15.0f, 0.0f), glm::vec2(1.5f, 10.0f), type));
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition + glm::vec2(5.0f, 0.0f), glm::vec2(1.5f, 10.0f), type));
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition + glm::vec2(-30.0f, 0.0f), glm::vec2(-2.5f, 10.0f), type));
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition + glm::vec2(-20.0f, 0.0f), glm::vec2(-2.5f, 10.0f), type));
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition + glm::vec2(30.0f, 0.0f), glm::vec2(2.5f, 10.0f), type));
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition + glm::vec2(20.0f, 0.0f), glm::vec2(2.5f, 10.0f), type));
    LOG_INFO("RedPowerUpStage3Strategy: Fired 10 bullets (wide spread).");
}

void PurplePowerUpStage1Strategy::Shoot(const glm::vec2& characterPosition, const glm::vec2& MuzzlePosition,
                                        std::vector<std::shared_ptr<Bullet>>& bullets, PowerUpType type,
                                        Character* character, const std::vector<std::shared_ptr<Enemy>>& enemies)
{
    std::shared_ptr<Enemy> targetEnemy = nullptr;
    if (character) {
        targetEnemy = character->FindNearestVisibleEnemy(MuzzlePosition, enemies);
    }

    if (targetEnemy) {
        // Fire a homing bullet using the current power-up's visual type (type should be PURPLE)
        bullets.push_back(std::make_shared<Bullet>(MuzzlePosition, 12.0f, targetEnemy, type));
    } else {
        // Fallback: shoot a normal bullet straight if no enemy or character is null
        bullets.push_back(std::make_shared<Bullet>(MuzzlePosition, glm::vec2(0, 12.0f), type, false));
    }
    LOG_INFO("PurplePowerUpStage1Strategy: Fired 1 auto-targeting bullet with visuals for type {}.", static_cast<int>(type));
}

// PurplePowerUpStage2Strategy (Auto-lock)
void PurplePowerUpStage2Strategy::Shoot(const glm::vec2& characterPosition, const glm::vec2& MuzzlePosition,
                                        std::vector<std::shared_ptr<Bullet>>& bullets, PowerUpType type,
                                        Character* character, const std::vector<std::shared_ptr<Enemy>>& enemies)
{
    std::shared_ptr<Enemy> targetEnemy = nullptr;
    if (character) {
        targetEnemy = character->FindNearestVisibleEnemy(MuzzlePosition, enemies);
    }

    if (targetEnemy) {
        bullets.push_back(std::make_shared<Bullet>(MuzzlePosition, 12.0f, targetEnemy, type));
        bullets.push_back(std::make_shared<Bullet>(MuzzlePosition + glm::vec2(0.0f, -10.0f), 12.0f, targetEnemy, type)); // Staggered or offset
    } else {
        bullets.push_back(std::make_shared<Bullet>(MuzzlePosition, glm::vec2(0, 12.0f), type, false));
        bullets.push_back(std::make_shared<Bullet>(MuzzlePosition + glm::vec2(0.0f, -10.0f), glm::vec2(0, 12.0f), type, false));
    }
    LOG_INFO("PurplePowerUpStage2Strategy: Fired 2 auto-targeting bullets with visuals for type {}.", static_cast<int>(type));
}

// PurplePowerUpStage3Strategy (Auto-lock)
void PurplePowerUpStage3Strategy::Shoot(const glm::vec2& characterPosition, const glm::vec2& MuzzlePosition,
                                        std::vector<std::shared_ptr<Bullet>>& bullets, PowerUpType type,
                                        Character* character, const std::vector<std::shared_ptr<Enemy>>& enemies)
{
    std::shared_ptr<Enemy> targetEnemy = nullptr;
    if (character) {
        targetEnemy = character->FindNearestVisibleEnemy(MuzzlePosition, enemies);
    }

    if (targetEnemy) {
        bullets.push_back(std::make_shared<Bullet>(MuzzlePosition, 15.0f, targetEnemy, type));
        bullets.push_back(std::make_shared<Bullet>(MuzzlePosition + glm::vec2(-10.0f, 0.0f), 15.0f, targetEnemy, type));
        bullets.push_back(std::make_shared<Bullet>(MuzzlePosition + glm::vec2(10.0f, 0.0f), 15.0f, targetEnemy, type));
    } else {
        bullets.push_back(std::make_shared<Bullet>(MuzzlePosition, glm::vec2(0, 15.0f), type, false));
        bullets.push_back(std::make_shared<Bullet>(MuzzlePosition + glm::vec2(-10.0f, 0.0f), glm::vec2(0, 15.0f), type, false));
        bullets.push_back(std::make_shared<Bullet>(MuzzlePosition + glm::vec2(10.0f, 0.0f), glm::vec2(0, 15.0f), type, false));
    }
    LOG_INFO("PurplePowerUpStage3Strategy: Fired 3 auto-targeting bullets with visuals for type {}.", static_cast<int>(type));
}

// BluePowerUpStage1Strategy
void BluePowerUpStage1Strategy::Shoot(const glm::vec2& characterPosition, const glm::vec2& MuzzlePosition,
                                      std::vector<std::shared_ptr<Bullet>>& bullets, PowerUpType type,
                                      Character* character, const std::vector<std::shared_ptr<Enemy>>& enemies)
{
    (void)character; // Unused
    (void)enemies;   // Unused
    const float LASER_SPEED = 25.0f;
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition, glm::vec2(0, LASER_SPEED), type));
    LOG_INFO("BluePowerUpStage1Strategy: Fired 1 laser beam.");
}

// BluePowerUpStage2Strategy
void BluePowerUpStage2Strategy::Shoot(const glm::vec2& characterPosition, const glm::vec2& MuzzlePosition,
                                      std::vector<std::shared_ptr<Bullet>>& bullets, PowerUpType type,
                                      Character* character, const std::vector<std::shared_ptr<Enemy>>& enemies)
{
    (void)character; // Unused
    (void)enemies;   // Unused
    const float LASER_SPEED = 25.0f;
    const float SPREAD_OFFSET = 10.0f;

    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition, glm::vec2(0, LASER_SPEED), type));
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition + glm::vec2(-SPREAD_OFFSET, 0.0f),
                                               glm::vec2(0, LASER_SPEED), type));
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition + glm::vec2(SPREAD_OFFSET, 0.0f), glm::vec2(0, LASER_SPEED), type));
    LOG_INFO("BluePowerUpStage2Strategy: Fired 3 parallel laser beams.");
}

// BluePowerUpStage3Strategy
void BluePowerUpStage3Strategy::Shoot(const glm::vec2& characterPosition, const glm::vec2& MuzzlePosition,
                                      std::vector<std::shared_ptr<Bullet>>& bullets, PowerUpType type,
                                      Character* character, const std::vector<std::shared_ptr<Enemy>>& enemies)
{
    (void)character; // Unused
    (void)enemies;   // Unused
    const float LASER_SPEED = 25.0f;
    const float INNER_SPREAD_OFFSET = 15.0f;
    const float OUTER_SPREAD_OFFSET = 30.0f;

    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition, glm::vec2(0, LASER_SPEED), type));
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition + glm::vec2(-INNER_SPREAD_OFFSET, 0.0f),
                                               glm::vec2(0, LASER_SPEED), type));
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition + glm::vec2(INNER_SPREAD_OFFSET, 0.0f),
                                               glm::vec2(0, LASER_SPEED), type));
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition + glm::vec2(-OUTER_SPREAD_OFFSET, 0.0f),
                                               glm::vec2(0, LASER_SPEED), type));
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition + glm::vec2(OUTER_SPREAD_OFFSET, 0.0f), glm::vec2(0, LASER_SPEED), type));
    LOG_INFO("BluePowerUpStage3Strategy: Fired 5 parallel laser beams (wide spread).");
}