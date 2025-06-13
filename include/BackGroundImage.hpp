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

    void SetPosition(const glm::vec2 &Position) { m_Transform.translation = Position; }

    [[nodiscard]] const glm::vec2 &GetPosition() { return m_Transform.translation; }

    [[nodiscard]] const glm::vec2 &GetPosition() const { return m_Transform.translation; }

    [[nodiscard]] const glm::vec2 &GetImageSize() const { return m_ImageSize; }

    void SetImageSize(const glm::vec2 &size) { m_ImageSize = size; }

    void NextPhase(const int phase);

    void ShakeMap();

    void ScrollScene();
//    void ScrollScene(){
//        auto init = GetPosition();
//        SetPosition({init.x, init.y - 5});
//    }
private:
    std::string ImagePath(const int phase);

    glm::vec2 m_ImageSize;

};

#endif // BACKGROUND_IMAGE_HPP
