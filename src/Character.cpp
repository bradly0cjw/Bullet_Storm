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
    if (std::get<0>(m_skill) == 0) {
        LOG_INFO("Skill not ready!");
        return;
    }
    // 技能：發射 3 顆子彈
    m_Bullets.push_back(std::make_shared<Bullet>(GetPosition(), glm::vec2(-3, 10))); // 左斜
    m_Bullets.push_back(std::make_shared<Bullet>(GetPosition(), glm::vec2(0, 10)));  // 直線
    m_Bullets.push_back(std::make_shared<Bullet>(GetPosition(), glm::vec2(3, 10)));  // 右斜
    // subtract 1 from skill count
    std::get<0>(m_skill) -= 1;
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