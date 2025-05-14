#ifndef RESULTTEXT_HPP
#define RESULTTEXT_HPP

#include "Util/GameObject.hpp"
#include "Util/Text.hpp"
#include "Util/Color.hpp"
#include "Util/Logger.hpp"
#include <string> // Include for std::string
#include <memory> // Include for std::dynamic_pointer_cast
#include <filesystem>

class ResultText : public Util::GameObject {
public:
    // Constructor: Sets the initial text
    ResultText(const std::string& initialMessage)
        : GameObject(
            std::make_shared<Util::Text>( // Use make_shared since m_Drawable is shared_ptr
                RESOURCE_DIR "/Font/236_Smudger.ttf", // Font path
                64, // Font size
                initialMessage, // Initial text message
                Util::Color::FromName(Util::Colors::WHITE) // Text color
            ),
            100 // z-index
        ) {

        m_Transform.translation = glm::vec2(0.0f, -70.0f);  // ✅ 顯示在畫面中間
        LOG_INFO("ResultText created with message: {}", initialMessage);
        LOG_INFO("ResultText positioned at ({}, {})", m_Transform.translation.x, m_Transform.translation.y);


        // Check if font file exists (useful for debugging)
        // Note: Original log checked arial.ttf, ensure Inkfree.ttf is the correct one to check if needed.
        // LOG_INFO("Font exists? {}", std::filesystem::exists(RESOURCE_DIR "/Font/Inkfree.ttf"));
    }

    // Method to change the displayed text
    void SetText(const std::string& newMessage)
    {
        // Get the drawable, which we know is a Util::Text in this case.
        // We need to cast m_Drawable (which is shared_ptr<Util::Drawable>)
        // to shared_ptr<Util::Text> to access the SetText method.
        auto textDrawable = std::dynamic_pointer_cast<Util::Text>(m_Drawable);

        if (textDrawable)
        {
            // If the cast is successful, call the SetText method of Util::Text
            // (Assuming Util::Text has a public SetText method)
            textDrawable->SetText(newMessage);
            LOG_INFO("ResultText updated to: {}", newMessage);
        }
        else
        {
            LOG_ERROR("Failed to cast Drawable to Text in ResultText::SetText");
            // This should not happen if the constructor setup is correct.
        }
    }
};

#endif // RESULTTEXT_HPP
