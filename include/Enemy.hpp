//
// Created by Owner on 2025/3/19.
//

#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Util/GameObject.hpp"
#include "Util/Image.hpp"
#include "Bullet.hpp"
#include <chrono>

class Enemy : public Util::GameObject {
public:
    enum class MovePattern {
        STRAIGHT,  // 直線前進
        WAVE,      // 左右擺動
        TRACK,     // 追蹤玩家
        ZIGZAG,    // Z 字形移動
        RANDOM     // 隨機移動
    };

    Enemy(const glm::vec2 &position, MovePattern pattern);

    void Update(glm::vec2 playerPosition); // 傳入玩家位置，讓敵機能夠追蹤

    void Shoot(glm::vec2 playerPosition); // 發射子彈

    std::vector<std::shared_ptr<Bullet>> GetBullets() { return m_Bullets; } // 取得子彈列表

    bool IsOutOfScreen() const; // 檢查是否超出畫面

    void RmBullets(const std::shared_ptr<Bullet> &bullet) {
        auto it = std::find(m_Bullets.begin(), m_Bullets.end(), bullet);
        if (it != m_Bullets.end()) {
            m_Bullets.erase(it);  // Remove the shared_ptr from m_Bullets
        }
    }


    static std::string GetImagePath(MovePattern pattern); // 取得不同敵機的圖片

    bool CanShoot();


    [[nodiscard]] const glm::vec2 &GetPosition() const { return m_Transform.translation; }

private:

    std::chrono::steady_clock::time_point m_LastShootTime;
    glm::vec2 m_Velocity;
    MovePattern m_MovePattern;
    float m_Speed;
    float m_ShootCooldown = 0.0f; // 子彈冷卻時間
    float m_WaveAngle;  // 用於擺動運動
    std::vector<std::shared_ptr<Bullet>> m_Bullets; // 子彈列表
};

#endif //ENEMY_HPP
