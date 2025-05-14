#ifndef PADDLE_H
#define PADDLE_H
#include <SFML/Graphics.hpp>


class paddle
{
private:
    sf::RectangleShape m_shape;
    sf::Vector2f m_position;
    float m_Speed = 1100.0f;

    bool m_MovingLeft = false;
    bool m_MovingRight = false;

public:
    paddle(float startX, float startY);

    sf::RectangleShape getShape();
    sf::FloatRect getPosition() const;

    void MoveLeft();
    void MoveRight();
    void stopLeft();
    void stopRight();

    void update(sf::Time deltaTime);
};



#endif //PADDLE_H
