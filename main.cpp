#include <SFML/Graphics.hpp>

#include "Character.hpp"
#include "GameObject.hpp"

int main()
{
    // Create the game window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Platform Game");

    // Load the player texture
    sf::Texture playerTexture;
    if (!playerTexture.loadFromFile("player.png"))
    {
        // handle error
    }

    // Create the player sprite
    Character player("player.png", 200.0f, 200.0f, 0.2f,  0.2f, 400);

    // Create a clock to measure time
    sf::Clock clock;

    // Start() all objects

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
        player.Update(deltaTime.asSeconds());

        /*
        // Handle keyboard input
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            playerVelocity.x = playerSpeed;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            playerVelocity.x = -playerSpeed;
        }
        else
        {
            playerVelocity.x = 0.0f;
        }*/

        // Update player position
        //playerSprite.move(playerVelocity * deltaTime.asSeconds());

        // Update game logic

        // Clear and render
        window.clear();
        
        // Draw all objects
        player.Draw(window);
        
        window.display();
    }

    return 0;
}