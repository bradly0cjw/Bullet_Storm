//
// Created by Owner on 2025/3/27.
//

#include "Boss.hpp"
#include "Util/Logger.hpp"

Boss::Boss(const glm::vec2& position)
    : Util::GameObject(std::make_shared<Util::Image>(RESOURCE_DIR "/enemy/boss.png"), 2),
      m_Health(500), m_Active(false) {
    m_Transform.translation = position;
    SetVisible(false);  // 預設不可見
}

void Boss::Update() {
    if (!m_Active) return;

    // 慢慢往下移動直到三分之一處（假設畫面高度為 900）
    if (m_Transform.translation.y > 100) {
        m_Transform.translation.y -= 1.5f;  // 緩慢移動
    }
}

void Boss::TakeDamage(int amount) {
    m_Health -= amount;
    LOG_INFO("Boss hit! Health: {}", m_Health);
    if (m_Health <= 0) {
        SetVisible(false);
        LOG_INFO("Boss defeated!");
    }
}

bool Boss::IsDead() const {
    return m_Health <= 0;
}
