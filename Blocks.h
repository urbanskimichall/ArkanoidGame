#ifndef ARKANOID_BLOCKS_H
#define ARKANOID_BLOCKS_H

#include <SFML/Graphics.hpp>

class Blocks
{
public:
    Blocks()
    {}

    Blocks(int xWindowSize, int yWindowSize);

    void setSingleRowOfBlocks(int blocksRowShift);

    std::vector<sf::RectangleShape> &getBlock();

    void setRowsOfBlocks();

    void setRectangles(std::vector<sf::RectangleShape> &rect);

private:
    std::vector<sf::RectangleShape> rectangles;
    sf::RectangleShape block;
    float xPositionOfBlock{0};
    float yPositionOfBlock{0};
    int xWindowSize{0};
    int yWindowSize{0};
    float xBlockSize{50};
    float yBlockSize{20};

};

#endif //ARKANOID_BLOCKS_H
