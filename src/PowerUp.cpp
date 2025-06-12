#include "PowerUp.hpp"
#include "Util/Logger.hpp"
#include "Core/Context.hpp"

PowerUp::PowerUp(PowerUpType type, const glm::vec2 &pos, const glm::vec2 &vel)
    : Util::GameObject(
        std::make_shared<Util::Image>(
            // 根據 type 決定圖檔路徑
            std::string(RESOURCE_DIR) +
            (type==PowerUpType::RED      ? "/powerUp/red_bullet.png"   :
             type==PowerUpType::BLUE  ? "/powerUp/blue_bullet.png"   :
             type==PowerUpType::PURPLE  ?  "/powerUp/purple_bullet.png" :
             type==PowerUpType::H  ?  "/powerUp/H.png" :
             type==PowerUpType::P  ?  "/powerUp/P.png" :
             type==PowerUpType::M  ?  "/powerUp/M.png" :
                                     "/powerUp/B.png"
                                              )),
        /* zIndex */ 20
    ),
    m_Velocity(vel), m_Type(type)
{
    m_Transform.translation = pos;
    SetVisible(true);
}

void PowerUp::Update() {
    // 移動
    m_Transform.translation += m_Velocity;

    // 取得視窗尺寸
    auto ctx = Core::Context::GetInstance();
    float halfW = 400.0f; // ctx->GetWindowWidth() * 0.5f;
    float halfH = 300.0f; // ctx->GetWindowHeight() * 0.5f;

    auto &p = m_Transform.translation;
    // 左右邊界反彈
    if (p.x < -halfW || p.x > halfW) {
        m_Velocity.x = -m_Velocity.x;
        p.x = glm::clamp(p.x, -halfW, halfW);
    }
    // 上下邊界反彈
    if (p.y < -halfH || p.y > halfH) {
        m_Velocity.y = -m_Velocity.y;
        p.y = glm::clamp(p.y, -halfH, halfH);
    }
}

PowerUpType PowerUp::GetType() const {
    return m_Type;
}


