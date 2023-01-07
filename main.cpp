#include <SFML/Window.hpp>
#include "Platform.h"
#include "Ball.h"
#include "Blocks.h"
#include "BlockDestroyer.h"
#include "Bonus.h"
#include "BonusManager.h"
#include <SFML/Graphics.hpp>
#include <thread>
#include <synchapi.h>

int main()
{
    const int xSizeOfWindow{1080};
    const int ySizeOfWindow{720};
    sf::RenderWindow window(sf::VideoMode(xSizeOfWindow, ySizeOfWindow), "Arkanoid");

    Bonus bonus;
    bonus=Bonus::NO_BONUS;

    Blocks blocks(xSizeOfWindow, ySizeOfWindow);
    blocks.setRowsOfBlocks();

    Platform platform(xSizeOfWindow, ySizeOfWindow);
//    Ball ball(blocks.getBlock());
//    Ball ball2(blocks.getBlock());
    BonusManager bonusManager{blocks};

    std::vector<sf::RectangleShape> rectangles = blocks.getBlock();


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
                for(auto &ball : bonusManager.getBalls())
                {
                    ball.isBallReleased = true;
                }

//                clickCounter++;
//                if (clickCounter > 2)
//                {
//                    ball2.isBallReleased = true;
//                }

            }

        }
        sf::Vector2i currentMousePosition = sf::Mouse::getPosition(window);
        platform.setPlatformPosition(currentMousePosition.x);
        for(auto &ball : bonusManager.getBalls())
        {
           ball.setBallPosition(platform, xSizeOfWindow, ySizeOfWindow, rectangles);
           ball.setRectangles(rectangles);
        }



        BlockDestroyer blockDestroyer(platform, blocks);
        blockDestroyer.removeBlockAfterShoot(rectangles, platform.getBullets());
        bonusManager.generateBonus(rectangles,platform);
        window.clear();
        Sleep(1);
        platform.drawPlatform(window);

//        if(ball.isDoubleBallActive())
//        {
//
//            ball2.setBallPosition(platform, xSizeOfWindow, ySizeOfWindow, rectangles);
//            window.draw(ball2.getBall());
//            ball2.setBallReleased(true);
//        }





        for(auto &ball : bonusManager.getBalls())
        {
            //ball.drawBonus(window);
            window.draw(ball.getBall());
        }
        bonusManager.drawBonus(window);
        for (const auto &rectangle: rectangles)
        {
            window.draw(rectangle);
        }

        window.display();
    }

    return 0;
}