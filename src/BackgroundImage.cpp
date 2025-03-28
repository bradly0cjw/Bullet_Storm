//
// Created by LINBEI on 25.03.21.
//
#include "BackgroundImage.hpp"
#include <memory>
#include <string>
#include "Util/Logger.hpp"

BackgroundImage::BackgroundImage() : GameObject(
        std::make_unique<Util::Image>(RESOURCE_DIR"/image2.jpg"), -10) {
    auto temp = dynamic_cast<Util::Image *>(m_Drawable.get());
    if (temp) {
        m_ImageSize = temp->GetSize();
        auto position = m_ImageSize;
        position.x = 0;
        position.y *= 1;
        SetPosition(position);
        LOG_WARN("current position: ({}, {})", m_Transform.translation.x, m_Transform.translation.y);
    }
}

void BackgroundImage::NextPhase(const int phase) {
    auto temp = std::dynamic_pointer_cast<Util::Image>(m_Drawable);
    temp->SetImage(ImagePath(phase));
}

void BackgroundImage::ScrollScene() {
    // if the background is on y = 0, then don't scroll
//    if (m_Transform.translation.y == 0) {
//        return;
//    }
    m_Transform.translation.y -= 5;
}

std::string BackgroundImage::ImagePath(const int phase) {
    return RESOURCE_DIR"/image1" + std::to_string(phase) + ".jpg";
}