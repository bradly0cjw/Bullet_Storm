//
// Created by Owner on 2025/3/10.
//

#ifndef BULLET_H
#define BULLET_H

#include "Util/GameObject.hpp"
#include "Util/Image.hpp"


class Enemy;

class Bullet : public Util::GameObject {
public:
    Bullet(const glm::vec2& position, const glm::vec2& velocity);
    // 新增：homing 建構子
    Bullet(const glm::vec2& position, float speed, std::shared_ptr<Enemy> target);

    [[nodiscard]] const glm::vec2& GetPosition() const { return m_Transform.translation; }

    void Update();
    bool IsInRenderer() const { return m_InRenderer; }
    void MarkAsInRenderer() { m_InRenderer = true; }
    bool InBound();

    bool CollidesWith(const std::shared_ptr<Util::GameObject> &other) const;

private:
    glm::vec2 m_Velocity;
    bool m_InRenderer = false;

    bool m_IsHoming = false;
    float m_HomingSpeed = 0.0f;
    std::weak_ptr<Enemy> m_HomingTarget;

};

#endif //BULLET_H
