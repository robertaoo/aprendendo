// Generates the levels and keeps data about each object on scene

#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

#include "GameObject.hpp"
#include "Character.hpp"

class GameLevelController
{
public:
    // Static method to access the instance
    static GameLevelController& getInstance() {
        static GameLevelController instance;
        return instance;
    }

    void Start();
    void Update(float deltaTime);

    void setWindow(sf::RenderWindow *window);
    sf::RenderWindow *getWindow();

    Character *getPlayer();

    void Draw();

    void GenerateLevel();

    void AddGameObject(GameObject* gameObject);

    void RemoveGameObject(GameObject* gameObject);

    void ClearGameObjects();

    std::vector<GameObject*> GetGameObjects();

private:
    // Private constructor and destructor to prevent instantiation and destruction
    GameLevelController();
    ~GameLevelController();

    // Delete the copy constructor and assignment operator to prevent cloning or assignment
    GameLevelController(const GameLevelController&) = delete;
    GameLevelController& operator=(const GameLevelController&) = delete;

    sf::RenderWindow *m_window;
    Character* m_player;
    std::vector<GameObject*> m_gameObjects;

    float m_yOffset;
};