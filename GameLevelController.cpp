#include "GameLevelController.hpp"
#include "Character.hpp"
#include <fstream>

GameLevelController::GameLevelController()
{
}

GameLevelController::~GameLevelController()
{
}

void GameLevelController::Start()
{
    GenerateLevel();
}

void GameLevelController::Update(float deltaTime)
{
    for (auto gameObject : m_gameObjects)
    {
        gameObject->Update(deltaTime);
    }
}

void GameLevelController::Draw(sf::RenderWindow& window)
{
    for (auto gameObject : m_gameObjects)
    {
        gameObject->Draw(window);
    }
}

void GameLevelController::GenerateLevel()
{


    // Open the file
    std::ifstream file("level.txt");

    // Check if the file is open
    if (!file.is_open())
    {
        // Error
    }

    // Read the file
    std::string imagePath;
    float x, y;

    while (file >> imagePath >> x >> y)
    {
        x *= 100;
        y *= 100;

        if (imagePath == "player") {
            // Create the player sprite
            Character* character = new Character("player.png", x, y, 0.2f,  0.2f, 400.0f);
            // Add the GameObject to the vector
            m_character = character;
            continue;
        }

        // Create a GameObject
        GameObject* gameObject = new GameObject(imagePath, x, y, 1, 1);

        // Add the GameObject to the vector
        m_gameObjects.push_back(gameObject);
    }

    // Close the file
    file.close();
}

void GameLevelController::AddGameObject(GameObject* gameObject)
{
    m_gameObjects.push_back(gameObject);
}

void GameLevelController::RemoveGameObject(GameObject* gameObject)
{
    // Find the gameObject in the vector
    // Remove it
}

void GameLevelController::ClearGameObjects()
{
    m_gameObjects.clear();
}

std::vector<GameObject*> GameLevelController::GetGameObjects()
{
    return m_gameObjects;
}