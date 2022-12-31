#include <iostream>
#include "BallMovement.h"

BallMovement::BallMovement(float radiusOfBall)
{
    this->radiusOfBall = radiusOfBall;
}

void BallMovement::fillUpSectorsValues(Platform &platform)
{
    float sizeOfSector{0.f};
    sizeOfSector = platform.getSizeXOfPlatform() / numberOfSectors;
    for (int i = 0; i < numberOfSectors; ++i)
    {
        sectorsOfPlatform[i] = platform.getXOfPlatform() + sizeOfSector * i;
    }
}

std::pair<float, float>
BallMovement::changePositionOfBall(Platform &platform, float currentXposition, float currentYposition,
                                   int xSizeOfWindow, int ySizeOfWindow)
{
    fillUpSectorsValues(platform);
    checkCeilingTouch(currentXposition, currentYposition);
    checkPlatformTouch(currentXposition, currentYposition, platform, ySizeOfWindow);
    checkLeftWallTouch(currentXposition, currentYposition);
    checkRightWallTouch(currentXposition, currentYposition, xSizeOfWindow);

    return updateBallPosition(currentXposition, currentYposition);
}

void BallMovement::checkCeilingTouch(float xOfBall, float yOfBall)
{
    if (yOfBall < 0 && ballDirections == BallDirections::UP_LEFT)
    {
        ballDirections = BallDirections::DOWN_LEFT;
    }
    else if (yOfBall < 0 && ballDirections == BallDirections::UP_RIGHT)
    {
        ballDirections = BallDirections::DOWN_RIGHT;
    }
}

void
BallMovement::checkPlatformTouch(float xOfBall, float yOfBall, Platform &platform, int ySizeOfWindow)
{
    if (yOfBall > ySizeOfWindow - 4 * platform.getSizeYOfPlatform() && ballDirections == BallDirections::DOWN_LEFT)
    {
        ballDirections = BallDirections::UP_LEFT;
    }
    else if (yOfBall > ySizeOfWindow - 4 * platform.getSizeYOfPlatform() &&
             ballDirections == BallDirections::DOWN_RIGHT)
    {
        ballDirections = BallDirections::UP_RIGHT;
    }
}

void BallMovement::checkLeftWallTouch(float xOfBall, float yOfBall)
{
    if (xOfBall < 0 && ballDirections == BallDirections::UP_LEFT)
    {
        ballDirections = BallDirections::UP_RIGHT;
    }
    else if (xOfBall < 0 && ballDirections == BallDirections::DOWN_LEFT)
    {
        ballDirections = BallDirections::DOWN_RIGHT;
    }

}

void BallMovement::checkRightWallTouch(float xOfBall, float yOfBall, int xSizeOfWindow)
{
    if (xOfBall > xSizeOfWindow - 2 * radiusOfBall && ballDirections == BallDirections::UP_RIGHT)
    {
        ballDirections = BallDirections::UP_LEFT;
    }
    else if (xOfBall > xSizeOfWindow - 2 * radiusOfBall && ballDirections == BallDirections::DOWN_RIGHT)
    {
        ballDirections = BallDirections::DOWN_LEFT;
    }

}

std::pair<float, float> BallMovement::updateBallPosition(float currentXposition, float currentYposition)
{
    switch (ballDirections)
    {
    case BallDirections::UP_RIGHT:
        currentXposition += 0.05;
        currentYposition -= 0.1;
        break;
    case BallDirections::UP_LEFT:
        currentXposition -= 0.05;
        currentYposition -= 0.1;
        break;
    case BallDirections::DOWN_RIGHT:
        currentXposition += 0.05;
        currentYposition += 0.1;
        break;
    case BallDirections::DOWN_LEFT:
        currentXposition -= 0.05;
        currentYposition += 0.1;
        break;
    case BallDirections::INVALID:
        std::cout << "Invalid ball direction!" << std::endl;
        break;
    }
    return std::pair<float, float>(currentXposition, currentYposition);
}
