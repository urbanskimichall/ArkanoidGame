#include <iostream>
#include "BlockDestroyer.h"
#include <algorithm>
#include <iterator>

BlockDestroyer::BlockDestroyer(Platform &platform, Blocks &blocks)
{
    this->blocks1 = blocks;
    this->platform1 = platform;
}

std::vector<sf::RectangleShape> BlockDestroyer::removeBlockAfterShoot(std::vector<sf::RectangleShape> &rectangles,
                                                                      std::vector<std::tuple<sf::RectangleShape, float, float>> &bullets)
{
    for (int i = 0; i < platform1.getBullets().size(); i++)
    {
        auto iterLeft = std::find_if(rectangles.begin(), rectangles.end(), [=](auto rectangle)
        {
            return (rectangle.getPosition().x < std::get<0>(bullets[i]).getPosition().x &&
                    rectangle.getPosition().x + rectangle.getSize().x >
                    std::get<0>(bullets[i]).getPosition().x &&
                    rectangle.getPosition().y + rectangle.getSize().y >
                    std::get<0>(bullets[i]).getPosition().y);
        });
        if (iterLeft != rectangles.end())
        {
            rectangles.erase(iterLeft);
            bullets.erase(bullets.begin() + i);

        }
        if (std::get<0>(bullets[i]).getPosition().y < 0)
        {
            bullets.erase(bullets.begin() + i);
        }
    }
    return rectangles;
}
