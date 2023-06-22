// Character class header file
// A character inherits from GameObject
// A character has a speed and the functions Walk, Jump, CheckCollision and also the inherited Start and Update functions

#pragma once

#include "GameObject.hpp"

class Character : public GameObject
{
public:
    Character(std::string name, const std::string& imagePath, float x, float y, float scaleX, float scaleY, float speed);

    ~Character();

    void Start() override;
    void Update(float deltaTime) override;

    void Walk(float deltaTime);
    void Jump(float deltaTime);
    //void Gravity(float deltaTime);

    void DoCollision(sf::Vector2f initialPos);

private:
    float m_speed;

    bool m_isJumping;
    float m_jumpHeight;
    float m_jumpSpeed;
    float m_originalY;
};  