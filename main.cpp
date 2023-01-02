#include <SFML/Window.hpp>
#include "Platform.h"
#include "Ball.h"
#include "Blocks.h"
#include <SFML/Graphics.hpp>
#include <thread>
#include <synchapi.h>

int main()
{
    const int xSizeOfWindow{1280};
    const int ySizeOfWindow{720};
    sf::RenderWindow window(sf::VideoMode(xSizeOfWindow, ySizeOfWindow), "Arkanoid");

    Platform platform(xSizeOfWindow, ySizeOfWindow);
    Ball ball;

    Blocks blocks(xSizeOfWindow, ySizeOfWindow);
    blocks.setRowsOfBlocks();

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
        Sleep(1);
        window.draw(platform.getPlatform());
        window.draw(ball.getBall());

        for (const auto &rectangle: blocks.getBlock())
        {
            window.draw(rectangle);
        }

        window.display();
    }

    return 0;
}