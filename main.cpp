#include <iostream>

#include "ball.h"
#include "paddle.h"
#include "enemy.h"
#include <SFML/Audio.hpp>

bool anotherPlayer = false;
bool AI = false;

int main()
{
    //SETTINGS
    sf::Clock clock;
    sf::Time dt;
    //WINDOW AND SIZES
    sf::VideoMode fixedMode({1280, 720}, 32);
    sf::RenderWindow window(fixedMode, "Pong Clone");
    ball pongDance(640, 300);
    paddle paddleDance(640, 710);
    enemy ememyDance(640, 40);
    float bounceTimer = 0.10f;


    //SOUND EFFECTS
    sf::SoundBuffer sound_buffer;
    if (!sound_buffer.loadFromFile("Sound/ui-pop-sound-316482.mp3"))
    {
        printf("Failed to load sounds\n");
        return -1;
    }

    sf::Sound sound(sound_buffer);
    sf::SoundBuffer sound_buffer2;
    if (!sound_buffer2.loadFromFile("Sound/tada-fanfare-a-6313.mp3")) {
        printf("Failed to load sounds\n");
        return -1;
    }
    sf::Sound sound2(sound_buffer2);



    //TEXT
    sf::Font font;
    if (!font.openFromFile("Text/PixelEmulator-xq08.ttf"))
    {
        printf("Failed to load font\n");
        return -1;
    }

    // Player Scores:
    sf::Text fontHUD(font);
    fontHUD.setCharacterSize(20);
    fontHUD.setPosition({5, 0});
    fontHUD.setFillColor(sf::Color::White);
    fontHUD.setOutlineThickness(3);
    fontHUD.setOutlineColor(sf::Color::Blue);


    int Points = 0;
    fontHUD.setString("Points: " + std::to_string(Points));

    //Enemy Scores:
    sf::Text enemyHUD(font);
    enemyHUD.setCharacterSize(20);
    enemyHUD.setPosition({1100, 0});
    enemyHUD.setFillColor(sf::Color::White);
    enemyHUD.setOutlineThickness(3);
    enemyHUD.setOutlineColor(sf::Color::Red);


    int enemyPoints = 0;
    enemyHUD.setString("Points: " + std::to_string(enemyPoints));

    sf::Text lineMIDLLE(font);
    lineMIDLLE.setCharacterSize(24);
    lineMIDLLE.setPosition({0, 350});
    lineMIDLLE.setFillColor(sf::Color::White);
    lineMIDLLE.setOutlineThickness(3);
    lineMIDLLE.setOutlineColor(sf::Color::Green);
    lineMIDLLE.setString("------------------------------------------------------------------------------------------------------------------");

    //MENU
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>() ||
                (event->is<sf::Event::KeyPressed>() &&
                 event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::Escape))
                window.close();
            // The window was resized
            if (const auto* resized = event->getIf<sf::Event::Resized>())
            {
                // Create a view that covers the new window size.
                sf::Vector2u newSize = resized->size;
                sf::FloatRect newBounds({0.f, 0.f}, {static_cast<float>(newSize.x), static_cast<float>(newSize.y)});
                sf::View view(newBounds);
                window.setView(view);
            }

        }

        sf::Font menu;
        if (!menu.openFromFile("Text/PixelEmulator-xq08.ttf"))
        {
            printf("Failed to load menu file");
            return 1;
        }

        sf::Text menuHUD(menu);
        menuHUD.setCharacterSize(30);
        menuHUD.setFont(menuHUD.getFont());
        menuHUD.setPosition({400, 320});
        menuHUD.setStyle(sf::Text::Style::Bold);
        menuHUD.setFillColor(sf::Color::White);
        menuHUD.setString("Welcome to a Pong Clone");

        sf::Text menuHUD2(menu);
        menuHUD2.setCharacterSize(30);
        menuHUD2.setFont(menuHUD.getFont());
        menuHUD2.setPosition({280, 350});
        menuHUD2.setStyle(sf::Text::Style::Bold);
        menuHUD2.setFillColor(sf::Color::Blue);
        menuHUD2.setString("Press key 1 to start soloplayer");

        sf::Text menuHUD3(menu);
        menuHUD3.setCharacterSize(30);
        menuHUD3.setFont(menuHUD.getFont());
        menuHUD3.setPosition({220, 380});
        menuHUD3.setStyle(sf::Text::Style::Bold);
        menuHUD3.setFillColor(sf::Color::Red);
        menuHUD3.setString("Press key 2 to play vs another player");

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num1)) {
            AI = true;
            break;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num2))
        {
            anotherPlayer = true;
            break;
        }

        window.clear();
        window.draw(menuHUD);
        window.draw(menuHUD2);
        // ikke vits i guess
        // window.draw(menuHUD3);
        window.display();

    }
    // GAME
    while (window.isOpen())
    {


        dt = clock.restart();
        bounceTimer -= dt.asSeconds();


        // Cache the ball's bounding rectangle so we don't call getPosition() multiple times.
        sf::FloatRect ballBounds = pongDance.getPosition();
        sf::FloatRect enemyBounds = ememyDance.getPosition();
        sf::FloatRect paddleBounds = paddleDance.getPosition();

        // Check if either intersection exists and if the bounce timer allows a collision.
        if (bounceTimer <= 0 &&
            (ballBounds.findIntersection(paddleBounds).has_value() ||
             ballBounds.findIntersection(enemyBounds).has_value()))
        {
            pongDance.hitBall();
            sound.play();
            bounceTimer = 0.10f;
        }



        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>() ||
                (event->is<sf::Event::KeyPressed>() &&
                 event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::Escape))
                window.close();
            // The window was resized
            if (const auto* resized = event->getIf<sf::Event::Resized>())
            {
                // Create a view that covers the new window size.
                sf::Vector2u newSize = resized->size;
                sf::FloatRect newBounds({0.f, 0.f}, {static_cast<float>(newSize.x), static_cast<float>(newSize.y)});
                sf::View view(newBounds);
                window.setView(view);
            }

        }

        // Controlls: (A <-> D) You!
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
            paddleDance.MoveLeft();
            if (paddleBounds.position.x < 0)
            {
                paddleDance.stopLeft();
            }
        }
        else {
            paddleDance.stopLeft();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
            paddleDance.MoveRight();
            if (paddleBounds.position.x + paddleBounds.size.x > 1280)
            {
                paddleDance.stopRight();
            }
        }
        else {
            paddleDance.stopRight();
        }
        // Another player logic
        if (anotherPlayer == true) {
            // Controlls: (<- <-> ->) Enemy!
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
                ememyDance.MoveLeft();
                if (enemyBounds.position.x < 0)
                {
                    ememyDance.stopLeft();
                }
            }
            else {
                ememyDance.stopLeft();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
                ememyDance.MoveRight();
                if (enemyBounds.position.x + enemyBounds.size.x > 1280)
                {
                    ememyDance.stopRight();
                }
            }
            else {
                ememyDance.stopRight();
            }
        }
        //AI logic (pfft easy)
        if (AI == true)
        {
            float ballX = ballBounds.position.x + (ballBounds.size.x / 2.0f);
            float enemyX = enemyBounds.position.x + (enemyBounds.size.x / 2.0f);

            // Move left if ball is to the left
            if (ballX < enemyX - 5.0f)
            {
                ememyDance.MoveLeft();
                ememyDance.stopRight();
            }
            // Move right if ball is to the right
            else if (ballX > enemyX + 5.0f)
            {
                ememyDance.MoveRight();
                ememyDance.stopLeft();
            }
            // Paddle is aligned, stop moving
            else
            {
                ememyDance.stopLeft();
                ememyDance.stopRight();
            }

            // Ensure enemy paddle remains on-screen horizontally
            if (enemyBounds.position.x < 0)
                ememyDance.stopLeft();
            else if (enemyBounds.position.x + enemyBounds.size.x > 1280)
                ememyDance.stopRight();
        }


        sf::FloatRect pongBounds = pongDance.getPosition();
        // Check left or right collision
        if (pongBounds.position.x < 0 ||
            pongBounds.position.x + pongBounds.size.x > 1280)
        {
            pongDance.hitSides();
        }
        // Check top collision
        if (pongBounds.position.y < 0 && bounceTimer <= 0)
        {
            pongDance.hitTop();

            enemyPoints = 0;
            enemyHUD.setString("Points: " + std::to_string(enemyPoints));
            Points++;
            fontHUD.setString("Points: " + std::to_string(Points));
            bounceTimer = 0.10f;
        }

        // Check bottom collision
        if (pongBounds.position.y + pongBounds.size.y > 720 && bounceTimer <= 0)
        {
            pongDance.noClipBottom();

            enemyPoints++;
            enemyHUD.setString("Points: " + std::to_string(enemyPoints));
            Points = 0;
            fontHUD.setString("Points: " + std::to_string(Points));
            bounceTimer = 0.10f;
        }

        if (Points == 10)
        {
            sound2.play();
            // Set up the winning overlay texts.
            sf::Font menuFont;
            if (!menuFont.openFromFile("Text/PixelEmulator-xq08.ttf"))
            {
                std::cout << "Failed to load menu file\n";
                return 1;
            }
            sf::Text winText(menuFont);
            winText.setCharacterSize(30);
            winText.setPosition({500, 200});
            winText.setStyle(sf::Text::Style::Bold);
            winText.setFillColor(sf::Color::White);
            winText.setString("You WON!");

            sf::Text replayText(menuFont);
            replayText.setCharacterSize(30);
            replayText.setPosition({380, 290});
            replayText.setStyle(sf::Text::Style::Bold);
            replayText.setFillColor(sf::Color::White);
            replayText.setString("Press Enter to play again");

            // Pause loop inside the game loop.
            bool paused = true;
            while (paused && window.isOpen()) {
                std::optional<sf::Event> pauseEvent;
                while ((pauseEvent = window.pollEvent()))
                {
                    if (pauseEvent->is<sf::Event::Closed>())
                        window.close();
                    if (pauseEvent->is<sf::Event::KeyPressed>() &&
                        pauseEvent->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::Enter)
                    {
                        paused = false;
                    }
                }
                window.clear();
                window.draw(winText);
                window.draw(replayText);
                window.display();
            }
            // Reset game state after win.
            Points = 0;
            fontHUD.setString("Points: " + std::to_string(Points));
            window.close();
            return main();
        }

        // Becomes black screen & updates delta time
        window.clear();
        pongDance.update(dt);
        paddleDance.update(dt);
        ememyDance.update(dt);
        // Draws the ball and paddle
        window.draw(pongDance.getShape());
        window.draw(paddleDance.getShape());
        window.draw(ememyDance.getShape());

        window.draw(fontHUD);
        window.draw(enemyHUD);
        window.draw(lineMIDLLE);

        window.display();
    }

}
