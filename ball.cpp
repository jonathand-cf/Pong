#include "ball.h"


ball::ball(float startX, float startY)
{
    m_pos.x = startX;
    m_pos.y = startY;

    m_ballShape.setSize(sf::Vector2f(10, 10));
    m_ballShape.setPosition(m_pos);

}


sf::FloatRect ball::getPosition() const {
    return m_ballShape.getGlobalBounds();
}
sf::RectangleShape ball::getShape()
{
    return m_ballShape;
}
float ball::getVelocityX() const {
    return m_directionX;
}
void ball::hitSides()
{
  m_directionX = -m_directionX;
}
void ball::hitTop()
{
    m_pos.x = uni(rng);
    m_pos.y = 350;
    m_ballShape.setPosition(m_pos);
}
void ball::noClipBottom()
{
    m_pos.x = uni(rng);
    m_pos.y = 350;
    m_ballShape.setPosition(m_pos);
}
void ball::increaseSpeed(float increment)
{
    m_speed += increment;
}
void ball::hitBall() {
    m_directionY = -m_directionY;
    increaseSpeed(10.0f); // :)
}
void ball::update(sf::Time deltaTime) {
    m_pos.x += m_directionX * m_speed * deltaTime.asSeconds();
    m_pos.y += m_directionY * m_speed * deltaTime.asSeconds();

    m_ballShape.setPosition(m_pos);
}