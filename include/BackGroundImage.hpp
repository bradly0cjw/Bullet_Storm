//
// Created by LINBEI on 25.03.07.
//

#ifndef BACKGROUND_IMAGE_HPP
#define BACKGROUND_IMAGE_HPP

#include "Util/GameObject.hpp"
#include "Util/Image.hpp"

class BackgroundImage : public Util::GameObject {

public:
    BackgroundImage() : GameObject(
            std::make_unique<Util::Image>(RESOURCE_DIR"/asset/image1.png"), -10) {
    }

    void NextPhase(const int phase) {
        auto temp = std::dynamic_pointer_cast<Util::Image>(m_Drawable);
        temp->SetImage(ImagePath(phase));
    }

private:
    inline std::string ImagePath(const int phase) {
        return RESOURCE_DIR"/asset/image1" + std::to_string(phase) + ".png";
    }
};

#endif //BACKGROUND_IMAGE_HPP
