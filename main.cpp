#include <SFML/Graphics.hpp>
#include "Platform.hpp"
#include "Character.hpp"
#include "GameObject.hpp"
#include "GameLevelController.hpp"
#include "Camera.hpp"
#include "GameExceptions.hpp"
#include <iostream>

int main()
{
    float window_size_x = 800;
    float window_size_y = 600;

    // Create the game window
    sf::RenderWindow window(sf::VideoMode(window_size_x, window_size_y), "Futurama The Run");

    // create a view with its center and size
    sf::View view = window.getDefaultView();
    window.setView(view);

    try {
        // Load the player texture
        sf::Texture playerTexture;
        loadTexture("playerr.png", playerTexture);

        // Load the background texture
        sf::Texture backgroundTexture;
        loadTexture("fundao.png", backgroundTexture);

        // Load the startscreen texture
        sf::Texture startScreenTexture;
        loadTexture("futt.jpeg", startScreenTexture);

        // Load the platform texture
        sf::Texture platformTexture;
        loadTexture("chaoo.jpg", platformTexture);

    } catch (const GameException& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
        // display an error message to the user
        return 1; // stop the program
    }

    // Create the player sprite
    //Character player("playerr.png", 50.0f, 450.0f, 0.2f,  0.2f, 200.0f);
    
    //Create the background sprite
    GameObject background("Background", "fundao.png",0.0f, 0.0f,0.7f, 0.7f);

     //Create the startscreen sprite
    GameObject startscreen("Start Screen", "futt.jpeg",0.0f, 0.0f,0.75f, 0.83f);

    // Create the platform sprite
    //Platform platform("chaoo.jpg", 0.0f, 520.0f, 3.0f, 1.8f);

    // Create the GameLevelController
    GameLevelController::getInstance().setWindow(&window);

    // Create the Camera Controller
    Camera camera(&window);

    // Create a clock to measure time
    sf::Clock clock;

     // Game state
    enum class GameState
    {
        StartScreen,
        Gameplay
    };

    GameState currentState = GameState::StartScreen;

    // Start() all objects
    GameLevelController::getInstance().Start();

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
        if(currentState == GameState::StartScreen ){
            startscreen.Update(deltaTime.asSeconds());

            // Clear and render
            window.clear();

            startscreen.Draw(window);

            window.display();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
            {
            currentState = GameState::Gameplay; // Atribuir um novo valor à variável existente
            }

            
        }else if(currentState == GameState::Gameplay ){
        // Update() all objects
        //player.Update(deltaTime.asSeconds());

        camera.Update(deltaTime.asSeconds());
        GameLevelController::getInstance().Update(deltaTime.asSeconds());
        
        // Clear and render
        window.clear();
        
        // Draw all objects
        background.Draw(window);

        // Draw the platform
        //platform.Draw(window);

        GameLevelController::getInstance().Draw();

        //player.Draw(window);

        
        window.display();
        }
    }
    return 0;
}