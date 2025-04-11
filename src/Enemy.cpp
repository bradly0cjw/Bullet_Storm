//
// Created by Owner on 2025/3/19.
//
#include "Enemy.hpp"
#include "Util/Logger.hpp"
#include <cmath>
#include <cstdlib>
#include "Character.hpp"

//取得圖片
std::string Enemy::GetImagePath(MovePattern pattern) {
    switch (pattern) {
        case MovePattern::STRAIGHT:
            return RESOURCE_DIR "/enemy/enemy_plane.png";
        case MovePattern::WAVE:
            return RESOURCE_DIR "/enemy/e_tank2.png";
        case MovePattern::TRACK:
            return RESOURCE_DIR "/enemy/enemy_plane.png";
        case MovePattern::ZIGZAG:
            return RESOURCE_DIR "/enemy/e_tank1.png";
        case MovePattern::RANDOM:
            return RESOURCE_DIR "/enemy/enemy_plane.png";
        default:
            return RESOURCE_DIR "/enemies/enemy_default.png"; // 預設敵機圖片
    }
}

//(RESOURCE_DIR "/enemy/enemy_plane.png"), 1)
Enemy::Enemy(const glm::vec2 &position, MovePattern pattern)
        : Util::GameObject(std::make_shared<Util::Image>(GetImagePath(pattern)), 1),
          m_MovePattern(pattern),
          m_Speed(3.0f),
          m_WaveAngle(0.0f) {
    m_Transform.translation = position;
}

void Enemy::Shoot(glm::vec2 playerPosition) {
    // 取得當前敵機位置
    glm::vec2 enemyPos = GetPosition();

    // 設定子彈起始位置（稍微往前，避免被敵機遮住）
    glm::vec2 bulletStartPos = enemyPos + glm::vec2(0, -50); // 改為 50px 正方向

    // 讓子彈向前飛行
    auto bullet = std::make_shared<Bullet>(bulletStartPos, glm::vec2(0, -10)); // 改為正方向

    m_Bullets.push_back(bullet);
    bullet->SetVisible(true); // 確保子彈可見
    LOG_INFO("Enemy Shoot At ({}, {})", bulletStartPos.x, bulletStartPos.y);

}

void Enemy::Update(glm::vec2 playerPosition) {
    switch (m_MovePattern) {
        case MovePattern::STRAIGHT:
            m_Transform.translation.y -= m_Speed; // 直線下降
            break;

        case MovePattern::WAVE:
            m_Transform.translation.y -= m_Speed;
            m_Transform.translation.x += std::sin(m_WaveAngle) * 5.0f; // 左右擺動
            m_WaveAngle += 0.1f;
            break;

        case MovePattern::TRACK:
            if (playerPosition.x > m_Transform.translation.x) {
                m_Transform.translation.x += m_Speed * 0.5f; // 追蹤玩家
            } else {
                m_Transform.translation.x -= m_Speed * 0.5f;
            }

            if (playerPosition.y > m_Transform.translation.y) {
                m_Transform.translation.y += m_Speed * 0.5f; // 追蹤玩家
            } else {
                m_Transform.translation.y -= m_Speed * 0.5f;
            }
            break;

        case MovePattern::ZIGZAG:
            m_Transform.translation.y += m_Speed;
            m_Transform.translation.x += (std::rand() % 2 == 0 ? -2.0f : 2.0f); // 隨機左右移動
            break;

        case MovePattern::RANDOM:
            m_Transform.translation.y -= m_Speed;
            m_Transform.translation.x += (std::rand() % 5 - 2); // 在 -2 ~ +2 之間隨機左右移動
            break;
        default:
            LOG_ERROR("Unknown move pattern!");
            break;
    }
    Shoot(playerPosition); // 每次更新都射擊
//    // 超出畫面範圍則隱藏
//    if (IsOutOfScreen()) {
//        SetVisible(false);
//    }
    for (auto &bullet: m_Bullets) {
        bullet->Update();
        LOG_WARN("Updated by enemy");
    }
}

bool Enemy::IsOutOfScreen() const {
    return m_Transform.translation.y > 900 || m_Transform.translation.y < -900; // 900px 以下則消失
}
