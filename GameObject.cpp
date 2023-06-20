#include "GameObject.hpp"

// Constructor
GameObject::GameObject(const std::string& imagePath, float x, float y, float scaleX, float scaleY)
{
    // Load the texture
    if (!m_texture.loadFromFile(imagePath))
    {
        // Error
    }

    // Creates Sprite
    m_sprite = sf::Sprite(m_texture);

    // Set the sprite position
    m_sprite.setPosition(x, y);

    // Set the sprite scale
    m_sprite.setScale(scaleX, scaleY);

    // Set the transform position
    m_transform.position = sf::Vector2f(x, y);

    // Set the transform scale
    m_transform.scale = sf::Vector2f(scaleX, scaleY);
}

// Desctructor
GameObject::~GameObject()
{
}

// Start
void GameObject::Start()
{
}

// Update
void GameObject::Update(float deltaTime)
{
}


// Draw
void GameObject::Draw(sf::RenderWindow& window)
{
    window.draw(m_sprite);
}