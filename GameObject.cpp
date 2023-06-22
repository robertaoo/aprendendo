#include "GameObject.hpp"

// Constructor
GameObject::GameObject(std::string name, const std::string& imagePath, float x, float y, float scaleX, float scaleY)
{
    // Load the texture
    if (!m_texture.loadFromFile(imagePath))
    {
        // Error
    }

    m_name = name;

    // Creates Sprite
    m_sprite = sf::Sprite(m_texture);

    sf::Vector2u sizeSprite = m_texture.getSize();
    m_collider = BoxCollider(x, y, sizeSprite.x * scaleX, sizeSprite.y * scaleY);

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

BoxCollider *GameObject::getCollider() {
    return &m_collider;
}

sf::Vector2f GameObject::getPosition() {
    return m_transform.position;
}

std::string GameObject::getName() {
    return m_name;
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