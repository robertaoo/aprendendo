#include <SFML/Graphics.hpp>

#include "Character.hpp"
#include "GameObject.hpp"
#include "GameLevelController.hpp"

int main()
{

    // Create the game window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Platform Game");
    // Game Level Controller
    GameLevelController gameLevelController;

    // Create a clock to measure time
    sf::Clock clock;

    // Start() all objects
    gameLevelController.Start();

    // Game loop
    while (window.isOpen())
    {
        // Calculate deltaTime
        sf::Time deltaTime = clock.restart();

        // Handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        // Update() all objects
        gameLevelController.Update(deltaTime.asSeconds());

        // Clear and render
        window.clear();
        
        // Draw all objects
        gameLevelController.Draw(window);
        
        window.display();
    }

    return 0;
}