#include "BoxCollider.hpp"

#include <iostream>

BoxCollider::BoxCollider() {

}

BoxCollider::BoxCollider(float x, float y, float width, float height)
    : m_bounds(x, y, width, height)
{
}

void BoxCollider::SetPosition(const sf::Vector2f& position)
{
    m_bounds.left = position.x;
    m_bounds.top = position.y;
}

void BoxCollider::SetSize(float width, float height)
{
    m_bounds.width = width;
    m_bounds.height = height;
}

sf::FloatRect BoxCollider::GetBounds() const
{
    return m_bounds;
}

CollisionSide BoxCollider::GetCollisionSide(const sf::FloatRect& collider, const sf::FloatRect& otherCollider) const
{
    float dx = (collider.left + collider.width / 2.0f) - (otherCollider.left + otherCollider.width / 2.0f);
    float dy = (collider.top + collider.height / 2.0f) - (otherCollider.top + otherCollider.height / 2.0f);

    float combinedHalfWidths = collider.width / 2.0f + otherCollider.width / 2.0f;
    float combinedHalfHeights = collider.height / 2.0f + otherCollider.height / 2.0f;

    float penetrationX = combinedHalfWidths - std::abs(dx);
    float penetrationY = combinedHalfHeights - std::abs(dy);

    if (penetrationX > penetrationY)
    {
        if (dx > 0.0f)
            return CollisionSide::Left;
        else
            return CollisionSide::Right;
    }
    else
    {
        if (dy > 0.0f)
            return CollisionSide::Top;
        else
            return CollisionSide::Bottom;
    }
}

CollisionSide BoxCollider::CheckCollision(const BoxCollider& other) const
{
    if (m_bounds.intersects(other.GetBounds()))
    {
        std::cout << "Collision detected" << std::endl;
        return GetCollisionSide(m_bounds, other.GetBounds());
    }

    return CollisionSide::None;
}
