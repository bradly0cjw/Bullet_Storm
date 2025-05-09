//
// Created by Owner on 2025/3/27.
//

#ifndef BOSS_HPP
#define BOSS_HPP
#include "Util/GameObject.hpp"
#include "Util/Image.hpp"
#include "Enemy.hpp"

class Boss : public Enemy {
public:
    Boss(const glm::vec2& position);
    void Update();  // 控制移動
    void TakeDamage(int amount);
    bool IsDead() const;
    bool IsVisible() const {
        return m_Visible;
    }
    void Activate() {
        m_Active = true;
    }
    float GetWidth() const { return m_HitboxWidth; }
    float GetHeight() const { return m_HitboxHeight; }

    float m_HitboxWidth = 600.0f;
    float m_HitboxHeight = 291.0f;




private:
    int m_Health;
    bool m_Active;  // 是否進入畫面中
};
#endif //BOSS_HPP
