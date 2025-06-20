//
// Created by LINBEI on 25.03.21.
//
#include "PhaseResourceManager.hpp"

#include "Util/Logger.hpp"

PhaseResourceManager::PhaseResourceManager() {
//    m_TaskText = std::make_shared<TaskText>();
    m_Background = std::make_shared<BackgroundImage>();
}

void PhaseResourceManager::ScrollScene() {
    m_Background->ScrollScene();
}
void PhaseResourceManager::ShakeMap()
{
    m_Background->ShakeMap();
}

void PhaseResourceManager::SetPosition(const glm::vec2 &Position) {
    m_Background->SetPosition(Position);
}
void PhaseResourceManager::NextPhase() {
    if (m_Phase == 7) return;
    LOG_DEBUG("Passed! Next phase: {}", m_Phase);
    m_Background->NextPhase(m_Phase);
//    m_TaskText->NextPhase(m_Phase++);
}
