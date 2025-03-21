#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include "Util/Logger.hpp"
#include "Util/GameObject.hpp"
#include "Bullet.hpp"

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

    void Shoot();  // 新增射擊
    void UseSkill();  // 新增技能
    void Update();  // 更新所有子彈


    std::vector<std::shared_ptr<Bullet>> GetBullets() { return m_Bullets; } // 取得子彈列表

    void RmBullets(const std::shared_ptr<Bullet>& bullet) {
        auto it = std::find(m_Bullets.begin(), m_Bullets.end(), bullet);
        if (it != m_Bullets.end()) {
            m_Bullets.erase(it);  // Remove the shared_ptr from m_Bullets
        }
    }

    // TODO: Implement the collision detection
    [[nodiscard]] bool IfCollides(const std::shared_ptr<Character>& other) const {
        auto thisPosition = GetPosition();
        auto otherPosition = other->GetPosition();
        bool collitionx = thisPosition.x < otherPosition.x + thisPosition.r && thisPosition.x + thisPosition.r >otherPosition.x;
        bool collitiony = thisPosition.y < otherPosition.y + thisPosition.s && thisPosition.y + thisPosition.s >otherPosition.y;
        return collitionx && collitiony;
    }

    // TODO: Add and implement more methods and properties as needed to finish Giraffe Adventure.

private:
    void ResetPosition() { m_Transform.translation = {0, 0}; }

    std::string m_ImagePath;
    std::vector<std::shared_ptr<Bullet>> m_Bullets;
};


#endif //CHARACTER_HPP
