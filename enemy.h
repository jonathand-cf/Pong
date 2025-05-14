#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class enemy {
    private:
        sf::RectangleShape m_shape;
        sf::Vector2f m_position;
        float m_Speed = 800.0f;

        bool m_MovingLeft = false;
        bool m_MovingRight = false;

    public:
        enemy(float startX, float startY);


        sf::RectangleShape getShape();
        sf::FloatRect getPosition() const;

        void MoveLeft();
        void MoveRight();
        void stopLeft();
        void stopRight();

        void update(sf::Time deltaTime);

};



#endif //ENEMY_H
