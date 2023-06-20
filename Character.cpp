#include "Character.hpp"

// Constructor
Character::Character(const std::string& imagePath, float x, float y, float scaleX, float scaleY, float speed)
    : GameObject(imagePath, x, y, scaleX, scaleY)
{
     m_speed = speed;
    m_isJumping = false;
    m_jumpHeight = y - 200.0f; // Altura máxima do pulo (o dobro da altura atual)
    m_jumpSpeed = -800.0f; // Velocidade de subida do pulo
    m_originalY = y; // Altura original do personagem
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
    Jump(deltaTime);
    
    // Update the sprite position
    m_sprite.setPosition(m_transform.position);
}

// Walk
void Character::Walk(float deltaTime)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        m_transform.position.x += deltaTime * m_speed;

        // Verifica se a posição ultrapassou o limite da janela na direita
        if (m_transform.position.x > WindowWidth - m_sprite.getGlobalBounds().width)
        {
            m_transform.position.x = WindowWidth - m_sprite.getGlobalBounds().width;
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        m_transform.position.x -= deltaTime * m_speed; // transforma posicao 
        

        // Verifica se a posição ultrapassou o limite da janela na esquerda
        if (m_transform.position.x < 0.0f)
        {
            m_transform.position.x = 0.0f;
        }
    }
}

void Character::Jump(float deltaTime)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        if (!m_isJumping)
        {
            m_isJumping = true;
            // Inicie o pulo definindo a velocidade inicial para cima
            m_jumpSpeed = -800.0f;
        }
    }

    if (m_isJumping)
    {
        // Atualize a posição vertical durante o pulo
        m_transform.position.y += m_jumpSpeed * deltaTime;

        // Atualize a velocidade do pulo considerando a gravidade (aumente a velocidade com o tempo)
        m_jumpSpeed += 2000.0f * deltaTime;

        // Verifique se atingiu a altura máxima do pulo ou está abaixo da altura original
        if (m_transform.position.y >= m_originalY || m_transform.position.y <= m_jumpHeight)
        {
            // Termine o pulo e retorne à altura original
            m_isJumping = false;
            m_transform.position.y = m_originalY;
        }
    }
}
// Gravity
/*void Character::Gravity(float deltaTime)
{
    if (CheckCollision())
    m_transform.position.y += deltaTime * m_speed;
}
*/