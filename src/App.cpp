#include "App.hpp"

#include "ResourceManager.hpp"
#include "Util/Image.hpp"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "Util/Logger.hpp"
#include "PhaseResourceManager.hpp"

void App::Start() {
    LOG_TRACE("Start");
    Util::Logger::Init();
    Util::Logger::SetLevel(Util::Logger::Level::DEBUG);  // 👈 設定最低 Log Level

    LOG_INFO("Game Started!");




    // 1️⃣ 創建玩家角色 (戰機)
    m_Player = std::make_shared<Character>(RESOURCE_DIR "/character/test_plane.png");
    m_Player->SetPosition({-112.5f, -140.5f});  // 螢幕中央
    m_Player->SetZIndex(1);                  // 讓玩家顯示在最前面
    m_Root.AddChild(m_Player);



    // 3️⃣ 初始化 Renderer 並加入根物件
    m_Renderer = std::make_unique<Util::Renderer>(
            std::vector<std::shared_ptr<Util::GameObject>>{std::make_shared<Util::GameObject>(m_Root)}
    );

    m_PRM = std::make_shared<PhaseResourceManager>();
    m_Renderer->AddChildren(m_PRM->GetChildren());


    m_EnemySpawnTimer = std::time(nullptr);

    // 測試：生成一架敵機
    auto enemy = std::make_shared<Enemy>(glm::vec2(400, -50), Enemy::MovePattern::WAVE);
    m_Enemies.push_back(enemy);
    m_Renderer->AddChild(enemy);

    // generate boss
    m_Timer = std::time(nullptr);

    m_Boss = std::make_shared<Boss>(glm::vec2(100, 350));  // 從畫面外開始
    m_Renderer->AddChild(m_Boss);

    m_CurrentState = State::UPDATE;
}

void App::Update() {

    //TODO: do your things here and delete this line <3
    const float speed = 10.0f; // 控制移動速度
    float x = m_Player->GetPosition().x;
    float y = m_Player->GetPosition().y;

    // Check if the player is in bound     then accept the input

    if (Util::Input::IsKeyPressed(Util::Keycode::UP) || Util::Input::IsKeyPressed(Util::Keycode::W)) {
        if (m_Player->GetPosition().y < 300) {
            y += speed;
        }
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::DOWN) || Util::Input::IsKeyPressed(Util::Keycode::S)) {
        if (m_Player->GetPosition().y > -300) {
            y -= speed;
        }
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::LEFT) || Util::Input::IsKeyPressed(Util::Keycode::A)) {
        if (m_Player->GetPosition().x > -400) {
            x -= speed;
        }
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::RIGHT) || Util::Input::IsKeyPressed(Util::Keycode::D)) {
        if (m_Player->GetPosition().x < 400) {
            x += speed;
        }

    }

    auto bullet_cooldown = std::clock(); // Use std::clock() for clarity
    // 按空白鍵射擊
    if (Util::Input::IsKeyPressed(Util::Keycode::SPACE)) {
        LOG_INFO("Space key detected on key down!");
        // 檢查子彈冷卻時間
        if (static_cast<float>(bullet_cooldown - m_bulletCooldownTimer) / CLOCKS_PER_SEC > 0.2f) { // 0.2 秒冷卻時間
            m_bulletCooldownTimer = bullet_cooldown; // 更新冷卻時間
            m_Player->Shoot();
        }
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
    for (auto &bullet: m_Player->GetBullets()) {
        if (!bullet->IsInRenderer()) {
            LOG_INFO("Adding bullet to Renderer at position ({}, {})", bullet->GetPosition().x,
                     bullet->GetPosition().y);
            m_Renderer->AddChild(bullet);
            bullet->MarkAsInRenderer();
        }
        if (!bullet->InBound()) {
            LOG_INFO("Bullet removed at position ({}, {})", bullet->GetPosition().x, bullet->GetPosition().y);
            m_Player->RmBullets(bullet);
            m_Renderer->RemoveChild(bullet);
            LOG_INFO("Bullet Count: {}", m_Player->GetBullets().size());
        }
    }


    m_Renderer->Update();

    //敵機生成
    const float enemySpawnInterval = 1.0f; // 每 1 秒生成一架敵機
    auto currentTime_Enemy = std::time(nullptr);

    m_PRM->ScrollScene();

    // 生成新敵機
    if (std::difftime(currentTime_Enemy, m_EnemySpawnTimer) > enemySpawnInterval) {
        // use srand to generate random number
        std::srand(std::time(nullptr));

        // TODO: fit screen size
        int randomX = (std::rand() % 800) - 400; // 在 0~800 之間隨機生成 X 座標

        LOG_INFO("Current random x value", randomX);
        // 隨機選擇敵機的移動模式
        Enemy::MovePattern randomPattern = static_cast<Enemy::MovePattern>(std::rand() % 5);

        auto enemy = std::make_shared<Enemy>(glm::vec2(randomX, 350), randomPattern);
        m_Enemies.push_back(enemy);
        m_Renderer->AddChild(enemy);
        LOG_INFO("Spawned enemy at ({}, {}) with pattern {}", randomX, -50, static_cast<int>(randomPattern));

        m_EnemySpawnTimer = std::time(nullptr); // 重置計時器
    }

    // 更新所有敵機
    for (auto &enemy: m_Enemies) {
        enemy->Update(m_Player->GetPosition()); // 讓敵機能夠追蹤玩家
    }
    // render all enemies bullets
    for (auto &enemy: m_Enemies) {
        for (auto &bullet: enemy->GetBullets()) {
            if (!bullet->IsInRenderer()) {
                LOG_INFO("Adding enemy bullet to Renderer at position ({}, {})", bullet->GetPosition().x,
                         bullet->GetPosition().y);
                m_Renderer->AddChild(bullet);
                bullet->MarkAsInRenderer();
            }
            if (!bullet->InBound()) {
                LOG_INFO("Enemy Bullet removed at position ({}, {})", bullet->GetPosition().x, bullet->GetPosition().y);
                enemy->RmBullets(bullet);
                m_Renderer->RemoveChild(bullet);
                LOG_INFO("Enemy Bullet Count: {}", enemy->GetBullets().size());
            }
        }
    }
    // 紀錄要移除的子彈與敵機
    std::vector<std::shared_ptr<Bullet>> bulletsToRemove;
    std::vector<std::shared_ptr<Enemy>> enemiesToRemove;

    for (auto &bullet: m_Player->GetBullets()) {
        for (auto &enemy: m_Enemies) {
            if (bullet->CollidesWith(enemy)) {
                LOG_INFO("Bullet hit enemy at ({}, {})", enemy->GetPosition().x, enemy->GetPosition().y);
                bulletsToRemove.push_back(bullet);
                enemiesToRemove.push_back(enemy);
            }
        }
    }

    // 移除子彈-------------------------------------
    for (auto &bullet: bulletsToRemove) {
        m_Player->RmBullets(bullet);           // 從子彈容器中移除
        m_Renderer->RemoveChild(bullet);       // 從畫面上移除
    }

    // Check if enemy is out of bound
    for (auto &enemy: m_Enemies) {
        if (enemy->IsOutOfScreen()) {
            LOG_INFO("Enemy removed at position ({}, {})", enemy->GetPosition().x, enemy->GetPosition().y);
            enemiesToRemove.push_back(enemy);
        }
    }

    bool isPlayerHit = false;

// Check if player collides with enemy or enemy bullet
    for (auto &enemy: m_Enemies) {
        if (m_Player->IfCollides(enemy)) {
            auto currentTime = std::time(nullptr);
            if (currentTime - m_collisionTimer >= 3) { // 3 seconds cooldown
                LOG_INFO("Player collided with enemy at position ({}, {})", enemy->GetPosition().x,
                         enemy->GetPosition().y);
                m_Player->modifyHealth(-1);
                isPlayerHit = true;
                m_collisionTimer = currentTime;
            }
        }
        // check collides with enemy bullet
        for (auto &bullet: enemy->GetBullets()) {
            if (m_Player->IfCollides(bullet)) {
                auto currentTime = std::time(nullptr);
                if (currentTime - m_collisionTimer >= 3) { // 3 seconds cooldown
                    LOG_INFO("Player collided with enemy bullet at position ({}, {})", bullet->GetPosition().x,
                             bullet->GetPosition().y);
                    m_Player->modifyHealth(-1);
                    isPlayerHit = true;
                    m_collisionTimer = currentTime;
                }
            }
        }
    }

    // 移除敵機-------------------------------------
    for (auto &enemy: enemiesToRemove) {
        m_Enemies.erase(std::remove(m_Enemies.begin(), m_Enemies.end(), enemy), m_Enemies.end());
        //remove bullet which enemy shooted
        for (auto &bullet: enemy->GetBullets()) {
            m_Renderer->RemoveChild(bullet);
            LOG_INFO("Enemy Bullet removed at position ({}, {})", bullet->GetPosition().x, bullet->GetPosition().y);
        }
        m_Renderer->RemoveChild(enemy);
        LOG_INFO("enemy Count: {}", m_Enemies.size());
    }

    if (m_Player->GetHealth() <= 0) {
        m_CurrentState = State::END;
    }
    // 更新畫面
    m_Renderer->Update();


    // Boss 出現條件
    auto currentTime_Boss = std::time(nullptr);
    if (!m_Boss->IsVisible() && currentTime_Boss - m_Timer >= 10) {
        m_Boss->SetVisible(true);
        m_Boss->SetZIndex(100);  // 確保在最上層
        m_Boss->Activate();      // <<==== 加這行
        LOG_INFO("Boss appears!");
    }

    // 更新 Boss 移動
    if (m_Boss->IsVisible() && !m_Boss->IsDead()) {
        m_Boss->Update();
    }

    if (m_Boss->IsDead()) {
        m_Renderer->RemoveChild(m_Boss);
        LOG_INFO("Boss fully removed from Renderer.");
    }


    // Boss 碰撞檢查
    if (m_Boss->IsVisible() && !m_Boss->IsDead()) {
        for (auto &bullet: m_Player->GetBullets()) {
            if (bullet->CollidesWith(m_Boss)) {
                m_Player->RmBullets(bullet);
                m_Renderer->RemoveChild(bullet);
                m_Boss->TakeDamage(1);  // 每顆子彈傷害 1
                break; // 一顆子彈最多打一個物件
            }
        }
    }
    //Check if player collides with boss
    if (m_Player->IfCollides(m_Boss)) {
        auto currentTime = std::time(nullptr);
        if (currentTime - m_collisionTimer >= 3) { // 3 seconds cooldown
//            LOG_INFO("Player collided with boss at position ({}, {})", m_Boss->GetPosition().x, m_Boss->GetPosition().y);
            m_Player->modifyHealth(-1);
            m_collisionTimer = currentTime;
            isPlayerHit = true;
        }
    }

    //Remove all enemy if player is hit(except boss)
    if (isPlayerHit) {
        for (auto &enemy: m_Enemies) {
            m_Renderer->RemoveChild(enemy);
            //remove bullet which enemy shooted
            for (auto &bullet: enemy->GetBullets()) {
                m_Renderer->RemoveChild(bullet);
                LOG_INFO("Enemy Bullet removed at position ({}, {})", bullet->GetPosition().x, bullet->GetPosition().y);
            }
        }
        m_Enemies.clear();
        LOG_INFO("All enemies removed from Renderer.");
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
