//
// Created by Owner on 2025/3/10.
//

#ifndef BULLET_H
#define BULLET_H

#include "Util/GameObject.hpp"
#include "Util/Image.hpp"
#include "PowerUp.hpp" // Added for PowerUpType


class Enemy;

class Bullet : public Util::GameObject {
public:
    // Constructor for normal bullets, now accepts PowerUpType and isEnemyBullet flag
    Bullet(const glm::vec2& position, const glm::vec2& velocity, PowerUpType type, bool isEnemyBullet = false);

    // Constructor for homing missiles
    Bullet(const glm::vec2& position, float speed, const std::shared_ptr<Enemy>& target,
           PowerUpType visualTypeForHomingPlayerBullet);
    // Made target a const reference

    [[nodiscard]] const glm::vec2& GetPosition() const { return m_Transform.translation; }

    void Update();
    [[nodiscard]] bool IsInRenderer() const { return m_InRenderer; } // Added [[nodiscard]]
    void MarkAsInRenderer() { m_InRenderer = true; }
    [[nodiscard]] bool InBound(); // Should also be [[nodiscard]] if it returns a meaningful bool

    [[nodiscard]] bool CollidesWith(const std::shared_ptr<Util::GameObject>& other) const; // Added [[nodiscard]]

private:
    glm::vec2 m_Velocity;
    bool m_InRenderer = false;

    bool m_IsHoming = false;
    float m_HomingSpeed = 0.0f;
    std::weak_ptr<Enemy> m_HomingTarget;

};

#endif //BULLET_H
