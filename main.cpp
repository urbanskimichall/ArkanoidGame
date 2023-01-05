#include <SFML/Window.hpp>
#include "Platform.h"
#include "Ball.h"
#include "Blocks.h"
#include "BlockDestroyer.h"
#include <SFML/Graphics.hpp>
#include <thread>
#include <synchapi.h>

int main()
{
    const int xSizeOfWindow{1280};
    const int ySizeOfWindow{720};
    sf::RenderWindow window(sf::VideoMode(xSizeOfWindow, ySizeOfWindow), "Arkanoid");

    Blocks blocks(xSizeOfWindow, ySizeOfWindow);
    blocks.setRowsOfBlocks();

    Platform platform(xSizeOfWindow, ySizeOfWindow);
    Ball ball(blocks.getBlock());
    Ball ball2(blocks.getBlock());

    std::vector<sf::RectangleShape> rectangles=blocks.getBlock();

    int clickCounter{0};
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
                clickCounter++;
                if(clickCounter>2)
                {
                    ball2.isBallReleased = true;
                }

            }
        }
        sf::Vector2i currentMousePosition = sf::Mouse::getPosition(window);
        platform.setPlatformPosition(currentMousePosition.x);
        ball.setBallPosition(platform, xSizeOfWindow, ySizeOfWindow,rectangles);
        ball2.setBallPosition(platform, xSizeOfWindow, ySizeOfWindow,rectangles);
//        BlockDestroyer blockDestroyer(platform,blocks);
//        auto rectangles=blockDestroyer.removeBlockAfterShoot();
//        ball.setRectangles(rectangles);
        window.clear();
        Sleep(1);
        platform.drawPlatform(window);
        window.draw(ball.getBall());
        window.draw(ball2.getBall());

        for (const auto &rectangle: rectangles)
        {
            window.draw(rectangle);
        }

        window.display();
    }

    return 0;
}