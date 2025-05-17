#include "Bullet.hpp"
#include "Util/Logger.hpp"
#include "Boss.hpp"

Bullet::Bullet(const glm::vec2& position, const glm::vec2& velocity)
    : Util::GameObject(std::make_shared<Util::Image>(RESOURCE_DIR "/character/bullet.png"), 1),
      m_Velocity(velocity) {
    m_Transform.translation = position;
    SetVisible(true);

    if (!m_Drawable) {
        LOG_ERROR("Bullet image failed to load!");
    } else {
       // LOG_INFO("Bullet created at ({}, {}) with image", m_Transform.translation.x, m_Transform.translation.y);
    }
}

Bullet::Bullet(const glm::vec2& position, float speed, std::shared_ptr<Enemy> target)
  : Util::GameObject(
      std::make_shared<Util::Image>(RESOURCE_DIR "/character/missile.png"),
      /*z=*/1
    ),
    m_HomingSpeed(speed),
    m_HomingTarget(target),
    m_IsHoming(true)
{
    m_Transform.translation = position;

    // 如果有鎖定目標，就先直接計算一個初始速度
    if (auto t = m_HomingTarget.lock()) {
        glm::vec2 dir = glm::normalize(t->GetTransform().translation - position);
        m_Velocity = glm::vec2(dir.x * speed, dir.y * speed);
    } else {
        // 沒目標就直線往上
        m_Velocity = glm::vec2(0.0f, speed);
    }
}

bool Bullet::CollidesWith(const std::shared_ptr<Util::GameObject>& other) const {
    glm::vec2 bulletPos = m_Transform.translation;
    glm::vec2 targetPos = other->GetTransform().translation;

    // 取得對方 hitbox（如果是 Boss，就用自定義範圍；否則預設）
    float halfW = 32.0f;
    float halfH = 32.0f;

    // 判斷是否是 Boss 並轉型
    if (auto boss = std::dynamic_pointer_cast<Boss>(other)) {
        halfW = boss->GetHitboxWidth() / 2.0f;
        halfH = boss->GetHitboxHeight() / 2.0f;
    }

    return (
        bulletPos.x > targetPos.x - halfW &&
        bulletPos.x < targetPos.x + halfW &&
        bulletPos.y > targetPos.y - halfH &&
        bulletPos.y < targetPos.y + halfH
    );
}


void Bullet::Update() {
    if (m_IsHoming) {
        if (auto t = m_HomingTarget.lock()) {
            // 取當前位置跟目標方向
            glm::vec2 dir = glm::normalize(t->GetTransform().translation - m_Transform.translation);
            // 分量乘速率
            m_Velocity = glm::vec2(dir.x * m_HomingSpeed, dir.y * m_HomingSpeed);
        }
    }
    m_Transform.translation += m_Velocity;


    //LOG_INFO("Bullet position: ({}, {})", m_Transform.translation.x, m_Transform.translation.y);

}

bool Bullet::InBound(){
    if (m_Transform.translation.y < -400 || m_Transform.translation.y > 400) {
        SetVisible(false);
        return false;
    }
    return true;
}

