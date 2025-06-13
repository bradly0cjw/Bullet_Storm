//
// Created by LINBEI on 25.03.21.
//

#ifndef PHASE_MANGER_HPP
#define PHASE_MANGER_HPP

#include "Util/GameObject.hpp"
//#include "TaskText.hpp"
#include "Character.hpp"
#include "BackgroundImage.hpp"

class PhaseResourceManager {
public:
    PhaseResourceManager();

    [[nodiscard]] std::vector<std::shared_ptr<Util::GameObject>> GetChildren() const {
        return {m_Background};
    }

    void NextPhase();

    void ScrollScene();

    void ShakeMap();

    void SetPosition(const glm::vec2 &Position);
private:
//    std::shared_ptr<TaskText> m_TaskText;
    std::shared_ptr<BackgroundImage> m_Background;

    int m_Phase = 1;

};


#endif //PHASE_MANGER_HPP
