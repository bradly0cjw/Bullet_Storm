#ifndef RESULTTEXT_HPP
#define RESULTTEXT_HPP

#include "Util/GameObject.hpp"
#include "Util/Text.hpp"
#include "Util/Color.hpp"
#include "Util/Logger.hpp"
#include <filesystem>

class ResultText : public Util::GameObject {
public:
    ResultText(const std::string& message)
        : GameObject(
            std::make_unique<Util::Text>(
                RESOURCE_DIR "/Font/Inkfree.ttf",  // ✅ 字型路徑依照你的格式
                64,
                message,
                Util::Color::FromName(Util::Colors::WHITE)
            ),
            100  // z-index
        ) {
        m_Transform.translation = glm::vec2(0.0f, 0.0f);  // ✅ 顯示在畫面中間
        LOG_INFO("ResultText created with message: {}", message);
        LOG_INFO("ResultText positioned at ({}, {})", m_Transform.translation.x, m_Transform.translation.y);

        LOG_INFO("Font exists? {}", std::filesystem::exists(RESOURCE_DIR "/Font/arial.ttf"));

    }
};

#endif // RESULTTEXT_HPP
