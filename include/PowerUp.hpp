#ifndef POWERUP_HPP
#define POWERUP_HPP

#include "Util/GameObject.hpp"
#include "Util/Image.hpp"
#include <glm/vec2.hpp>

enum class PowerUpType { RED, PURPLE, BLUE };

class PowerUp : public Util::GameObject {
public:
    PowerUp(PowerUpType type, const glm::vec2 &pos, const glm::vec2 &vel);
    void Update();                // 每 frame 更新位置與彈跳
    PowerUpType GetType() const;  // 拾取後觸發的效果
private:
    glm::vec2 m_Velocity;
    PowerUpType m_Type;
};

#endif // POWERUP_HPP
