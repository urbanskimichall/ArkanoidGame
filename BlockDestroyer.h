#ifndef ARKANOID_BLOCKDESTROYER_H
#define ARKANOID_BLOCKDESTROYER_H

#include "Blocks.h"
#include "Platform.h"

class BlockDestroyer
{
public:
    BlockDestroyer(Platform &platform, Blocks &blocks);

    std::vector<sf::RectangleShape> removeBlockAfterShoot(std::vector<sf::RectangleShape> &rectangles,
                                                          std::vector<std::tuple<sf::RectangleShape, float, float>> &bullets);

private:

    Platform platform1;
    Blocks blocks1;

};

#endif //ARKANOID_BLOCKDESTROYER_H
