#include <iostream>
#include "Blocks.h"

Blocks::Blocks(int xWindowSize, int yWindowSize)
{
    this->xWindowSize = xWindowSize;
    this->yWindowSize = yWindowSize;
}

void Blocks::setSingleRowOfBlocks(int blocksRowShift)
{
    int leftFreeSpace{xWindowSize % static_cast<int>(xBlockSize)};
    int numberOfRectanglesInSingleRow{xWindowSize / static_cast<int>(xBlockSize)};
    for (int i = 2; i < numberOfRectanglesInSingleRow; i++)
    {
        sf::RectangleShape block;
        block.setSize({xBlockSize, yBlockSize});
        block.setFillColor({200, 110, 100});
        block.setPosition(xPositionOfBlock + i * xBlockSize + leftFreeSpace / 2,
                          yPositionOfBlock + blocksRowShift * yBlockSize);
        block.setOutlineThickness(2);
        block.setOutlineColor({80, 100, 40});
        rectangles.emplace_back(block);
    }
}

std::vector<sf::RectangleShape> &Blocks::getBlock()
{
    return rectangles;
}

void Blocks::setRowsOfBlocks()
{
    for (int i = 2; i < 11; i++)
    {
        setSingleRowOfBlocks(i);
    }
}

void Blocks::setRectangles(std::vector<sf::RectangleShape> &rect)
{
    rectangles=rect;

}

