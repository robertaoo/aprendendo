#include "GameLevelController.hpp"
#include "Character.hpp"
#include <fstream>

#include <iostream>

GameLevelController::GameLevelController()
{
}

GameLevelController::~GameLevelController()
{
}


void GameLevelController::setWindow(sf::RenderWindow *window) {
    m_window = window;
}

sf::RenderWindow * GameLevelController::getWindow() {
    return m_window;
}

Character *GameLevelController::getPlayer() {
    return m_player;
}

void GameLevelController::Start()
{
    m_yOffset = m_window->getSize().y;
    GenerateLevel();
}

void GameLevelController::Update(float deltaTime)
{
    for (auto gameObject : m_gameObjects)
    {
        gameObject->Update(deltaTime);
    }

    m_player->Update(deltaTime);
}

void GameLevelController::Draw()
{
    for (auto gameObject : m_gameObjects)
    {
        gameObject->Draw(*m_window);
    }

    m_player->Draw(*m_window);
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

    int id = 0;

    while (file >> imagePath >> x >> y)
    {
        x *= 64;
        y *= 64;

        y = m_yOffset - y - 64;

        if (imagePath == "player") {
            // Create the player sprite
            Character* player = new Character("Player", "player_64_128.png", x, y, 0.8,  0.8, 200.0f);
            // Add the GameObject to the vector
            m_player = player;
            continue;
        }

        // Create a GameObject
        GameObject* gameObject = new GameObject("Object " + std::to_string(id++), imagePath, x, y, 1, 1);

        // Add the GameObject to the vector
        m_gameObjects.push_back(gameObject);
    }

    std::cout << "Finished Adding GameObjects to scene" << std::endl;

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