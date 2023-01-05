#include <iostream>
#include "BlockDestroyer.h"
#include <algorithm>
#include <iterator>

BlockDestroyer::BlockDestroyer(Platform &platform, Blocks &blocks)
{
    this->blocks1 = blocks;
    this->platform1 = platform;
}

std::vector<sf::RectangleShape> BlockDestroyer::removeBlockAfterShoot()
{
//    for (int i=0; i<platform1.getBullets().size(); i++)
//    {auto blocks = blocks1.getBlock();
//        auto iter = std::find_if(blocks1.getBlock().begin(), blocks1.getBlock().end(), [=](auto rectangle)
//        {
//            return (rectangle.getPosition().x < std::get<0>(platform1.getBullets()[i]).getPosition().x &&
//                    rectangle.getPosition().x + rectangle.getSize().x > std::get<0>(platform1.getBullets()[i]).getPosition().x &&
//                    rectangle.getPosition().y + rectangle.getSize().y > std::get<0>(platform1.getBullets()[i]).getPosition().y);
//        });
//        if(iter!=blocks1.getBlock().end())
//        {
//            blocks1.getBlock().erase(iter);
//            platform1.getBullets().erase(platform1.getBullets().begin()+i);
//
//        }
//}

    return blocks1.getBlock();
}
