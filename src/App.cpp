#include "App.hpp"

#include "ResourceManager.hpp"
#include "Util/Image.hpp"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "Util/Logger.hpp"

void App::Start() {
    LOG_TRACE("Start");
    Util::Logger::Init();
    Util::Logger::SetLevel(Util::Logger::Level::DEBUG);  // 👈 設定最低 Log Level

    LOG_INFO("Game Started!");

    m_BackGround = std::make_shared<BackgroundImage>();



    // 1️⃣ 創建玩家角色 (戰機)
    m_Player = std::make_shared<Character>(RESOURCE_DIR "/character/test_plane.png");
    m_Player->SetPosition({-112.5f, -140.5f});  // 螢幕中央
    m_Player->SetZIndex(10);                  // 讓玩家顯示在最前面
    m_Root.AddChild(m_Player);



    // 3️⃣ 初始化 Renderer 並加入根物件
    m_Renderer = std::make_unique<Util::Renderer>(
        std::vector<std::shared_ptr<Util::GameObject>>{std::make_shared<Util::GameObject>(m_Root)}
    );

    m_EnemySpawnTimer = 0.0f;

    // 測試：生成一架敵機
    auto enemy = std::make_shared<Enemy>(glm::vec2(400, -50), Enemy::MovePattern::WAVE);
    m_Enemies.push_back(enemy);
    m_Renderer->AddChild(enemy);

    m_CurrentState = State::UPDATE;
}

void App::Update() {

    //TODO: do your things here and delete this line <3
    const float speed = 10.0f; // 控制移動速度
    float x = m_Player->GetPosition().x;
    float y = m_Player->GetPosition().y;


    if (Util::Input::IsKeyPressed(Util::Keycode::UP)) {
        y += speed;
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::DOWN)) {
        y -= speed;
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::LEFT)) {
        x -= speed;
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::RIGHT)) {
        x += speed;

    }

    // 按空白鍵射擊
    if (Util::Input::IsKeyPressed(Util::Keycode::SPACE)) {
        LOG_INFO("Space key detected on key down!");
        m_Player->Shoot();
    }

    // 按 `Z` 鍵使用技能
    if (Util::Input::IsKeyPressed(Util::Keycode::Z)) {
        m_Player->UseSkill();
    }

    // 設定新的玩家位置
    m_Player->SetPosition({x, y});

    // 更新玩家與子彈
    m_Player->Update();
    // 更新畫面
    for (auto &bullet : m_Player->GetBullets()) {
        if (!bullet->IsInRenderer()) {
            LOG_INFO("Adding bullet to Renderer at position ({}, {})", bullet->GetPosition().x, bullet->GetPosition().y);
            m_Renderer->AddChild(bullet);
            bullet->MarkAsInRenderer();
        }
        if(!bullet->InBound()){
            LOG_INFO("Bullet removed at position ({}, {})",  bullet->GetPosition().x,  bullet->GetPosition().y);
            m_Player->RmBullets(bullet);
            m_Renderer->RemoveChild(bullet);
        }
    }



    m_Renderer->Update();

    //敵機生成
    const float enemySpawnInterval = 100.0f; // 每 100 帧生成一架敵機
    m_EnemySpawnTimer += 1.0f;

    // 生成新敵機
    if (m_EnemySpawnTimer > enemySpawnInterval) {
        int randomX = std::rand() % 800-400; // 在 0~800 之間隨機生成 X 座標

        // 隨機選擇敵機的移動模式
        Enemy::MovePattern randomPattern = static_cast<Enemy::MovePattern>(std::rand() % 5);

        auto enemy = std::make_shared<Enemy>(glm::vec2(randomX, -50), randomPattern);
        m_Enemies.push_back(enemy);
        m_Renderer->AddChild(enemy);
        LOG_INFO("Spawned enemy at ({}, {}) with pattern {}", randomX, -50, static_cast<int>(randomPattern));

        m_EnemySpawnTimer = 0.0f; // 重置計時器
    }

    // 更新所有敵機
    for (auto& enemy : m_Enemies) {
        enemy->Update(m_Player->GetPosition()); // 讓敵機能夠追蹤玩家
    }

    // 更新畫面
    m_Renderer->Update();



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
