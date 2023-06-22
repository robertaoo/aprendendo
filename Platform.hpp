#pragma once
#include "GameObject.hpp"

class Platform : public GameObject
{
public:
    Platform(const std::string& imagePath, float x, float y, float scaleX, float scaleY);
    void Update(float deltaTime);
    
private:
    sf::Texture m_texture;
    sf::Sprite m_sprite;
    
};
