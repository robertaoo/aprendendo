#pragma once

#include <SFML/Graphics.hpp>
#include "Character.hpp"

class Camera {
public:
    Camera(sf::RenderWindow *window);
    ~Camera();

    void Start();

    void Update(float deltaTime);

private:
    sf::RenderWindow *m_window;
};