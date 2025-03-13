#include "Bullet.hpp"
#include "Util/Logger.hpp"

Bullet::Bullet(const glm::vec2& position, const glm::vec2& velocity)
    : Util::GameObject(std::make_shared<Util::Image>(RESOURCE_DIR "/character/bullet.png"), 1),
      m_Velocity(velocity) {
    m_Transform.translation = position;
    SetVisible(true);

    if (!m_Drawable) {
        LOG_ERROR("Bullet image failed to load!");
    } else {
        LOG_INFO("Bullet created at ({}, {}) with image", m_Transform.translation.x, m_Transform.translation.y);
    }
}



void Bullet::Update() {
    m_Transform.translation += m_Velocity;

    LOG_INFO("Bullet position: ({}, {})", m_Transform.translation.x, m_Transform.translation.y);

    // 修正錯誤的移除判定
    if (m_Transform.translation.y < -50 || m_Transform.translation.y > 850) {
        SetVisible(false);
        LOG_INFO("Bullet removed at position ({}, {})", m_Transform.translation.x, m_Transform.translation.y);
    }
}

