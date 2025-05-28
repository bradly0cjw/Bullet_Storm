#include "ShootingStrategy.hpp"
#include "Util/Logger.hpp" // For LOG_INFO


// RedPowerUpStage1Strategy: Shoots two bullets side-by-side
void RedPowerUpStage1Strategy::Shoot(const glm::vec2& characterPosition, const glm::vec2& MuzzlePosition,
                                     std::vector<std::shared_ptr<Bullet>>& bullets, PowerUpType type)
{
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition + glm::vec2(-10.0f, 0.0f), glm::vec2(0, 10.0f), type));
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition + glm::vec2(10.0f, 0.0f), glm::vec2(0, 10.0f), type));
    LOG_INFO("RedPowerUpStage1Strategy: Fired 2 bullets.");
}

// RedPowerUpStage2Strategy: Shoots three bullets in a narrow spread
void RedPowerUpStage2Strategy::Shoot(const glm::vec2& characterPosition, const glm::vec2& MuzzlePosition,
                                     std::vector<std::shared_ptr<Bullet>>& bullets, PowerUpType type)
{
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition + glm::vec2(-10.0f, 0.0f), glm::vec2(0, 10.0f), type));
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition + glm::vec2(10.0f, 0.0f), glm::vec2(0, 10.0f), type));
    // Center
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition + glm::vec2(-5.0f, 0.0f), glm::vec2(-0.5f, 10.0f), type));
    // Slight left 1
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition + glm::vec2(-7.0f, 0.0f), glm::vec2(-0.5f, 10.0f), type));
    // Slight left 2
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition + glm::vec2(5.0f, 0.0f), glm::vec2(0.5f, 10.0f), type));
    // Slight right 1
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition + glm::vec2(7.0f, 0.0f), glm::vec2(0.5f, 10.0f), type));
    // Slight right 2
    LOG_INFO("RedPowerUpStage2Strategy: Fired 3 bullets (narrow spread).");
}

// RedPowerUpStage3Strategy: Shoots five bullets in a wider spread
void RedPowerUpStage3Strategy::Shoot(const glm::vec2& characterPosition, const glm::vec2& MuzzlePosition,
                                     std::vector<std::shared_ptr<Bullet>>& bullets, PowerUpType type)
{
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition + glm::vec2(-10.0f, 0.0f), glm::vec2(0, 10.0f), type));
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition + glm::vec2(10.0f, 0.0f), glm::vec2(0, 10.0f), type));// Center
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition + glm::vec2(-15.0f, 0.0f), glm::vec2(-1.5f, 10.0f),type));    // Mid left 1
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition + glm::vec2(-5.0f, 0.0f), glm::vec2(-1.5f, 10.0f), type)); // Mid left 2
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition + glm::vec2(15.0f, 0.0f), glm::vec2(1.5f, 10.0f), type));    // Mid right 1
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition + glm::vec2(5.0f, 0.0f), glm::vec2(1.5f, 10.0f), type)); // Mid right 2
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition + glm::vec2(-30.0f, 0.0f), glm::vec2(-2.5f, 10.0f),type));    // Far left 1
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition + glm::vec2(-20.0f, 0.0f), glm::vec2(-2.5f, 10.0f), type)); // Far left 2
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition + glm::vec2(30.0f, 0.0f), glm::vec2(2.5f, 10.0f), type));    // Far right
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition + glm::vec2(20.0f, 0.0f), glm::vec2(2.5f, 10.0f), type)); // Far right 2
    LOG_INFO("RedPowerUpStage3Strategy: Fired 5 bullets (wide spread).");
}

// PurplePowerUpStage1Strategy (Placeholder)
void PurplePowerUpStage1Strategy::Shoot(const glm::vec2& characterPosition, const glm::vec2& MuzzlePosition,
                                        std::vector<std::shared_ptr<Bullet>>& bullets, PowerUpType type)
{
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition, glm::vec2(0, 12.0f), type)); // Slightly faster bullet
    LOG_INFO("PurplePowerUpStage1Strategy: Placeholder - Fired 1 default-like bullet (faster).");
}

// PurplePowerUpStage2Strategy (Placeholder)
void PurplePowerUpStage2Strategy::Shoot(const glm::vec2& characterPosition, const glm::vec2& MuzzlePosition,
                                        std::vector<std::shared_ptr<Bullet>>& bullets, PowerUpType type)
{
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition, glm::vec2(0, 12.0f), type));
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition + glm::vec2(0, -10.0f), glm::vec2(0, 12.0f), type));
    // second bullet slightly delayed
    LOG_INFO("PurplePowerUpStage2Strategy: Placeholder - Fired 2 default-like bullets (faster).");
}

// PurplePowerUpStage3Strategy (Placeholder)
void PurplePowerUpStage3Strategy::Shoot(const glm::vec2& characterPosition, const glm::vec2& MuzzlePosition,
                                        std::vector<std::shared_ptr<Bullet>>& bullets, PowerUpType type)
{
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition, glm::vec2(0, 15.0f), type)); // even faster
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition + glm::vec2(-10.0f, 0.0f), glm::vec2(0, 15.0f), type));
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition + glm::vec2(10.0f, 0.0f), glm::vec2(0, 15.0f), type));
    LOG_INFO("PurplePowerUpStage3Strategy: Placeholder - Fired 3 default-like bullets (very fast).");
}

// BluePowerUpStage1Strategy (Placeholder)
void BluePowerUpStage1Strategy::Shoot(const glm::vec2& characterPosition, const glm::vec2& MuzzlePosition,
                                      std::vector<std::shared_ptr<Bullet>>& bullets, PowerUpType type)
{
    const float LASER_SPEED = 25.0f;
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition, glm::vec2(0, LASER_SPEED), type));
    LOG_INFO("BluePowerUpStage1Strategy: Fired 1 laser beam.");
}

// BluePowerUpStage2Strategy (Placeholder)
void BluePowerUpStage2Strategy::Shoot(const glm::vec2& characterPosition, const glm::vec2& MuzzlePosition,
                                      std::vector<std::shared_ptr<Bullet>>& bullets, PowerUpType type)
{
    const float LASER_SPEED = 25.0f;
    const float SPREAD_OFFSET = 10.0f; // Width for the side beams

    // Center beam
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition, glm::vec2(0, LASER_SPEED), type));
    // Side beams
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition + glm::vec2(-SPREAD_OFFSET, 0.0f), glm::vec2(0, LASER_SPEED), type));
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition + glm::vec2(SPREAD_OFFSET, 0.0f), glm::vec2(0, LASER_SPEED), type));
    LOG_INFO("BluePowerUpStage2Strategy: Fired 3 parallel laser beams.");
}

// BluePowerUpStage3Strategy (Placeholder)
void BluePowerUpStage3Strategy::Shoot(const glm::vec2& characterPosition, const glm::vec2& MuzzlePosition,
                                      std::vector<std::shared_ptr<Bullet>>& bullets, PowerUpType type)
{
    const float LASER_SPEED = 25.0f;
    const float INNER_SPREAD_OFFSET = 15.0f;
    const float OUTER_SPREAD_OFFSET = 30.0f;

    // Center beam
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition, glm::vec2(0, LASER_SPEED), type));
    // Inner side beams
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition + glm::vec2(-INNER_SPREAD_OFFSET, 0.0f), glm::vec2(0, LASER_SPEED), type));
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition + glm::vec2(INNER_SPREAD_OFFSET, 0.0f), glm::vec2(0, LASER_SPEED), type));
    // Outer side beams
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition + glm::vec2(-OUTER_SPREAD_OFFSET, 0.0f), glm::vec2(0, LASER_SPEED), type));
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition + glm::vec2(OUTER_SPREAD_OFFSET, 0.0f), glm::vec2(0, LASER_SPEED), type));
    LOG_INFO("BluePowerUpStage3Strategy: Fired 5 parallel laser beams (wide spread).");
}
