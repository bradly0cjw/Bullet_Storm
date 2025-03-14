//
// Created by Owner on 2025/3/10.
//

#ifndef BULLET_H
#define BULLET_H

#include "Util/GameObject.hpp"
#include "Util/Image.hpp"

class Bullet : public Util::GameObject {
public:
    Bullet(const glm::vec2& position, const glm::vec2& velocity);
    [[nodiscard]] const glm::vec2& GetPosition() const { return m_Transform.translation; }

    void Update();
    bool IsInRenderer() const { return m_InRenderer; }
    void MarkAsInRenderer() { m_InRenderer = true; }
    bool InBound();

private:
    glm::vec2 m_Velocity;
    bool m_InRenderer = false;

};

#endif //BULLET_H
