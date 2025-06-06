#ifndef BOSS_HPP
#define BOSS_HPP

#include "Enemy.hpp" // Base class is now the refactored Enemy

class Boss : public Enemy {
public:
    // Constants for attack patterns
    static constexpr int PHASES_PER_LEVEL = 3;
    static constexpr float PHASE_DURATION = 15.0f; // Duration in seconds for each phase

    Boss(const glm::vec2& position);

    void Update(glm::vec2 playerPosition) override;
    void Shoot(glm::vec2 playerPosition) override; // Boss definitely has custom shooting

    void SetLevel(int level); // Method to set boss level
    int GetCurrentLevel() const { return m_CurrentLevel; }

    void TakeDamage(int amount);
    bool IsDead() const;

    // IsVisible is inherited from Util::GameObject.
    // SetVisible is also inherited.

    void Activate();
    bool IsActive() const { return m_Active; }

    // Hitbox getters (members are now private)
    float GetHitboxWidth() const { return m_HitboxWidth_Private; }
    float GetHitboxHeight() const { return m_HitboxHeight_Private; }

private:
    // Different attack patterns based on level and phase
    void ExecuteAttackPattern(int level, int phase, glm::vec2 playerPosition);

    // Level 1 attack patterns
    void Level1Phase1(glm::vec2 playerPosition);
    void Level1Phase2(glm::vec2 playerPosition);
    void Level1Phase3(glm::vec2 playerPosition);

    // Level 2 attack patterns
    void Level2Phase1(glm::vec2 playerPosition);
    void Level2Phase2(glm::vec2 playerPosition);
    void Level2Phase3(glm::vec2 playerPosition);

    // Level 3 attack patterns
    void Level3Phase1(glm::vec2 playerPosition);
    void Level3Phase2(glm::vec2 playerPosition);
    void Level3Phase3(glm::vec2 playerPosition);

    int m_Health;
    bool m_Active; // Whether boss logic (movement, shooting) is active

    int m_CurrentLevel;   // Current boss level
    int m_MaxLevel;       // Maximum boss level

    // Store hitbox dimensions privately
    float m_HitboxWidth_Private;
    float m_HitboxHeight_Private;

    // For attack patterns
    int m_AttackPhase;
    float m_PhaseTimer;
};
#endif //BOSS_HPP
