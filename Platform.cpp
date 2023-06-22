#include "Platform.hpp"

Platform::Platform(const std::string& imagePath, float x, float y, float scaleX, float scaleY) 
        : GameObject("", imagePath, x, y, scaleX, scaleY)
{
    m_sprite.setTexture(m_texture);
    m_sprite.setPosition(x, y);
    m_sprite.setScale(scaleX, scaleY);
    
}

void Platform::Update(float deltaTime)
{
}
