// Generates the levels and keeps data about each object on scene

#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

#include "GameObject.hpp"

class GameLevelController
{
public:
    GameLevelController();
    ~GameLevelController();

    void Start();
    void Update(float deltaTime);

    void Draw(sf::RenderWindow& window);

    void GenerateLevel();

    void AddGameObject(GameObject* gameObject);

    void RemoveGameObject(GameObject* gameObject);

    void ClearGameObjects();

    std::vector<GameObject*> GetGameObjects();

private:
    GameObject* m_character;
    std::vector<GameObject*> m_gameObjects;
};