//
// Created by Owner on 2025/3/19.
//

#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Util/GameObject.hpp"
#include "Util/Image.hpp"
#include "Bullet.hpp"

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

    bool IsOutOfScreen() const; // 檢查是否超出畫面

    static std::string GetImagePath(MovePattern pattern); // 取得不同敵機的圖片

    [[nodiscard]] const glm::vec2 &GetPosition() const { return m_Transform.translation; }

private:
    glm::vec2 m_Velocity;
    MovePattern m_MovePattern;
    float m_Speed;
    float m_WaveAngle;  // 用於擺動運動
    std::vector<std::shared_ptr<Bullet>> m_Bullets; // 子彈列表
};

#endif //ENEMY_HPP
