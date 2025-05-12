#ifndef BOSS_HPP
#define BOSS_HPP

#include "Enemy.hpp" // Base class is now the refactored Enemy

class Boss : public Enemy {
public:
    Boss(const glm::vec2& position);

    void Update(glm::vec2 playerPosition) override;
    void Shoot(glm::vec2 playerPosition) override; // Boss definitely has custom shooting

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
    int m_Health;
    bool m_Active; // Whether boss logic (movement, shooting) is active

    // Store hitbox dimensions privately
    float m_HitboxWidth_Private;
    float m_HitboxHeight_Private;

    // Example: For more complex attack patterns
    int m_AttackPhase;
    float m_PhaseTimer;
};
#endif //BOSS_HPP