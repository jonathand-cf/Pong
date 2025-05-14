#include "paddle.h"
paddle::paddle(float startX, float startY)
{
    m_position.x = startX;
    m_position.y = startY;

    m_shape.setSize(sf::Vector2f(90, 5));
    m_shape.setFillColor(sf::Color::White);
    m_shape.setOutlineColor(sf::Color::Blue);
    m_shape.setOutlineThickness(2);

    m_shape.setPosition(m_position);
}


sf::FloatRect paddle::getPosition() const {
    return m_shape.getGlobalBounds();
}
sf::RectangleShape paddle::getShape() {
    return m_shape;
}

void paddle::MoveLeft() {
    m_MovingLeft = true;
}
void paddle::MoveRight() {
    m_MovingRight = true;
}
void paddle::stopLeft() {
    m_MovingLeft = false;
}
void paddle::stopRight() {
    m_MovingRight = false;
}
void paddle::update(sf::Time deltaTime) {
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
