#include <iostream>
#include "BallMovement.h"

BallMovement::BallMovement(float radiusOfBall, BallDirections ballDirections)
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

std::tuple<float, float, bool>
BallMovement::changePositionOfBall(Platform &platform, float currentXposition, float currentYposition,
                                   int xSizeOfWindow, int ySizeOfWindow, std::vector<sf::RectangleShape> &rectangles)
{
    fillUpSectorsValues(platform);
    bool isBlockDestroyed = checkBlockTouch(rectangles, currentXposition, currentYposition);
    checkCeilingTouch(currentXposition, currentYposition);
    checkPlatformTouch(currentXposition, currentYposition, platform, ySizeOfWindow);
    checkLeftWallTouch(currentXposition, currentYposition);
    checkRightWallTouch(currentXposition, currentYposition, xSizeOfWindow);
    gameOver.checkIfBallUnderPlatform(currentYposition, platform.getYOfPlatform());
    return updateBallPosition(currentXposition, currentYposition, isBlockDestroyed);
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

void BallMovement::checkPlatformTouch(float xOfBall, float yOfBall, Platform &platform, int ySizeOfWindow)
{
    if (checkBallOnPlatform(xOfBall, yOfBall, platform, ySizeOfWindow))
    {
        calculatePartOfPlatformWhereBallWasBounced(xOfBall, platform);
        if (ballDirections == BallDirections::DOWN_LEFT || ballDirections == BallDirections::DOWN_RIGHT)
        {
            if (indexOfSector <= 9)
            {
                ballDirections = BallDirections::UP_LEFT;
            }
            else
            {
                ballDirections = BallDirections::UP_RIGHT;
            }
        }
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

std::tuple<float, float, bool>
BallMovement::updateBallPosition(float currentXposition, float currentYposition, bool isBlockDestroyed)
{

    switch (ballDirections)
    {
    case BallDirections::UP_RIGHT:
        currentXposition += ballBounceCoefficient * speedMultiplicator;
        currentYposition -= 0.1f * speedMultiplicator;
        break;
    case BallDirections::UP_LEFT:
        currentXposition -= ballBounceCoefficient * speedMultiplicator;
        currentYposition -= 0.1f * speedMultiplicator;
        break;
    case BallDirections::DOWN_RIGHT:
        currentXposition += ballBounceCoefficient * speedMultiplicator;
        currentYposition += 0.1f * speedMultiplicator;
        break;
    case BallDirections::DOWN_LEFT:
        currentXposition -= ballBounceCoefficient * speedMultiplicator;
        currentYposition += 0.1f * speedMultiplicator;
        break;
    case BallDirections::INVALID:
        std::cout << "Invalid ball direction!" << std::endl;
        break;
    }
    return std::tuple<float, float, bool>(currentXposition, currentYposition, isBlockDestroyed);
}

bool BallMovement::checkBallOnPlatform(float xOfBall, float yOfBall, Platform &platform, int ySizeOfWindow)
{
    return yOfBall > ySizeOfWindow - 4 * platform.getSizeYOfPlatform() &&
           xOfBall + 2 * radiusOfBall > platform.getXOfPlatform() &&
           xOfBall < platform.getXOfPlatform() + platform.getSizeXOfPlatform();
}

void BallMovement::calculatePartOfPlatformWhereBallWasBounced(float xOfBall, Platform &platform)
{
    float distanceBetweenBallAndBeginOfPlatform{xOfBall - platform.getXOfPlatform()};
    float indeXOfSector{(distanceBetweenBallAndBeginOfPlatform / (platform.getSizeXOfPlatform() / numberOfSectors))};
    indexOfSector = static_cast<int> (indeXOfSector);
    if (indexOfSector < 0)
    {
        indexOfSector = 0;
    }
    else if (indexOfSector >= 20)
    {
        indexOfSector = 19;
    }
    ballBounceCoefficient = directionsOfBall[indexOfSector];
}

std::string BallMovement::printBallDirection(BallDirections ballDirections)
{
    switch (ballDirections)
    {
    case BallDirections::INVALID:
        return "BallDirections::INVALID";
    case BallDirections::UP_LEFT:
        return "BallDirections::UP_LEFT";
    case BallDirections::UP_RIGHT:
        return "BallDirections::UP_RIGHT";
    case BallDirections::DOWN_LEFT:
        return "BallDirections::DOWN_LEFT";
    case BallDirections::DOWN_RIGHT:
        return "BallDirections::DOWN_RIGHT";
    }
    return "nothing";
}

bool BallMovement::checkBlockTouch(std::vector<sf::RectangleShape> &rectangles, float currentXposition,
                                   float currentYposition)
{
    bool isBlockDestroyed{false};
    for (int indexOfRectangle = 0; indexOfRectangle < rectangles.size(); indexOfRectangle++)
    {
        if (checkIfBottomSideBlockTouched(rectangles, currentXposition, currentYposition, indexOfRectangle))
        {
            if (ballDirections == BallDirections::UP_RIGHT)
            {
                ballDirections = BallDirections::DOWN_RIGHT;
            }
            else if (ballDirections == BallDirections::UP_LEFT)
            {
                ballDirections = BallDirections::DOWN_LEFT;
            }
            rectangles.erase(rectangles.begin() + indexOfRectangle);
            isBlockDestroyed = true;
            break;
        }
        else if (checkIfLeftSideBlockTouched(rectangles, currentXposition, currentYposition, indexOfRectangle))
        {
            if (ballDirections == BallDirections::UP_RIGHT)
            {
                ballDirections = BallDirections::UP_LEFT;
            }
            else if (ballDirections == BallDirections::DOWN_RIGHT)
            {
                ballDirections = BallDirections::DOWN_LEFT;
            }
            rectangles.erase(rectangles.begin() + indexOfRectangle);
            isBlockDestroyed = true;
            break;
        }
        else if (checkIfRightSideBlockTouched(rectangles, currentXposition, currentYposition, indexOfRectangle))
        {
            if (ballDirections == BallDirections::UP_LEFT)
            {
                ballDirections = BallDirections::UP_RIGHT;
            }
            else if (ballDirections == BallDirections::DOWN_LEFT)
            {
                ballDirections = BallDirections::DOWN_RIGHT;
            }
            rectangles.erase(rectangles.begin() + indexOfRectangle);
            isBlockDestroyed = true;
            break;
        }
        else if (checkIfTopSideBlockTouched(rectangles, currentXposition, currentYposition, indexOfRectangle))
        {
            if (ballDirections == BallDirections::DOWN_RIGHT)
            {
                ballDirections = BallDirections::UP_RIGHT;
            }
            else if (ballDirections == BallDirections::DOWN_LEFT)
            {
                ballDirections = BallDirections::UP_LEFT;
            }
            rectangles.erase(rectangles.begin() + indexOfRectangle);
            isBlockDestroyed = true;
            break;
        }
    }
    return isBlockDestroyed;
}

bool BallMovement::checkIfBottomSideBlockTouched(std::vector<sf::RectangleShape> &rectangles, float currentXposition,
                                                 float currentYposition, int indexOfRectangle)
{
    return (currentXposition > rectangles[indexOfRectangle].getPosition().x &&
            currentXposition <
            rectangles[indexOfRectangle].getPosition().x + rectangles[indexOfRectangle].getSize().x &&
            currentYposition >
            rectangles[indexOfRectangle].getPosition().y + rectangles[indexOfRectangle].getSize().y &&
            currentYposition < rectangles[indexOfRectangle].getPosition().y + 30);
}

bool BallMovement::checkIfTopSideBlockTouched(std::vector<sf::RectangleShape> &rectangles, float currentXposition,
                                              float currentYposition, int indexOfRectangle)
{
    return (currentXposition > rectangles[indexOfRectangle].getPosition().x &&
            currentXposition <
            rectangles[indexOfRectangle].getPosition().x + rectangles[indexOfRectangle].getSize().x &&
            currentYposition + 2 * radiusOfBall > rectangles[indexOfRectangle].getPosition().y &&
            currentYposition < rectangles[indexOfRectangle].getPosition().y + 30);
}

bool BallMovement::checkIfLeftSideBlockTouched(std::vector<sf::RectangleShape> &rectangles, float currentXposition,
                                               float currentYposition, int indexOfRectangle)
{
    return (currentXposition + 2 * radiusOfBall > rectangles[indexOfRectangle].getPosition().x &&
            currentXposition < rectangles[indexOfRectangle].getPosition().x + 30 &&
            currentYposition > rectangles[indexOfRectangle].getPosition().y &&
            currentYposition < rectangles[indexOfRectangle].getPosition().y + rectangles[indexOfRectangle].getSize().y);
}

bool BallMovement::checkIfRightSideBlockTouched(std::vector<sf::RectangleShape> &rectangles, float currentXposition,
                                                float currentYposition, int indexOfRectangle)
{
    return (currentXposition + 2 * radiusOfBall >
            rectangles[indexOfRectangle].getPosition().x + rectangles[indexOfRectangle].getSize().x &&
            currentXposition <
            rectangles[indexOfRectangle].getPosition().x + rectangles[indexOfRectangle].getSize().x + 30 &&
            currentYposition > rectangles[indexOfRectangle].getPosition().y &&
            currentYposition < rectangles[indexOfRectangle].getPosition().y + rectangles[indexOfRectangle].getSize().y);
}

