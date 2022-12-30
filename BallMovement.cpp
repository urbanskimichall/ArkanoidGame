#include "BallMovement.h"

void BallMovement::fillUpSectorsValues(Platform &platform)
{
    float sizeOfSector{0};
    sizeOfSector = platform.getSizeXOfPlatform() / numberOfSectors;
    for (int i = 0; i < numberOfSectors; ++i)
    {
        sectorsOfPlatform[i] = platform.getXOfPlatform() + sizeOfSector * i;
    }
}

std::pair<float,float> BallMovement::changePositionOfBall(Platform &platform, float currentXposition, float currentYposition)
{
    fillUpSectorsValues(platform);
    checkCeilingTouch(currentYposition);
    if(isDirectionUp)
    {
        currentXposition+=directionsOfBall[11];
        currentYposition-=0.1;
    }
    else
    {
        currentXposition-=directionsOfBall[11];
        currentYposition+=0.1;
    }


    return std::pair<float,float>(currentXposition,currentYposition);
}

void BallMovement::checkCeilingTouch(float yOfBall) {
    if(yOfBall<0)
    {
        isDirectionUp = false;

    }
}
