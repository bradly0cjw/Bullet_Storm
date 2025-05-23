#include "Character.hpp"
#include "Util/Image.hpp"
#include <iostream>
#include "Util/Logger.hpp"


Character::Character(const std::string &ImagePath) {
    LOG_INFO("Character created with image path: {}", ImagePath);
    SetImage(ImagePath);

    ResetPosition();
}

void Character::SetImage(const std::string &ImagePath) {
    m_ImagePath = ImagePath;

    m_Drawable = std::make_shared<Util::Image>(m_ImagePath);
}

void Character::Shoot() {
    LOG_INFO("Shoot function called!");

    // 取得當前 player 位置
    glm::vec2 playerPos = GetPosition();

    // 設定子彈起始位置（稍微往前，避免被 player 遮住）
    glm::vec2 bulletStartPos = playerPos + glm::vec2(0, 50); // 改為 50px 正方向

    // 讓子彈向前飛行
    auto bullet = std::make_shared<Bullet>(bulletStartPos, glm::vec2(0, 10)); // 改為正方向

    m_Bullets.push_back(bullet);
    bullet->SetVisible(true); // 確保子彈可見
    LOG_INFO("Bullet created at ({}, {})", bulletStartPos.x, bulletStartPos.y);
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

void Character::Update() {
    // 更新所有子彈
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
