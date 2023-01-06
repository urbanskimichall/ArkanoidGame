#include <iostream>
#include "Ball.h"

Ball::Ball(std::vector<sf::RectangleShape> &rectangles)
{
    this->rectangles = rectangles;
    ball.setRadius(radius);
    ball.setFillColor(colorOfBall);
    ball.setOutlineColor(outlineColorOfBall);
    ball.setOutlineThickness(thickness);
}

void Ball::setBallPosition(Platform &platform, int xSizeOfWindow, int ySizeOfWindow,
                           std::vector<sf::RectangleShape> &rectangles1)
{
    std::pair<float, float> ballCords;
    if (!isBallReleased)
    {
        currentXballPosition = platform.getXOfPlatform() + 4 * radius;
        currentYballPosition = platform.getYOfPlatform() - 2.6f * radius;
        ball.setPosition(currentXballPosition, currentYballPosition);
    }
    else
    {
        ballCords = ballMovement.changePositionOfBall(platform, currentXballPosition, currentYballPosition,
                                                      xSizeOfWindow, ySizeOfWindow, rectangles1);
        std::cout << "size : " << rectangles1.size() << std::endl;
        currentXballPosition = ballCords.first;
        currentYballPosition = ballCords.second;
        ball.setPosition(ballCords.first, ballCords.second);
    }
}

sf::CircleShape Ball::getBall()
{
    return ball;
}

std::vector<sf::RectangleShape> &Ball::getLeftBlocks()
{
    return rectangles;
}

void Ball::setRectangles(std::vector<sf::RectangleShape> &rect)
{
    rectangles = rect;
}
