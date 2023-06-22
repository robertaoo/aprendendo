// GameObject class definition
// A GameObject has a sprite image path, a position (x, y) and scale (x, y)
// Also has two functions, Start() and Update(deltaTime)

#pragma once

#include <SFML/Graphics.hpp>

#include "BoxCollider.hpp"
#include <string>

struct Transform {
    sf::Vector2f position;
    sf::Vector2f scale;
};

class GameObject
{
public:
    GameObject(std::string name, const std::string& imagePath, float x, float y, float scaleX, float scaleY);
    virtual ~GameObject();

    sf::Vector2f getPosition();
    BoxCollider *getCollider();
    std::string getName();

    virtual void Start();
    virtual void Update(float deltaTime);

    void Draw(sf::RenderWindow& window);

protected:
    sf::Sprite m_sprite;
    sf::Texture m_texture;

    Transform m_transform;

    BoxCollider m_collider;

    std::string m_name;
}; 