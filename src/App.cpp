#include "App.hpp"   // 假设你在 include/Bullet_Storm/App.hpp

#include "ResourceManager.hpp"
#include "Util/Text.hpp"
#include "Util/Image.hpp"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "Util/Logger.hpp"
#include "PhaseResourceManager.hpp"
#include "Enemy.hpp" // Make sure this points to your new Enemy.hpp
#include "Boss.hpp"
#include <cstdlib> // For std::srand, std::rand
#include <ctime>   // For std::time
#include "Core/Context.hpp"


void App::Menu()
{
    LOG_TRACE("Start");
    Util::Logger::Init();
    Util::Logger::SetLevel(Util::Logger::Level::DEBUG); // 👈 設定最低 Log Level
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // Seed RNG once
    LOG_INFO("Game Started!");
    // 3️⃣ 初始化 Renderer 並加入根物件
    if (!m_MenuInitialized)
    {
        // 只做一次
        m_Renderer = std::make_unique<Util::Renderer>(
            std::vector<std::shared_ptr<Util::GameObject>>{std::make_shared<Util::GameObject>(m_Root)}
        );

        m_MenuBackground = std::make_shared<Util::GameObject>(
            std::make_shared<Util::Image>(RESOURCE_DIR "/entrance/background.png"),
            /* z-index */ 0);
        // 如果背景圖要充滿畫面，通常 translation = {0,0} 就好（中心對齊）
        m_MenuBackground->m_Transform.translation = {0.0f, 0.0f};
        m_Renderer->AddChild(m_MenuBackground);
        m_MenuTitle = std::make_shared<Util::GameObject>(
            std::make_shared<Util::Image>(RESOURCE_DIR "/entrance/title.png"), 100);
        m_MenuTitle->m_Transform.translation = {0, 0};
        m_StartButton = std::make_shared<Util::GameObject>(
            std::make_shared<Util::Image>(RESOURCE_DIR "/entrance/start.png"), 100);
        m_StartButton->m_Transform.translation = {0, -50};

        m_Renderer->AddChild(m_MenuTitle);
        m_Renderer->AddChild(m_StartButton);

        m_MenuInitialized = true;
    }
    // 偵測滑鼠點擊
    if (Util::Input::IsKeyDown(Util::Keycode::MOUSE_LB))
    {
        auto pos = Util::Input::GetCursorPosition();
        // GameObject 位置在 m_Transform.translation
        auto btnPos = m_StartButton->m_Transform.translation;
        // 假設 start button 大小 200×80
        if (pos.x >= btnPos.x - 120 && pos.x <= btnPos.x + 120 &&
            pos.y >= btnPos.y - 140 && pos.y <= btnPos.y + 140)
        {
            m_ButtonPressed = true;
        }
    }
    // 等滑鼠放開再真正觸發
    if (m_ButtonPressed && !Util::Input::IsKeyPressed(Util::Keycode::MOUSE_LB))
    {
        // 清掉 menu 圖片
        m_Renderer->RemoveChild(m_MenuTitle);
        m_Renderer->RemoveChild(m_StartButton);
        m_Renderer->RemoveChild(m_MenuBackground);
        m_MenuTitle.reset();
        m_StartButton.reset();
        m_MenuBackground.reset();
        m_ButtonPressed = false;

        // 切到 START 做遊戲初始化
        m_CurrentState = State::START;
    }

    m_Renderer->Update();
}

void App::Start()
{
    LOG_INFO("Game Started!");

    // 1️⃣ 創建玩家角色 (戰機)
    m_Player = std::make_shared<Character>(RESOURCE_DIR "/character/player_red.png");
    m_Player->SetPosition({-112.5f, -140.5f}); // 螢幕中央
    m_Player->m_Transform.scale = {0.5f, 0.5f};

    m_Player->SetZIndex(50); // 讓玩家顯示在最前面
    m_Root.AddChild(m_Player);
    m_Renderer->AddChild(m_Player);


    m_PRM = std::make_shared<PhaseResourceManager>();
    m_Renderer->AddChildren(m_PRM->GetChildren());

    //HP display init
    m_HealthDisplay = std::make_shared<ResultText>("HP: " + std::to_string(m_Player->GetHealth()));
    m_HealthDisplay->m_Transform.translation = {-390.0f, -290.0f}; // 左下角微調
    m_Renderer->AddChild(m_HealthDisplay);

    m_SkillDisplay = std::make_shared<ResultText>(
        "SKILL: " + std::to_string(m_Player->GetSkillCharges())
    );
    // 把它放在 HP 之上（往上 30 像素）
    m_SkillDisplay->m_Transform.translation = {-370.0f, -230.0f};
    m_Renderer->AddChild(m_SkillDisplay);

    m_EnemySpawnTimer = std::time(nullptr);
    m_Timer = std::time(nullptr); // Game timer for boss spawn etc.


    // Create Boss instance (initially inactive/invisible)
    m_Boss = std::make_shared<Boss>(glm::vec2(0.0f, 450.0f)); // Spawn boss off-screen top
    m_Renderer->AddChild(m_Boss); // Add to renderer, but it's invisible

    m_ResultText = std::make_shared<ResultText>("YOU WIN!"); // Initialized but not shown
    m_CurrentState = State::UPDATE;
}

// App.cpp (only show修改過的 result() 部分)
void App::result()
{
    if (!m_ResultShown)
    {
        // ——1. 清除所有舊遊戲物件（沿用你原本邏輯）——
        // ——App::result() 首段清場邏輯——
        for (auto& enemy : m_Enemies) {
            m_Renderer->RemoveChild(enemy);
            for (auto& b : enemy->GetBullets()) {
                m_Renderer->RemoveChild(b);
            }
        }
        // 一次把 vector 清空
        m_Enemies.clear();

        // 同理清掉 Boss 的子彈
        for (auto& b : m_Boss->GetBullets())
            m_Renderer->RemoveChild(b);
        m_Boss->GetBullets().clear();
        m_Renderer->RemoveChild(m_Boss);
        m_Renderer->RemoveChild(m_Boss);
        for (auto& b : m_Player->GetBullets())
            m_Renderer->RemoveChild(b);
        for (auto& pup : m_PowerUps)
            m_Renderer->RemoveChild(pup);
        m_PowerUps.clear();
        m_Renderer->RemoveChild(m_Player);
        m_Renderer->RemoveChild(m_PRM->GetChildren()[0]);
        m_Player->SetVisible(false);

        m_SkillDisplay->SetVisible(false);
        m_HealthDisplay->SetVisible(false);

        m_Renderer->Update();


        // ——2. 血量檢查：顯示 GameOver 圖片或關卡結算——
        if (m_Player->GetHealth() <= 0)
        {
            // 顯示大大的 Game Over 圖
            m_GameOverImage = std::make_shared<Util::GameObject>(
                std::make_shared<Util::Image>(RESOURCE_DIR "/entrance/gameover.png"),
                /* z-index */ 100
            );
            m_GameOverImage->m_Transform.translation = {0.0f, 0.0f};
            m_Renderer->AddChild(m_GameOverImage);
        }
        else
        {
            // 顯示菜單背景 + 標題
            m_MenuBackground = std::make_shared<Util::GameObject>(
                std::make_shared<Util::Image>(RESOURCE_DIR "/entrance/background.png"),
                0
            );
            m_MenuBackground->m_Transform.translation = {0.0f, 0.0f};
            m_MenuTitle = std::make_shared<Util::GameObject>(
                std::make_shared<Util::Image>(RESOURCE_DIR "/entrance/title.png"),
                100
            );
            m_MenuTitle->m_Transform.translation = {0, 50};
            m_Renderer->AddChild(m_MenuBackground);
            m_Renderer->AddChild(m_MenuTitle);

            // 關卡結算文字
            std::string info =
                "HP: " + std::to_string(m_Player->GetHealth()) + "\n" +
                "LEVEL: " + std::to_string(m_Level) + "\n" +
                "KILLED: " + std::to_string(m_DefeatedThisLevel) + "\n" +
                "SCORE: " + std::to_string(m_DefeatedThisLevel * 10);
            m_ResultText = std::make_shared<ResultText>(info);
            m_Renderer->AddChild(m_ResultText);
        }

        m_ResultShown = true;
    }

    // 每一幀都要刷新畫面
    m_Renderer->Update();

    // 偵測空白鍵放開後再按下
    if (m_WaitForSpaceRelease)
    {
        if (!Util::Input::IsKeyPressed(Util::Keycode::SPACE))
            m_WaitForSpaceRelease = false;
    }
    else if (Util::Input::IsKeyDown(Util::Keycode::SPACE))
    {
        // ——3. 按下空白鍵，清除所有 result 狀態的 UI——
        if (m_GameOverImage)
        {
            m_Renderer->RemoveChild(m_GameOverImage);
            m_GameOverImage.reset();
        }
        if (m_ResultText)
        {
            m_Renderer->RemoveChild(m_ResultText);
            m_ResultText.reset();
        }
        if (m_MenuBackground)
        {
            m_Renderer->RemoveChild(m_MenuBackground);
            m_MenuBackground.reset();
        }
        if (m_MenuTitle)
        {
            m_Renderer->RemoveChild(m_MenuTitle);
            m_MenuTitle.reset();
        }

        // ——4. 狀態轉換：玩家死了直接結束，否則進下一關或結束——
        if (m_Player->GetHealth() <= 0)
        {
            m_CurrentState = State::END;
        }
        else if (m_Level < MAX_LEVEL)
        {
            m_Level++;
            ResetLevel(); // 清場並重製下一關
            m_CurrentState = State::UPDATE;
        }
        else
        {
            m_CurrentState = State::END;
        }

        // 重置標記，下次再進 result() 時可重新顯示
        m_ResultShown = false;
        m_WaitForSpaceRelease = true;
    }
}


void App::Update()
{
    //TODO: do your things here and delete this line <3

    float halfW = 400.0f; // ctx->GetWindowWidth() * 0.5f;
    float halfH = 300.0f; // ctx->GetWindowHeight() * 0.5f;

    const float speed = 10.0f; // 控制移動速度
    float x = m_Player->GetPosition().x;
    float y = m_Player->GetPosition().y;

    if (Util::Input::IsKeyPressed(Util::Keycode::UP) || Util::Input::IsKeyPressed(Util::Keycode::W))
    {
        if (m_Player->GetPosition().y < halfH)
        {
            y += speed;
        }
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::DOWN) || Util::Input::IsKeyPressed(Util::Keycode::S))
    {
        if (m_Player->GetPosition().y > -halfH)
        {
            y -= speed;
        }
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::LEFT) || Util::Input::IsKeyPressed(Util::Keycode::A))
    {
        if (m_Player->GetPosition().x > -400)
        {
            x -= speed;
        }
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::RIGHT) || Util::Input::IsKeyPressed(Util::Keycode::D))
    {
        if (m_Player->GetPosition().x < halfW)
        {
            x += speed;
        }
    }

    m_Player->SetPosition({x, y});

    auto bullet_cooldown = std::clock();
    if (Util::Input::IsKeyPressed(Util::Keycode::SPACE))
    {
        float threshold;
        if (m_Player->GetPowerUpType() == PowerUpType::PURPLE)
        {
            threshold = 0.1f; // 更快的冷卻時間
        }
        else if (m_Player->GetPowerUpType() == PowerUpType::BLUE)
        {
            threshold = 0.4f; // 默認冷卻時間
        }
        else
        {
            threshold = 0.2f; // RED 的冷卻時間
        }
        // enforce your 0.2s cooldown as before…
        if (static_cast<float>(std::clock() - m_bulletCooldownTimer) / CLOCKS_PER_SEC > threshold)
        {
            m_bulletCooldownTimer = std::clock();
            // **if** you have at least one M charge, fire missiles
            if (m_Player->GetMissileCount())
            {
                m_Player->LaunchMissiles(m_Enemies, m_Renderer.get());
            }

            m_Player->Shoot(m_Enemies);
        }
    }


    if (Util::Input::IsKeyPressed(Util::Keycode::Z))
    {
        // 只在第一次按下時觸發
        if (!m_ZPressedLastFrame && m_Player->GetSkillCharges() > 0)
        {
            // 1️⃣ 清掉所有小兵與他們的子彈
            for (auto& enemy : m_Enemies)
            {
                for (auto& b : enemy->GetBullets())
                    m_Renderer->RemoveChild(b);
                m_Renderer->RemoveChild(enemy);
            }
            m_Enemies.clear();
            // 2️⃣ 扣一次技能次數
            m_Player->UseSkill();
        }
        m_ZPressedLastFrame = true;
    }
    else
    {
        m_ZPressedLastFrame = false;
    }

    // —— 作弊鍵 ——
    // H：切換武器顏色（RED → BLUE → PURPLE → RED）
    if (Util::Input::IsKeyDown(Util::Keycode::H))
    {
        // 你需要在 Character.hpp 裡加一個 getter:
        // PowerUpType GetPowerUpType() const { return m_CurrentPowerUpType; }
        PowerUpType cur = m_Player->GetPowerUpType();
        PowerUpType next;
        switch (cur)
        {
        case PowerUpType::RED: next = PowerUpType::BLUE;
            break;
        case PowerUpType::BLUE: next = PowerUpType::PURPLE;
            break;
        case PowerUpType::PURPLE: next = PowerUpType::RED;
            break;
        default: next = PowerUpType::RED;
            break;
        }
        m_Player->ApplyPowerUp(next);
    }

    // J：加一點血
    if (Util::Input::IsKeyDown(Util::Keycode::J))
    {
        m_Player->modifyHealth(1);
    }

    // K：強化（升級）當前武器一次
    if (Util::Input::IsKeyDown(Util::Keycode::K))
    {
        // 再次對當前種類呼叫 ApplyPowerUp 會讓 m_PowerUpLevel++
        m_Player->ApplyPowerUp(m_Player->GetPowerUpType());
    }

    // L：直接跳到下一關（沒有 boss 就直接 ResetLevel）
    if (Util::Input::IsKeyDown(Util::Keycode::L))
    {
        if (m_Level < MAX_LEVEL)
        {
            m_Level++;
            ResetLevel();
        }
        else
        {
            m_CurrentState = State::RESULT;
        }
    }

    m_Player->Update();

    for (auto& bullet : m_Player->GetBullets())
    {
        if (!bullet->IsInRenderer())
        {
            m_Renderer->AddChild(bullet);
            bullet->MarkAsInRenderer();
        }
        if (!bullet->InBound())
        {
            m_Player->RmBullets(bullet);
            m_Renderer->RemoveChild(bullet);
        }
    }
    if (!m_Boss->IsActive() || m_Boss->GetAttackPhase() == 0)
    {
        m_PRM->ScrollScene();
    }

    float baseEnemySpawnInterval = 1.2f; // Base interval at level 1
    float spawnIntervalDecrement = 0.2f; // How much to decrease interval per level
    float minSpawnInterval = 0.5f; // Minimum spawn interval
    float enemySpawnInterval = std::max(minSpawnInterval,
                                        baseEnemySpawnInterval - (m_Level - 1) * spawnIntervalDecrement);
    auto currentTime_Enemy = std::time(nullptr);

    if (!m_Boss->IsActive() && (std::difftime(currentTime_Enemy, m_EnemySpawnTimer) > enemySpawnInterval))
    {
        int gameScreenWidth = 800;
        int randomX = (std::rand() % (gameScreenWidth - 100)) - (gameScreenWidth / 2 - 50);
        EnemyType type = static_cast<EnemyType>(std::rand() % 7);

        std::shared_ptr<Enemy> newEnemy;
        glm::vec2 spawnPosition = glm::vec2(static_cast<float>(randomX), 400.0f);

        switch (type)
        {
        case EnemyType::STRAIGHT:
            newEnemy = std::make_shared<StraightEnemy>(spawnPosition);
            break;
        case EnemyType::WAVE:
            newEnemy = std::make_shared<WaveEnemy>(spawnPosition);
            break;
        case EnemyType::TRACK:
            newEnemy = std::make_shared<TrackEnemy>(spawnPosition);
            break;
        case EnemyType::ZIGZAG:
            newEnemy = std::make_shared<ZigzagEnemy>(spawnPosition);
            break;
        case EnemyType::CHARGER:
            newEnemy = std::make_shared<ChargerEnemy>(spawnPosition);
            break;
        case EnemyType::RISE:
            // 这里 spawnPosition.x 用随机 X，但 Y 由 RiseEnemy 构造决定
            newEnemy = std::make_shared<RiseEnemy>(
                glm::vec2(spawnPosition.x, 0.0f),
                /*speed*/ 4.0f
            );
            break;
        case EnemyType::RANDOM:
        default:
            newEnemy = std::make_shared<RandomEnemy>(spawnPosition);
            break;
        }
        m_Enemies.push_back(newEnemy);
        m_Renderer->AddChild(newEnemy);
        m_EnemySpawnTimer = currentTime_Enemy;
    }

    for (auto it = m_Enemies.begin(); it != m_Enemies.end();)
    {
        auto& enemy = *it;
        enemy->Update(m_Player->GetPosition());

        auto& enemyBullets = enemy->GetBullets();
        for (auto b_it = enemyBullets.begin(); b_it != enemyBullets.end();)
        {
            auto& bullet = *b_it;
            if (!bullet->IsInRenderer())
            {
                m_Renderer->AddChild(bullet);
                bullet->MarkAsInRenderer();
            }
            if (!bullet->InBound())
            {
                m_Renderer->RemoveChild(bullet);
                b_it = enemyBullets.erase(b_it);
            }
            else
            {
                ++b_it;
            }
        }

        if (enemy->IsOutOfScreen())
        {
            for (auto& bullet : enemy->GetBullets())
            {
                m_Renderer->RemoveChild(bullet);
            }
            m_Renderer->RemoveChild(enemy);
            it = m_Enemies.erase(it);
        }
        else
        {
            ++it;
        }
    }

    std::vector<std::shared_ptr<Enemy>> defeatedEnemies;
    std::vector<std::shared_ptr<Bullet>> playerBulletsToRemove;

    for (auto& bullet : m_Player->GetBullets())
    {
        for (auto& enemy : m_Enemies)
        {
            if (enemy->IsVisible() && bullet->CollidesWith(std::static_pointer_cast<Util::GameObject>(enemy)))
            {
                playerBulletsToRemove.push_back(bullet);
                enemy->TakeDamage(bullet->GetDamage());
                if (!enemy->IsAlive())
                {
                    defeatedEnemies.push_back(enemy);
                }
                break;
            }
        }
    }
    for (auto& bullet : playerBulletsToRemove)
    {
        m_Player->RmBullets(bullet);
        m_Renderer->RemoveChild(bullet);
    }
    for (auto& enemyHit : defeatedEnemies)
    {
        for (auto& bullet : enemyHit->GetBullets())
        {
            m_Renderer->RemoveChild(bullet);
        }
        m_Renderer->RemoveChild(enemyHit);
        m_Enemies.erase(std::remove(m_Enemies.begin(), m_Enemies.end(), enemyHit), m_Enemies.end());
        m_DefeatedThisLevel = m_DefeatedThisLevel + 1;
        if (m_PowerUps.size() < 20)
        {
            if (std::rand() % 2 == 0)
            {
                // 50% chance to drop a power-up
                PowerUpType type = static_cast<PowerUpType>(std::rand() % 3);
                auto pup = std::make_shared<PowerUp>(type, enemyHit->GetPosition(),
                                                     glm::vec2{(std::rand() % 200 - 100) / 100.0f, 2.0f});
                m_PowerUps.push_back(pup);
                m_Renderer->AddChild(pup);
            }
            float r = static_cast<float>(std::rand()) / (RAND_MAX + 1.0f);
            if (r < 0.20f)
            {
                PowerUpType special_type;
                if (r < 0.05f)
                {
                    special_type = PowerUpType::H; // H
                }
                else if (r < 0.10f)
                {
                    special_type = PowerUpType::M; // M
                }
                else if (r < 0.15f)
                {
                    special_type = PowerUpType::P; // P
                }
                else if (r < 0.20f)
                {
                    special_type = PowerUpType::B;
                }


                glm::vec2 vel{(std::rand() % 200 - 100) / 100.0f, 2.0f};
                auto specialPup = std::make_shared<PowerUp>(special_type, enemyHit->GetPosition(), vel);
                m_PowerUps.push_back(specialPup);
                m_Renderer->AddChild(specialPup);
            }
        }
    }

    bool isPlayerHitThisFrame = false;

    for (auto& enemy : m_Enemies)
    {
        if (m_Player->IfCollides(std::static_pointer_cast<Util::GameObject>(enemy)))
        {
            auto currentTime = std::time(nullptr);
            if (currentTime - m_collisionTimer >= 3)
            {
                LOG_INFO("Player collided with enemy at position ({}, {})", enemy->GetPosition().x,
                         enemy->GetPosition().y);
                m_Player->modifyHealth(-1);
                m_Player->SetPosition({-0.0f, -200.0f});
                m_Player->ResetPowerUp();
                m_Player->SetMissileCount(false);
                m_Player->ResetSkillCharges();
                LOG_INFO("Player hit! Skill charges reset to 3");
                isPlayerHitThisFrame = true;
                m_collisionTimer = currentTime;
            }
            if (isPlayerHitThisFrame) break;
        }
        if (isPlayerHitThisFrame) break;
        for (auto b_it = enemy->GetBullets().begin(); b_it != enemy->GetBullets().end();)
        {
            auto& bullet = *b_it;
            if (m_Player->IfCollides(bullet))
            {
                auto currentTime = std::time(nullptr);
                if (currentTime - m_collisionTimer >= 3)
                {
                    LOG_INFO("Player collided with enemy bullet at position ({}, {})", bullet->GetPosition().x,
                             bullet->GetPosition().y);
                    m_Player->modifyHealth(-1);
                    m_Player->ResetPowerUp();
                    m_Player->SetPosition({0.0f, -200.0f});
                    m_Player->SetMissileCount(false);
                    isPlayerHitThisFrame = true;
                    m_collisionTimer = currentTime;
                    m_DefeatedThisLevel += 1;

                    m_Renderer->RemoveChild(bullet);
                    b_it = enemy->GetBullets().erase(b_it);
                }
                else { ++b_it; }
                if (isPlayerHitThisFrame) break;
            }
            else
            {
                ++b_it;
            }
        }
        if (isPlayerHitThisFrame) break;
    }


    auto currentTime_Boss = std::time(nullptr);

    if (!m_Boss->IsActive() && !m_Boss->IsVisible() && (currentTime_Boss - m_Timer >= BOSS_SPAWN_TIME))
    {
        m_Boss->Activate();
        LOG_INFO("Boss has been activated.");
    }
    if (m_Boss->IsActive() && !m_Boss->IsDead())
    {
        m_Boss->Update(m_Player->GetPosition());

        auto spawnedMinions = m_Boss->GetSpawnedMinions();
        if (!spawnedMinions.empty())
        {
            for (const auto& minion : spawnedMinions)
            {
                // Add the minion to the main enemy list. It will now be updated,
                // rendered, and checked for collisions by the App's main loop.
                m_Enemies.push_back(minion);
                m_Renderer->AddChild(minion);
            }
        }

        auto& bossBullets = m_Boss->GetBullets();
        for (auto b_it = bossBullets.begin(); b_it != bossBullets.end();)
        {
            auto& bullet = *b_it;
            if (!bullet->IsInRenderer())
            {
                m_Renderer->AddChild(bullet);
                bullet->MarkAsInRenderer();
            }
            if (!bullet->InBound())
            {
                m_Renderer->RemoveChild(bullet);
                b_it = bossBullets.erase(b_it);
            }
            else
            {
                ++b_it;
            }
        }


        std::vector<std::shared_ptr<Bullet>> playerBulletsHittingBossToRemove;
        for (auto& bullet : m_Player->GetBullets())
        {
            if (bullet->CollidesWith(std::static_pointer_cast<Util::GameObject>(m_Boss)))
            {
                playerBulletsHittingBossToRemove.push_back(bullet);
                m_Boss->TakeDamage(bullet->GetDamage());
            }
        }
        for (auto& bullet : playerBulletsHittingBossToRemove)
        {
            m_Player->RmBullets(bullet);
            m_Renderer->RemoveChild(bullet);
        }

        if (!isPlayerHitThisFrame && m_Player->IfCollides(std::static_pointer_cast<Util::GameObject>(m_Boss)))
        {
            auto currentTime = std::time(nullptr);
            if (currentTime - m_collisionTimer >= 3)
            {
                LOG_INFO("Player collided with Boss body.");
                m_Player->modifyHealth(-1);
                m_Player->ResetPowerUp();
                m_Player->SetPosition({-0.0f, -200.0f});
                isPlayerHitThisFrame = true;
                m_collisionTimer = currentTime;
            }
        }

        if (!isPlayerHitThisFrame)
        {
            for (auto b_it = m_Boss->GetBullets().begin(); b_it != m_Boss->GetBullets().end();)
            {
                auto& bullet = *b_it;
                if (m_Player->IfCollides(bullet))
                {
                    auto currentTime = std::time(nullptr);
                    if (currentTime - m_collisionTimer >= 3)
                    {
                        LOG_INFO("Player collided with Boss bullet.");
                        m_Player->modifyHealth(-1);
                        m_Player->ResetPowerUp();
                        m_Player->SetPosition({-0.0f, -200.0f});
                        isPlayerHitThisFrame = true;
                        m_collisionTimer = currentTime;
                        m_Renderer->RemoveChild(bullet);
                        b_it = m_Boss->GetBullets().erase(b_it);
                    }
                    else { ++b_it; }
                    if (isPlayerHitThisFrame) break;
                }
                else
                {
                    ++b_it;
                }
            }
        }
    }

    if (isPlayerHitThisFrame && !m_Boss->IsActive())
    {
        for (auto& enemy : m_Enemies)
        {
            for (auto& bullet : enemy->GetBullets()) m_Renderer->RemoveChild(bullet);
            m_Renderer->RemoveChild(enemy);
        }
        m_Enemies.clear();
        LOG_INFO("All non-boss enemies cleared due to player hit.");
    }

    if (m_Boss->IsActive() && m_Boss->IsDead())
    {
        m_Renderer->RemoveChild(m_Boss);

        m_CurrentState = State::RESULT;
        m_ResultShown = false; // 讓 result() 重新執行裡面的「只一次」邏輯
        m_WaitForSpaceRelease = true; // 重置空白鍵偵測
    }
    else if (m_Player->GetHealth() <= 0)
    {
        LOG_INFO("Player defeated! YOU LOSE!");
        // m_ResultText->SetText("YOU LOSE!");
        m_CurrentState = State::RESULT;
    }

    for (auto& pup : m_PowerUps)
    {
        pup->Update();
    }
    m_PowerUps.erase(std::remove_if(m_PowerUps.begin(), m_PowerUps.end(),
                                    [&](const std::shared_ptr<PowerUp>& pup)
                                    {
                                        if (m_Player->IfCollides(pup))
                                        {
                                            if (pup->GetType() == PowerUpType::PURPLE ||
                                                pup->GetType() == PowerUpType::RED ||
                                                pup->GetType() == PowerUpType::BLUE)
                                            {
                                                m_Player->ApplyPowerUp(pup->GetType());
                                            }
                                            else
                                            {
                                                m_Player->ApplySpecialPowerUp(pup->GetType());
                                            }


                                            m_Renderer->RemoveChild(pup);
                                            return true;
                                        }
                                        if (pup->IsOutOfScreen())
                                        {
                                            m_Renderer->RemoveChild(pup);
                                            return true;
                                        }
                                        return false;
                                    }), m_PowerUps.end());

    // 更新血量顯示
    m_HealthDisplay->SetText("HP: " + std::to_string(m_Player->GetHealth()));

    m_SkillDisplay->SetText(
        "SKILL: " + std::to_string(m_Player->GetSkillCharges()));

    m_Renderer->Update();
    /*
     * Do not touch the code below as they serve the purpose for
     * closing the window.
     */
    if (Util::Input::IsKeyUp(Util::Keycode::ESCAPE) ||
        Util::Input::IfExit())
    {
        m_CurrentState = State::END;
    }
}

void App::ResetLevel()
{
    // 1. 移除所有敵人及其子彈
    for (auto& enemy : m_Enemies)
    {
        m_Renderer->RemoveChild(enemy);
        for (auto& b : enemy->GetBullets())
        {
            m_Renderer->RemoveChild(b);
        }
    }
    m_Enemies.clear();

    // 2. 移除玩家的所有子彈
    for (auto& b : m_Player->GetBullets())
    {
        m_Renderer->RemoveChild(b);
    }
    m_Player->GetBullets().clear();

    // 3. 移除所有道具
    for (auto& pup : m_PowerUps)
    {
        m_Renderer->RemoveChild(pup);
    }
    m_PowerUps.clear();

    // 4. 移除 Boss
    if (m_Boss)
    {
        m_Renderer->RemoveChild(m_Boss);
        m_Boss.reset();
    }

    // 5. 移除玩家本體
    m_Renderer->RemoveChild(m_Player);

    // 6. 移除背景節點（PhaseResourceManager 的 child）
    if (m_PRM)
    {
        for (auto& child : m_PRM->GetChildren())
        {
            m_Renderer->RemoveChild(child);
        }
        m_PRM.reset();
    }

    // ——以上對應 result() 的清除邏輯——

    // 7. 重建玩家
    m_Player->SetPosition({-112.5f, -140.5f});
    m_Player->SetVisible(true);
    m_Renderer->AddChild(m_Player);

    // 8. 重建場景背景
    m_PRM = std::make_shared<PhaseResourceManager>();
    m_Renderer->AddChildren(m_PRM->GetChildren());

    // 9. 重建（隱藏狀態的）Boss
    m_Boss = std::make_shared<Boss>(glm::vec2(100, 350));
    m_Boss->SetLevel(m_Level);
    m_Boss->SetVisible(false);
    m_Renderer->AddChild(m_Boss);

    // 10. 重置計時器
    m_EnemySpawnTimer = std::time(nullptr);
    m_Timer = std::time(nullptr);

    //重製變數
    m_HealthDisplay->SetVisible(true);
    m_SkillDisplay->SetVisible(true);

    // 在 result() 裡，按下 SPACE 要進關卡前：
    m_HealthDisplay->SetVisible(true);
    m_SkillDisplay->SetVisible(true);
}


void App::End()
{ // NOLINT(this method will mutate members in the future)

    LOG_TRACE("End");
    exit(0); // ✅ 或是切換回主選單（延伸功能）
}

