#include "App.hpp"

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


void App::Start() {
    LOG_TRACE("Start");
    Util::Logger::Init();
    Util::Logger::SetLevel(Util::Logger::Level::DEBUG);  // 👈 設定最低 Log Level
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // Seed RNG once
    LOG_INFO("Game Started!");




    // 1️⃣ 創建玩家角色 (戰機)
    m_Player = std::make_shared<Character>(RESOURCE_DIR "/character/test_plane.png");
    m_Player->SetPosition({-112.5f, -140.5f});  // 螢幕中央
    m_Player->SetZIndex(50); // 讓玩家顯示在最前面
    m_Root.AddChild(m_Player);



    // 3️⃣ 初始化 Renderer 並加入根物件
    m_Renderer = std::make_unique<Util::Renderer>(
            std::vector<std::shared_ptr<Util::GameObject>>{std::make_shared<Util::GameObject>(m_Root)}
    );

    m_PRM = std::make_shared<PhaseResourceManager>();
    m_Renderer->AddChildren(m_PRM->GetChildren());


    m_EnemySpawnTimer = std::time(nullptr);
    m_Timer = std::time(nullptr); // Game timer for boss spawn etc.

    // Create Boss instance (initially inactive/invisible)
    m_Boss = std::make_shared<Boss>(glm::vec2(0.0f, 450.0f)); // Spawn boss off-screen top
    m_Renderer->AddChild(m_Boss); // Add to renderer, but it's invisible

    m_ResultText = std::make_shared<ResultText>("YOU WIN!"); // Initialized but not shown

    m_CurrentState = State::UPDATE;
}

void App::result() {
    for (auto& enemy : m_Enemies) {
        m_Renderer->RemoveChild(enemy);
        //remove bullet which enemy shooted
        for (auto& bullet : enemy->GetBullets()) {
            m_Renderer->RemoveChild(bullet);
            LOG_INFO("Enemy Bullet removed at position ({}, {})", bullet->GetPosition().x, bullet->GetPosition().y);
        }
    }

    m_Renderer->RemoveChild(m_Boss);

    m_Enemies.clear();

    for (auto& bullet : m_Player->GetBullets()) {
        m_Renderer->RemoveChild(bullet);
    }

    for (auto &pup : m_PowerUps) {
        m_Renderer->RemoveChild(pup);
    }

    m_PowerUps.clear();
    m_Renderer->RemoveChild(m_Player);
    m_Renderer->RemoveChild(m_PRM->GetChildren()[0]);
    m_Player->SetVisible(false);


    if (!m_ResultShown) {
        //LOG_INFO("test");
        m_Renderer->AddChild(m_ResultText);
        //m_ResultShown = true;
        m_Renderer->Update();

    }

    // 每一幀都會檢查一次這段
    if (m_WaitForSpaceRelease) {
        if (!Util::Input::IsKeyPressed(Util::Keycode::SPACE)) {
            m_WaitForSpaceRelease = false;
        }
    } else {
        if (Util::Input::IsKeyDown(Util::Keycode::SPACE)) {
            m_CurrentState = State::END;
        }
    }


}

void App::Update() {
    const float speed = 10.0f;
    float x = m_Player->GetPosition().x;
    float y = m_Player->GetPosition().y;

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

    m_Player->SetPosition({x, y});

    auto bullet_cooldown = std::clock();
    if (Util::Input::IsKeyPressed(Util::Keycode::SPACE)) {
        if (static_cast<float>(bullet_cooldown - m_bulletCooldownTimer) / CLOCKS_PER_SEC > 0.2f)
        {
            m_bulletCooldownTimer = bullet_cooldown;
            m_Player->Shoot();
        }
    }

    if (Util::Input::IsKeyPressed(Util::Keycode::Z)) {
        m_Player->UseSkill();
    }

    m_Player->Update();

    for (auto &bullet: m_Player->GetBullets()) {
        if (!bullet->IsInRenderer()) {
            m_Renderer->AddChild(bullet);
            bullet->MarkAsInRenderer();
        }
        if (!bullet->InBound()) {
            m_Player->RmBullets(bullet);
            m_Renderer->RemoveChild(bullet);
        }
    }

    m_PRM->ScrollScene();

    const float enemySpawnInterval = 2.5f;
    auto currentTime_Enemy = std::time(nullptr);

    if (!m_Boss->IsActive() && (std::difftime(currentTime_Enemy, m_EnemySpawnTimer) > enemySpawnInterval))
    {
        int gameScreenWidth = 800;
        int randomX = (std::rand() % (gameScreenWidth - 100)) - (gameScreenWidth / 2 - 50);
        EnemyType type = static_cast<EnemyType>(std::rand() % 5);

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
            if (!bullet->InBound()) {
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

    std::vector<std::shared_ptr<Enemy>> enemiesToRemove;
    std::vector<std::shared_ptr<Bullet>> playerBulletsToRemove;

    for (auto& bullet : m_Player->GetBullets())
    {
        for (auto& enemy : m_Enemies)
        {
            if (enemy->IsVisible() && bullet->CollidesWith(std::static_pointer_cast<Util::GameObject>(enemy)))
            {
                playerBulletsToRemove.push_back(bullet);
                enemiesToRemove.push_back(enemy);
                break;
            }
        }
    }
    for (auto& bullet : playerBulletsToRemove)
    {
        m_Player->RmBullets(bullet);
        m_Renderer->RemoveChild(bullet);
    }
    for (auto& enemyHit : enemiesToRemove)
    {
        for (auto& bullet : enemyHit->GetBullets())
        {
            m_Renderer->RemoveChild(bullet);
        }
        m_Renderer->RemoveChild(enemyHit);
        m_Enemies.erase(std::remove(m_Enemies.begin(), m_Enemies.end(), enemyHit), m_Enemies.end());
        if (std::rand() % 2 == 0)
        {
            PowerUpType type = static_cast<PowerUpType>(std::rand() % 3);
            auto pup = std::make_shared<PowerUp>(type, enemyHit->GetPosition(),
                                                 glm::vec2{(std::rand() % 200 - 100) / 100.0f, 2.0f});
            m_PowerUps.push_back(pup);
            m_Renderer->AddChild(pup);
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
                    isPlayerHitThisFrame = true;
                    m_collisionTimer = currentTime;
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
    if (!m_Boss->IsActive() && !m_Boss->IsVisible() && (currentTime_Boss - m_Timer >= 15))
    {
        m_Boss->Activate();
        m_Enemies.clear();
        for (auto& enemy : m_Enemies)
        {
            m_Renderer->RemoveChild(enemy);
            for (auto& bullet : enemy->GetBullets()) m_Renderer->RemoveChild(bullet);
        }
        LOG_INFO("Boss has been activated. Normal enemies cleared.");
    }

    if (m_Boss->IsActive() && !m_Boss->IsDead())
    {
        m_Boss->Update(m_Player->GetPosition());

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
                m_Boss->TakeDamage(1);
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
        LOG_INFO("Boss defeated! YOU WIN!");
        m_ResultText->SetText("YOU WIN!");
        m_CurrentState = State::RESULT;
    }
    else if (m_Player->GetHealth() <= 0)
    {
        LOG_INFO("Player defeated! YOU LOSE!");
        m_ResultText->SetText("YOU LOSE!");
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
                                            m_Player->ApplyPowerUp(pup->GetType());
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
    exit(0);  // ✅ 或是切換回主選單（延伸功能）
}
