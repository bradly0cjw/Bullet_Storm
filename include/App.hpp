#ifndef APP_HPP
#define APP_HPP

#include "pch.hpp" // IWYU pragma: export

#include "Util/Image.hpp"
#include "Util/GameObject.hpp"
#include "Util/Renderer.hpp"
#include "Character.hpp"
#include "AnimatedCharacter.hpp"
#include "BackgroundImage.hpp"
#include "Enemy.hpp"
#include "PhaseResourceManager.hpp"
#include <vector>

class App {
public:
    enum class State {
        START,
        UPDATE,
        END,
    };

    State GetCurrentState() const { return m_CurrentState; }

    void Start();

    void Update();

    void End(); // NOLINT(readability-convert-member-functions-to-static)

private:
    void ValidTask();

    State m_CurrentState = State::START;

    // 遊戲根物件，負責管理所有物件
    Util::GameObject m_Root;

    // Background
    std::shared_ptr<BackgroundImage> m_BackGround;

    // PhaseResourceManager
    std::shared_ptr<PhaseResourceManager> m_PRM;

    // 角色物件
    std::shared_ptr<Character> m_Player;
    std::shared_ptr<AnimatedCharacter> m_Enemy;

    // 遊戲渲染器
    std::unique_ptr<Util::Renderer> m_Renderer;

    // 敵機
    std::vector<std::shared_ptr<Enemy>> m_Enemies;
    float m_EnemySpawnTimer;
};

#endif
