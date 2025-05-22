#include "Character.hpp"
#include "Util/Image.hpp"
#include <iostream>
#include "Util/Logger.hpp"


Character::Character(const std::string& ImagePath)
{
    // Initialize power-up state
    LOG_INFO("Character created with image path: {}", ImagePath);
    SetImage(ImagePath);
    ResetPosition();
    m_CurrentPowerUpType = PowerUpType::RED; // Default, doesn't matter if m_PowerUpLevel is 0
    m_ShootingStrategy = std::make_unique<RedPowerUpStage1Strategy>(); // Start with default
}

void Character::SetImage(const std::string &ImagePath) {
    m_ImagePath = ImagePath;

    m_Drawable = std::make_shared<Util::Image>(m_ImagePath);
}

void Character::Shoot()
{
    //LOG_INFO("Shoot function called!"); // Logged by strategy now
    glm::vec2 playerPos = GetPosition();
    glm::vec2 MuzzlePosition = playerPos + glm::vec2(0.0f, 50.0f); // Muzzle offset from player center

    if (m_ShootingStrategy)
    {
        m_ShootingStrategy->Shoot(playerPos, MuzzlePosition, m_Bullets);
        // Ensure new bullets are visible (Bullet constructor should handle this)
        // for(const auto& bullet : m_Bullets) { // This might be inefficient if m_Bullets is large
        //     if(bullet && !bullet->GetVisibility()) { // Assuming GetVisibility exists
        //         // Bullet constructor should set visibility. Or strategy should.
        //     }
        // }
    }
    else
    {
        LOG_ERROR("No shooting strategy set for Character!");
    }
}


bool Character::IfCollides(const std::shared_ptr<Util::GameObject> &other) const {
    glm::vec2 a = m_Transform.translation;
    glm::vec2 b = other->GetTransform().translation;

    float distance = glm::distance(a, b);
    return distance < 32.0f; // 半徑碰撞，32 可依照子彈/敵機圖大小調整
}

void Character::UseSkill() {
    if (m_skillCharges <= 0) {
        LOG_INFO("No skill charges!");
        return;
    }
    // 扣一次技能
    DecSkillCharge();
    LOG_INFO("UseSkill: remaining charges = {}", GetSkillCharges());
}

void Character::Update()
{
    // 更新所有子彈
    LOG_INFO("PowerUP Level: {}", m_PowerUpLevel);
    for (auto &bullet: m_Bullets) {
        if (!bullet->InBound()) {
            //TODO: Migrate delete logic to here
//            RmBullets(bullet);
        } else {
            bullet->Update();
        }
        // remove if out of bound
    }
}

void Character::RmBullets(const std::shared_ptr<Bullet>& bullet_to_remove)
{
    auto it = std::find(m_Bullets.begin(), m_Bullets.end(), bullet_to_remove);
    if (it != m_Bullets.end())
    {
        (*it)->SetVisible(false); // Mark for removal or hide
        m_Bullets.erase(it);
    }
}

void Character::ApplyPowerUp(PowerUpType power_up_type)
{
    // if (m_CurrentPowerUpType == power_up_type) {
    //     // Same type, upgrade level
    //     if (m_PowerUpLevel < 3) {
    //         m_PowerUpLevel++;
    //     }
    // } else {
    //     // Different type, switch to it at level 1
    //     m_CurrentPowerUpType = power_up_type;
    //     m_PowerUpLevel = 1;
    // }
    if (m_PowerUpLevel < 3)
    {
        m_PowerUpLevel++;
    }
    m_CurrentPowerUpType = power_up_type;
    LOG_INFO("PowerUp Applied: Type {}, Level {}", static_cast<int>(m_CurrentPowerUpType), m_PowerUpLevel);
    UpdateShootingStrategy();
}


void Character::UpdateShootingStrategy()
{
    if (m_PowerUpLevel == 0)
    {
        m_ShootingStrategy = std::make_unique<RedPowerUpStage1Strategy>();
        return;
    }

    switch (m_CurrentPowerUpType)
    {
    case PowerUpType::RED:
        if (m_PowerUpLevel == 1) m_ShootingStrategy = std::make_unique<RedPowerUpStage1Strategy>();
        else if (m_PowerUpLevel == 2) m_ShootingStrategy = std::make_unique<RedPowerUpStage2Strategy>();
        else if (m_PowerUpLevel == 3) m_ShootingStrategy = std::make_unique<RedPowerUpStage3Strategy>();
        else m_ShootingStrategy = std::make_unique<RedPowerUpStage1Strategy>(); // Fallback
        break;
    case PowerUpType::PURPLE:
        if (m_PowerUpLevel == 1) m_ShootingStrategy = std::make_unique<PurplePowerUpStage1Strategy>();
        else if (m_PowerUpLevel == 2) m_ShootingStrategy = std::make_unique<PurplePowerUpStage2Strategy>();
        else if (m_PowerUpLevel == 3) m_ShootingStrategy = std::make_unique<PurplePowerUpStage3Strategy>();
        else m_ShootingStrategy = std::make_unique<RedPowerUpStage1Strategy>(); // Fallback
        break;
    case PowerUpType::BLUE:
        if (m_PowerUpLevel == 1) m_ShootingStrategy = std::make_unique<BluePowerUpStage1Strategy>();
        else if (m_PowerUpLevel == 2) m_ShootingStrategy = std::make_unique<BluePowerUpStage2Strategy>();
        else if (m_PowerUpLevel == 3) m_ShootingStrategy = std::make_unique<BluePowerUpStage3Strategy>();
        else m_ShootingStrategy = std::make_unique<RedPowerUpStage1Strategy>(); // Fallback
        break;
    default:
        m_ShootingStrategy = std::make_unique<RedPowerUpStage1Strategy>();
        break;
    }
    LOG_INFO("Shooting strategy updated.");
}

void Character::ResetPowerUp()
{
    m_CurrentPowerUpType = PowerUpType::RED; // Reset to default
    m_PowerUpLevel = 1;
    UpdateShootingStrategy();
}

void Character::ApplySpecialPowerUp(PowerUpType type) {
    switch(type) {
        case PowerUpType::H:
            // 吃到 H 回 1 點血
                modifyHealth(1);
        LOG_INFO("PowerUp H: Health increased to {}", GetHealth());
        break;

        case PowerUpType::M:
            // 例如增加一次技能（假設 m_skill.first 為技能數量）
                isMissile = true;
        LOG_INFO("PowerUp M: Skill count is now {}");
        break;

        case PowerUpType::P:
            // 你可以依需求加上 P 道具效果
                LOG_INFO("PowerUp P collected");
        break;

        case PowerUpType::B:
            IncSkillCharge();
        LOG_INFO("PowerUp B: Skill charges = {}", GetSkillCharges());
        break;

        default:
            break;
    }
}
void Character::LaunchMissiles(
    const std::vector<std::shared_ptr<Enemy>>& enemies,
    Util::Renderer* renderer
) {
    if (!isMissile) {
        LOG_INFO("No missiles available!");
        return;
    }
    // 一次性消耗這個 M 道具
    LOG_INFO("Missiles launched, isMissile reset to false");

    glm::vec2 center = m_Transform.translation;
    glm::vec2 offset{25.0f, 0.0f};
    const float speed = 5.0f;

    // 單一 spawn lambda：不論有無目標都呼叫 homing ctor
    auto spawnMissile = [&](glm::vec2 start) {
        // 找到最近的敵人（可能找不到，bestTgt 會是 nullptr）
        std::shared_ptr<Enemy> bestTgt;
        float bestDist = std::numeric_limits<float>::infinity();
        for (auto& e : enemies) {
            if (!e->IsVisible()) continue;
            float d = glm::length(e->GetTransform().translation - start);
            if (d < bestDist) {
                bestDist = d;
                bestTgt = e;
            }
        }

        // 統一呼叫 homing constructor：有目標就追蹤，沒目標在 ctor 裡直射
        auto msl = std::make_shared<Bullet>(start, speed, bestTgt);
        m_Bullets.push_back(msl);
        renderer->AddChild(msl);
    };

    // 從左右兩側各發一顆
    spawnMissile(center - offset);
    spawnMissile(center + offset);
}
