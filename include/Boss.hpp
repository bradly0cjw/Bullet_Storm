#ifndef BOSS_HPP
#define BOSS_HPP

#include "Enemy.hpp" // Base class is now the refactored Enemy
#include <vector>    // For std::vector
#include <memory>    // For std::shared_ptr
#include <chrono>    // For std::chrono

class Boss : public Enemy {
public:
    // Constants for attack patterns
    static constexpr int PHASES_PER_LEVEL = 3; // Note: Level 2 will not use these phases
    static constexpr float PHASE_DURATION = 15.0f; // Duration in seconds for each phase

    Boss(const glm::vec2& position);

    void Update(glm::vec2 playerPosition) override;
    void Shoot(glm::vec2 playerPosition) override; // Boss definitely has custom shooting

    void SetLevel(int level); // Method to set boss level
    int GetCurrentLevel() const { return m_CurrentLevel; }

    void TakeDamage(int amount); // Changed from int to int amount
    bool IsDead() const;

    // IsVisible is inherited from Util::GameObject.
    // SetVisible is also inherited.

    void Activate();
    bool IsActive() const { return m_Active; }

    // Hitbox getters (members are now private)
    float GetHitboxWidth() const { return m_HitboxWidth_Private; }
    float GetHitboxHeight() const { return m_HitboxHeight_Private; }

    int GetAttackPhase() const { return m_AttackPhase; }

    std::vector<std::shared_ptr<Enemy>> GetSpawnedMinions();
    // const std::vector<std::shared_ptr<Enemy>>& GetMinions() const { return m_Minions; }
    // void ClearMinions(); // To remove minions, e.g. when boss dies or resets

private:
    // Different attack patterns based on level and phase
    void ExecuteAttackPattern(int level, int phase, glm::vec2 playerPosition);

    // Level 1 attack patterns
    void Level1Phase1(glm::vec2 playerPosition);
    void Level1Phase2(glm::vec2 playerPosition);
    void Level1Phase3(glm::vec2 playerPosition);

    // Level 2 new continuous attack
    void Level2ContinuousAttack(glm::vec2 playerPosition);

    // Level 3 attack patterns
    // void Level3Phase1(glm::vec2 playerPosition);
    // void Level3Phase2(glm::vec2 playerPosition);
    // void Level3Phase3(glm::vec2 playerPosition);

    // Minion spawning helpers
    bool CanSpawnMinion();
    void SpawnChargerMinion(const glm::vec2& playerPosition); // playerPosition might be useful for spawning logic

    int m_Health; // Renamed from m_HitPoints for consistency if Enemy uses m_HitPoints
    bool m_Active; // Whether boss logic (movement, shooting) is active

    int m_CurrentLevel; // Current boss level
    int m_MaxLevel; // Maximum boss level

    // Store hitbox dimensions privately
    float m_HitboxWidth_Private;
    float m_HitboxHeight_Private;

    // For attack patterns (Level 2 will not use m_AttackPhase or m_PhaseTimer in the same way)
    int m_AttackPhase;
    float m_PhaseTimer;

    // Minion management
    std::vector<std::shared_ptr<Enemy>> m_NewlySpawnedMinions;
    // std::vector<std::shared_ptr<Enemy>> m_Minions;
    float m_MinionSpawnIntervalSeconds; // Interval for spawning minions, e.g. 5 seconds
    std::chrono::steady_clock::time_point m_LastMinionSpawnTime;
};
#endif //BOSS_HPP
