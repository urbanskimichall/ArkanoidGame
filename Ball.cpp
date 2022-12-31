#include <iostream>
#include "Ball.h"

Ball::Ball()
{
    ball.setRadius(radius);
    ball.setFillColor(colorOfBall);
    ball.setOutlineColor(outlineColorOfBall);
    ball.setOutlineThickness(thickness);
}

void Ball::setBallPosition(Platform &platform, int xSizeOfWindow, int ySizeOfWindow)
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
                                                      xSizeOfWindow, ySizeOfWindow);
        currentXballPosition = ballCords.first;
        currentYballPosition = ballCords.second;
        ball.setPosition(ballCords.first, ballCords.second);
    }
}

sf::CircleShape Ball::getBall()
{
    return ball;
}
