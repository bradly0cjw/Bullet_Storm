#include "ShootingStrategy.hpp"
#include "Util/Logger.hpp" // For LOG_INFO


// RedPowerUpStage1Strategy: Shoots two bullets side-by-side
void RedPowerUpStage1Strategy::Shoot(const glm::vec2& characterPosition, const glm::vec2& MuzzlePosition,
                                     std::vector<std::shared_ptr<Bullet>>& bullets)
{
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition + glm::vec2(-10.0f, 0.0f), glm::vec2(0, 10.0f)));
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition + glm::vec2(10.0f, 0.0f), glm::vec2(0, 10.0f)));
    LOG_INFO("RedPowerUpStage1Strategy: Fired 2 bullets.");
}

// RedPowerUpStage2Strategy: Shoots three bullets in a narrow spread
void RedPowerUpStage2Strategy::Shoot(const glm::vec2& characterPosition, const glm::vec2& MuzzlePosition,
                                     std::vector<std::shared_ptr<Bullet>>& bullets)
{
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition, glm::vec2(0, 10.0f))); // Center
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition + glm::vec2(-5.0f, 0.0f), glm::vec2(-0.5f, 10.0f)));
    // Slight left
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition + glm::vec2(5.0f, 0.0f), glm::vec2(0.5f, 10.0f)));
    // Slight right
    LOG_INFO("RedPowerUpStage2Strategy: Fired 3 bullets (narrow spread).");
}

// RedPowerUpStage3Strategy: Shoots five bullets in a wider spread
void RedPowerUpStage3Strategy::Shoot(const glm::vec2& characterPosition, const glm::vec2& MuzzlePosition,
                                     std::vector<std::shared_ptr<Bullet>>& bullets)
{
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition, glm::vec2(0, 10.0f))); // Center
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition + glm::vec2(-15.0f, 0.0f), glm::vec2(-1.5f, 10.0f)));
    // Mid left
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition + glm::vec2(15.0f, 0.0f), glm::vec2(1.5f, 10.0f)));
    // Mid right
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition + glm::vec2(-30.0f, 0.0f), glm::vec2(-2.5f, 10.0f)));
    // Far left
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition + glm::vec2(30.0f, 0.0f), glm::vec2(2.5f, 10.0f)));
    // Far right
    LOG_INFO("RedPowerUpStage3Strategy: Fired 5 bullets (wide spread).");
}

// PurplePowerUpStage1Strategy (Placeholder)
void PurplePowerUpStage1Strategy::Shoot(const glm::vec2& characterPosition, const glm::vec2& MuzzlePosition,
                                        std::vector<std::shared_ptr<Bullet>>& bullets)
{
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition, glm::vec2(0, 12.0f))); // Slightly faster bullet
    LOG_INFO("PurplePowerUpStage1Strategy: Placeholder - Fired 1 default-like bullet (faster).");
}

// PurplePowerUpStage2Strategy (Placeholder)
void PurplePowerUpStage2Strategy::Shoot(const glm::vec2& characterPosition, const glm::vec2& MuzzlePosition,
                                        std::vector<std::shared_ptr<Bullet>>& bullets)
{
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition, glm::vec2(0, 12.0f)));
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition + glm::vec2(0, -10.0f), glm::vec2(0, 12.0f)));
    // second bullet slightly delayed
    LOG_INFO("PurplePowerUpStage2Strategy: Placeholder - Fired 2 default-like bullets (faster).");
}

// PurplePowerUpStage3Strategy (Placeholder)
void PurplePowerUpStage3Strategy::Shoot(const glm::vec2& characterPosition, const glm::vec2& MuzzlePosition,
                                        std::vector<std::shared_ptr<Bullet>>& bullets)
{
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition, glm::vec2(0, 15.0f))); // even faster
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition + glm::vec2(-10.0f, 0.0f), glm::vec2(0, 15.0f)));
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition + glm::vec2(10.0f, 0.0f), glm::vec2(0, 15.0f)));
    LOG_INFO("PurplePowerUpStage3Strategy: Placeholder - Fired 3 default-like bullets (very fast).");
}

// BluePowerUpStage1Strategy (Placeholder)
void BluePowerUpStage1Strategy::Shoot(const glm::vec2& characterPosition, const glm::vec2& MuzzlePosition,
                                      std::vector<std::shared_ptr<Bullet>>& bullets)
{
    // Example: Piercing shot (gameplay logic for piercing would be in bullet collision)
    auto bullet = std::make_shared<Bullet>(MuzzlePosition, glm::vec2(0, 8.0f));
    // bullet->SetPiercing(true); // This would require Bullet class modification
    bullets.push_back(bullet);
    LOG_INFO("BluePowerUpStage1Strategy: Placeholder - Fired 1 (concept: piercing) bullet.");
}

// BluePowerUpStage2Strategy (Placeholder)
void BluePowerUpStage2Strategy::Shoot(const glm::vec2& characterPosition, const glm::vec2& MuzzlePosition,
                                      std::vector<std::shared_ptr<Bullet>>& bullets)
{
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition + glm::vec2(-5.0f, 0.0f), glm::vec2(0, 8.0f)));
    bullets.push_back(std::make_shared<Bullet>(MuzzlePosition + glm::vec2(5.0f, 0.0f), glm::vec2(0, 8.0f)));
    LOG_INFO("BluePowerUpStage2Strategy: Placeholder - Fired 2 (concept: piercing) bullets.");
}

// BluePowerUpStage3Strategy (Placeholder)
void BluePowerUpStage3Strategy::Shoot(const glm::vec2& characterPosition, const glm::vec2& MuzzlePosition,
                                      std::vector<std::shared_ptr<Bullet>>& bullets)
{
    // Example: Homing missile (gameplay logic for homing would be in bullet update)
    auto bullet = std::make_shared<Bullet>(MuzzlePosition, glm::vec2(0, 7.0f));
    // bullet->SetHoming(true); // This would require Bullet class modification
    bullets.push_back(bullet);
    LOG_INFO("BluePowerUpStage3Strategy: Placeholder - Fired 1 (concept: homing) bullet.");
}
