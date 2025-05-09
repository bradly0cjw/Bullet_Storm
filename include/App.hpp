#ifndef APP_HPP
#define APP_HPP
#define ll long long
#include "pch.hpp" // IWYU pragma: export

#include "Util/Image.hpp"
#include "ResultText.hpp"
#include "Util/GameObject.hpp"
#include "Util/Renderer.hpp"
#include "Character.hpp"
#include "AnimatedCharacter.hpp"
#include "BackgroundImage.hpp"
#include "Enemy.hpp"
#include "PhaseResourceManager.hpp"
#include <vector>
#include "Boss.hpp"
#include "PowerUp.hpp"


class App {
public:
    enum class State {
        MENU,
        START,
        UPDATE,
        RESULT,
        END,
    };
    App() : m_CurrentState(State::MENU) {}   // 初始進入 Menu

    State GetCurrentState() const { return m_CurrentState; }

    void Start();
    void Menu();

    void Update();
    void result();

    void End(); // NOLINT(readability-convert-member-functions-to-static)

private:
    void ValidTask();

    std::shared_ptr<Util::GameObject> m_MenuTitle;
    std::shared_ptr<Util::GameObject> m_StartButton;
    bool m_ButtonPressed = false;
    bool m_MenuInitialized = false;

    State m_CurrentState = State::MENU;

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
    ll m_EnemySpawnTimer;

    // bullet
    ll m_bulletCooldownTimer = 0.0f; // 紀錄子彈冷卻時間


    std::shared_ptr<ResultText> m_ResultText;
    bool m_ResultShown = false;

    // 讓結束頁面停住
    bool m_WaitForSpaceRelease = true;


    std::shared_ptr<Boss> m_Boss;
    ll m_Timer;  // 記錄遊戲經過時間（秒）
    ll m_collisionTimer = 0.0f;  // 紀錄碰撞時間

    // powerup
    std::vector<std::shared_ptr<PowerUp>> m_PowerUps;

};

#endif
