#ifndef BALL_H
#define BALL_H
#include <random>
#include <SFML/Graphics.hpp>

// Define static random generators in this source file
static std::random_device rd;
static std::mt19937 rng(rd());
static std::uniform_int_distribution<int> uni(0, 1280);

class ball
{
private:
    sf::Vector2f m_pos;
    sf::RectangleShape m_ballShape;

    float m_speed = 500;
    float m_directionX = 1.0f;
    float m_directionY = 1.0f;


    public:
    ball(float startX, float startY);
    sf::FloatRect getPosition() const;
    sf::RectangleShape getShape();

    float getVelocityX() const;

    void hitSides();

    void hitTop();

    void resetPos() {
        // Set the ball's x-position to a random value between 0 and 1280
        m_pos.x = static_cast<float>(uni(rng));
        m_ballShape.setPosition(m_pos);
    }

    void increaseSpeed(float increment);

    void noClipBottom();

    void hitBall();

    void update(sf::Time deltaTime);
};



#endif //BALL_H
