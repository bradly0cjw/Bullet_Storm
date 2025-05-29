#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include "Util/Logger.hpp"
#include "Util/GameObject.hpp"
#include "Bullet.hpp"
#include "PowerUp.hpp"
#include "Enemy.hpp"      // for std::shared_ptr<Enemy>
#include "Util/Renderer.hpp" // for Util::Renderer
#include "ShootingStrategy.hpp"

class Character : public Util::GameObject {
public:
    explicit Character(const std::string& ImagePath);

    Character(const Character&) = delete;

    Character(Character&&) = delete;

    Character& operator=(const Character&) = delete;

    Character& operator=(Character&&) = delete;

    [[nodiscard]] const std::string& GetImagePath() const { return m_ImagePath; }

    [[nodiscard]] const glm::vec2& GetPosition() const { return m_Transform.translation; }

    [[nodiscard]] bool GetVisibility() const { return m_Visible; }

    void SetImage(const std::string& ImagePath);

    void SetPosition(const glm::vec2& Position) { m_Transform.translation = Position; }

    void Shoot(const std::vector<std::shared_ptr<Enemy>>& enemies);  // 新增射擊
    void UseSkill();  // 新增技能
    void Update();  // 更新所有子彈

    std::vector<std::shared_ptr<Bullet>> GetBullets() { return m_Bullets; } // 取得子彈列表

    void RmBullets(const std::shared_ptr<Bullet>& bullet);

    bool IfCollides(const std::shared_ptr<Util::GameObject> &other) const;

    // TODO: Implement the collision detection
//    [[nodiscard]] bool IfCollides(const std::shared_ptr<Character>& other) const {
//        auto thisPosition = GetPosition();
//        auto otherPosition = other->GetPosition();
//        bool collitionx = thisPosition.x < otherPosition.x + thisPosition.r && thisPosition.x + thisPosition.r >otherPosition.x;
//        bool collitiony = thisPosition.y < otherPosition.y + thisPosition.s && thisPosition.y + thisPosition.s >otherPosition.y;
//        return collitionx && collitiony;
//    }

    // TODO: Add and implement more methods and properties as needed to finish Giraffe Adventure.
    void SetHealth(int health) { m_health = health; }

    int GetHealth() const { return m_health; }

    void modifyHealth(int health) { m_health += health; }

    void ApplyPowerUp(PowerUpType power_up);

    void ResetPowerUp();

    void ApplySpecialPowerUp(PowerUpType type) ;

    void LaunchMissiles(const std::vector<std::shared_ptr<Enemy>>& enemies, Util::Renderer* renderer);
    bool GetMissileCount() const { return isMissile; }
    void SetMissileCount(bool isM) { isMissile = isM; }
    int  GetSkillCharges() const  { return m_skillCharges; }
    void DecSkillCharge()         { if (m_skillCharges > 0) --m_skillCharges; }
    void IncSkillCharge()         { ++m_skillCharges; }
    void ResetSkillCharges()      { m_skillCharges = 3; }
    std::shared_ptr<Enemy> FindNearestVisibleEnemy(const glm::vec2& start, const std::vector<std::shared_ptr<Enemy>>& enemies) const;

private:
    void ResetPosition() { m_Transform.translation = {0, 0}; }
    void UpdateShootingStrategy(); // Helper to set strategy based on current power-up state

    // Finds the nearest visible enemy to the given position

    int m_health = 3;
    bool isMissile = false;
    int m_skillCharges = 3;       // 最多三次
    std::tuple<int, int> m_skill = std::make_tuple(0, 0);
    std::string m_ImagePath;
    std::vector<std::shared_ptr<Bullet>> m_Bullets;

    PowerUpType m_CurrentPowerUpType = PowerUpType::RED; // Default power-up type
    int m_PowerUpLevel = 1; // Default power-up level
    std::unique_ptr<ShootingStrategy> m_ShootingStrategy;
};


#endif //CHARACTER_HPP
