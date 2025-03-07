#include "App.hpp"

#include "ResourceManager.hpp"
#include "Util/Image.hpp"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "Util/Logger.hpp"

void App::Start() {
    LOG_TRACE("Start");
    m_CurrentState = State::UPDATE;
}

void App::Update() {
    
    //TODO: do your things here and delete this line <3

    ResourceManger::ResourceManger() {

        m_Background = std::make_shared<BackgroundImage>();
    }

    void ResourceManger::NextPhase() {
        if (m_Phase == 7) return;
        LOG_DEBUG("Passed! Next phase: {}", m_Phase);
        m_Background->NextPhase(m_Phase);
//
    }




    /*
     * Do not touch the code below as they serve the purpose for
     * closing the window.
     */
    if (Util::Input::IsKeyUp(Util::Keycode::ESCAPE) ||
        Util::Input::IfExit()) {
        m_CurrentState = State::END;
    }
}

void App::End() { // NOLINT(this method will mutate members in the future)
    LOG_TRACE("End");
}
