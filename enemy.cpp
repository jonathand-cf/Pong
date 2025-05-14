#include "enemy.h"
enemy::enemy(float startX, float startY)
{

    m_position = sf::Vector2f(startX, startY);
    m_shape.setSize(sf::Vector2f(90, 5));
    m_shape.setFillColor(sf::Color::White);
    m_shape.setOutlineColor(sf::Color::Red);
    m_shape.setOutlineThickness(2);
    m_shape.setPosition(m_position);

}


sf::FloatRect enemy::getPosition() const
{
    return m_shape.getGlobalBounds();
}
sf::RectangleShape enemy::getShape()
{
    return m_shape;
}

void enemy::MoveLeft()
{
    m_MovingLeft = true;
}
void enemy::MoveRight()
{
    m_MovingRight = true;
}
void enemy::stopLeft()
{
    m_MovingLeft = false;
}
void enemy::stopRight()
{
    m_MovingRight = false;
}
void enemy::update(sf::Time deltaTime)
{
    if (m_MovingLeft)
    {
        m_position.x -= m_Speed * deltaTime.asSeconds();
    }
    if (m_MovingRight)
    {
        m_position.x += m_Speed * deltaTime.asSeconds();
    }
    m_shape.setPosition(m_position);
}
