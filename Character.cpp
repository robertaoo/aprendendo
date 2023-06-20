#include "Character.hpp"

// Constructor
Character::Character(const std::string& imagePath, float x, float y, float scaleX, float scaleY, float speed, float jspeed)
    : GameObject(imagePath, x, y, scaleX, scaleY)
{
    m_speed = speed;
    jumpSpeed = jspeed;
}

// Destructor
Character::~Character()
{
}

// Start
void Character::Start()
{
}

// Update
void Character::Update(float deltaTime)
{
    // Update the position
    Walk(deltaTime);

    // Update the sprite position
    m_sprite.setPosition(m_transform.position);
}

// Walk
void Character::Walk(float deltaTime)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        m_transform.position.x += deltaTime * m_speed;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        m_transform.position.x -= deltaTime * m_speed;
    }
}

void Character::Jump(float deltaTime)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
    // Aplica a velocidade vertical ao personagem
    m_transform.position.y += jumpSpeed * deltaTime;
    }
}



  bool Character::CheckCollision(){

    // Obtém a bounding box do personagem
    sf::FloatRect characterBounds = m_sprite.getGlobalBounds();

    // Loop através das superfícies ou objetos de colisão
    for (const auto& surface : surfaces)
    {
        // Obtém a bounding box da superfície
        sf::FloatRect surfaceBounds = surface.getGlobalBounds();

        // Verifica se ocorre uma colisão
        if (characterBounds.intersects(surfaceBounds))
        {
            // Colisão detectada
            return true;
        }
    }

    // Nenhuma colisão detectada
    //return false;
} 


// Gravity
//void Character::Gravity(float deltaTime)
//{
  //  if (CheckCollision())
  //  m_transform.position.y += deltaTime * m_speed;
//}
