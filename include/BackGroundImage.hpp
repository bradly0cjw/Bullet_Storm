//
// Created by LINBEI on 25.03.07.
//

#ifndef BACKGROUND_IMAGE_HPP
#define BACKGROUND_IMAGE_HPP

#include "Util/GameObject.hpp"
#include "Util/Image.hpp"

class BackgroundImage : public Util::GameObject {
public:
    BackgroundImage();

    void NextPhase(const int phase);

private:
    std::string ImagePath(const int phase);
};

#endif // BACKGROUND_IMAGE_HPP
