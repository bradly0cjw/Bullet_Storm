//
// Created by LINBEI on 25.03.07.
//

#ifndef RESOURCEMANAGER_HPP
#define RESOURCEMANAGER_HPP

#include "Util/GameObject.hpp"
#include "BackGroundImage.hpp"


class ResourceManger {
public:
    ResourceManger();

    [[nodiscard]] std::vector<std::shared_ptr<Util::GameObject>> GetChildren() const {
//        return {m_TaskText, m_Background};
        return {m_Background};
    }

    void NextPhase();

private:
//    std::shared_ptr<TaskText> m_TaskText;
    std::shared_ptr<BackgroundImage> m_Background;

    int m_Phase = 1;
};



#endif //RESOURCEMANAGER_HPP
