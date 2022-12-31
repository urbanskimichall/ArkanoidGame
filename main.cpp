#include <SFML/Window.hpp>
#include "Platform.h"
#include "Ball.h"
#include <SFML/Graphics.hpp>

int main()
{
    const int xSizeOfWindow{1280};
    const int ySizeOfWindow{720};
    sf::RenderWindow window(sf::VideoMode(xSizeOfWindow, ySizeOfWindow), "Arkanoid");

    Platform platform(xSizeOfWindow, ySizeOfWindow);
    Ball ball;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                ball.isBallReleased = true;
            }
        }
        sf::Vector2i currentMousePosition = sf::Mouse::getPosition(window);
        platform.setPlatformPosition(currentMousePosition.x);
        ball.setBallPosition(platform, xSizeOfWindow, ySizeOfWindow);
        window.clear();
        window.draw(platform.getPlatform());
        window.draw(ball.getBall());
        window.display();
    }

    return 0;
}