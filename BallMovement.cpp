#include <iostream>
#include "BallMovement.h"

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
BallMovement::changePositionOfBall(Platform &platform, float currentXposition, float currentYposition)
{
    fillUpSectorsValues(platform);
    checkCeilingTouch(currentXposition, currentYposition, platform);

    if (isDirectionUp && !isRightWallTouched)
    {
        currentXposition += directionsOfBall[14];
        currentYposition -= 0.1;
    }
    else if (isDirectionUp && isRightWallTouched)
    {
        currentXposition += directionsOfBall[6];
        currentYposition -= 0.1;
    }
    else if (!isDirectionUp && isRightWallTouched)
    {
        currentXposition += directionsOfBall[6];
        currentYposition += 0.1;
        std::cout << "Jestem w trzecim ifie" << std::endl;
    }
    else if (isDirectionUp && !isLeftWallTouched)
    {
        currentXposition += directionsOfBall[6];
        currentYposition += 0.1;
    }
    else if (!isDirectionUp)
    {
        currentXposition -= directionsOfBall[6];
        currentYposition += 0.1;
        std::cout << "Jestem w czwartym ifie" << std::endl;
    }
    return std::pair<float, float>(currentXposition, currentYposition);
}

void BallMovement::checkCeilingTouch(float xOfBall, float yOfBall, Platform &platform) //do zmiany
{
    if (yOfBall < 0)
    {
        isDirectionUp = false;
    }
    else if (!isDirectionUp && yOfBall > platform.getYOfPlatform() - platform.getSizeYOfPlatform())
    {
        isDirectionUp = true;
    }
    if (xOfBall > 800)
    {
        isRightWallTouched = true;
    }
    if (xOfBall < 0)
    {
        isLeftWallTouched = true;
    }
}
