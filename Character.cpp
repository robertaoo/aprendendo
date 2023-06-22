#include "Character.hpp"
#include "GameLevelController.hpp"

#include <iostream>

// Constructor
Character::Character(std::string name, const std::string& imagePath, float x, float y, float scaleX, float scaleY, float speed)
    : GameObject(name, imagePath, x, y, scaleX, scaleY)
{
     m_speed = speed;
    m_isJumping = false;
    m_jumpHeight = y - 640.0f; // Altura máxima do pulo (o dobro da altura atual)
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
    sf::Vector2f initialPos = m_transform.position;

    // Update the position
    Walk(deltaTime);
    Jump(deltaTime);

    DoCollision(initialPos);
    
    // Update the sprite positiona
    m_sprite.setPosition(m_transform.position);
    m_collider.SetPosition(m_transform.position);
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
        m_transform.position.x -= deltaTime * m_speed; // transforma posicao 
        

        // Verifica se a posição ultrapassou o limite da janela na esquerda
        GameLevelController &controller = GameLevelController::getInstance();
        float border = controller.getWindow()->getView().getCenter().x - (controller.getWindow()->getSize().x/2);
        if (m_transform.position.x < border)
        {
            m_transform.position.x = border;
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

void Character::DoCollision(sf::Vector2f initialPos) {
    CollisionSide side;
    for (GameObject* go : GameLevelController::getInstance().GetGameObjects()) {
        std::cout << "Testing " << m_name << " com " << go->getName() << std::endl;
        side = m_collider.CheckCollision(*(go->getCollider()));
        break;
    }

    if (side == CollisionSide::Left || side == CollisionSide::Right) {
        m_transform.position.x = initialPos.x;
    }

    else if (side == CollisionSide::Top || side == CollisionSide::Bottom) {
        m_transform.position.y = initialPos.y;
    }


}