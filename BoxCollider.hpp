#pragma once

#include <SFML/Graphics.hpp>

enum class CollisionSide
{
    None,
    Top,
    Bottom,
    Left,
    Right
};

class BoxCollider
{
public:
    BoxCollider();
    BoxCollider(float x, float y, float width, float height);
    ~BoxCollider() {}

    void SetPosition(const sf::Vector2f& position);
    void SetSize(float width, float height);

    sf::FloatRect GetBounds() const;

    CollisionSide GetCollisionSide(const sf::FloatRect& collider, const sf::FloatRect& otherCollider) const;
    CollisionSide CheckCollision(const BoxCollider& other) const;

private:
    sf::FloatRect m_bounds;
};
