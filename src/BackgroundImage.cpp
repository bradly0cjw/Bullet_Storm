//
// Created by LINBEI on 25.03.21.
//
#include "BackgroundImage.hpp"
#include <memory>
#include <string>

BackgroundImage::BackgroundImage() : GameObject(
        std::make_unique<Util::Image>(RESOURCE_DIR"/image1.jpg"), -10) {
}

void BackgroundImage::NextPhase(const int phase) {
    auto temp = std::dynamic_pointer_cast<Util::Image>(m_Drawable);
    temp->SetImage(ImagePath(phase));
}

std::string BackgroundImage::ImagePath(const int phase) {
    return RESOURCE_DIR"/image1" + std::to_string(phase) + ".jpg";
}