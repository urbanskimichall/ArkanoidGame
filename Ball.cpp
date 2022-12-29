#include <iostream>
#include "Ball.h"

Ball::Ball()
{
    ball.setRadius(radius);
    ball.setFillColor(colorOfBall);
    ball.setOutlineColor(outlineColorOfBall);
    ball.setOutlineThickness(thickness);
}

void Ball::setBallPosition(Platform &platform)
{

    if (isBallReleased == false)
    {
        xOfBall = platform.getXOfPlatform() + 4 * radius;
        yOfBall = platform.getYOfPlatform() - 2.6 * radius;
        ball.setPosition(xOfBall, yOfBall);
    }
    else
    {
        setBallPositionDependOnPlatform(platform);
    }
}

sf::CircleShape Ball::getBall()
{
    return ball;
}

void Ball::setBallPositionDependOnPlatform(Platform &platform)
{
    checkDirections(platform);
    fillUpSectorsValues(platform);
    updateBallPosition(platform);

    ball.setPosition(xOfBall, yOfBall);
}

void Ball::checkDirections(Platform &platform)
{

    if (yOfBall < 0)
    {
        isDirectionUp = false;

    }
    else if (yOfBall > platform.getYOfPlatform() - 2 * radius)
    {
        indexOfSector = calculateSectorOfPickup();
        std::cout<< "komunikat index: " << indexOfSector << std::endl;
//        for (auto element : sectorsOfPlatform)
//        {
//            std::cout<< "komunikat element: " << element<<" " ;
//        }std::cout << std::endl;

        isDirectionUp = true;
    }
    if (xOfBall <= 0)
    {
        isLeftWallTouched = true;
        std::cout << "Left wall touched" << std::endl;
    }
    else if (xOfBall > 800 - 2 * radius)
    {
        isLeftWallTouched = false;
        std::cout << "Right wall touched" << std::endl;
    }
}

void Ball::updateBallPosition(Platform &platform)
{
    if (isLeftWallTouched)
    {
        if (isDirectionUp && directionsOfBall[indexOfSector] < 0)
        {
            xOfBall -= directionsOfBall[indexOfSector];
            yOfBall -= 0.1;
        }
        else if (isDirectionUp && directionsOfBall[indexOfSector] > 0)
        {
            xOfBall += directionsOfBall[indexOfSector];
            yOfBall -= 0.1;
        }
        else if (!isDirectionUp && directionsOfBall[indexOfSector] < 0)
        {
            xOfBall += directionsOfBall[indexOfSector];
            yOfBall += 0.1;
        }
        else if (!isDirectionUp && directionsOfBall[indexOfSector] > 0)
        {
            xOfBall -= directionsOfBall[indexOfSector];
            yOfBall += 0.1;
        }
    }

    else
    {
        if (isDirectionUp && directionsOfBall[indexOfSector] < 0)
        {
            xOfBall += directionsOfBall[indexOfSector];
            yOfBall -= 0.1;
        }
        else if(isDirectionUp && directionsOfBall[indexOfSector] > 0)
        {
            xOfBall -= directionsOfBall[indexOfSector];
            yOfBall -= 0.1;
        }
        else if(!isDirectionUp && directionsOfBall[indexOfSector] < 0)
        {
            xOfBall += directionsOfBall[indexOfSector];
            yOfBall += 0.1;
        }
        else if(!isDirectionUp && directionsOfBall[indexOfSector] > 0)
        {
            xOfBall -= directionsOfBall[indexOfSector];
            yOfBall += 0.1;
        }

    }
}

void Ball::fillUpSectorsValues(Platform &platform)
{
    float sizeOfSector{0};
    sizeOfSector = platform.getSizeXOfPlatform() / numberOfSectors;
    for (int i = 0; i < numberOfSectors; ++i)
    {
        sectorsOfPlatform[i] = platform.getXOfPlatform() + sizeOfSector * i;
    }
}

int Ball::calculateSectorOfPickup()
{

    for (int i = 0; i < sectorsOfPlatform.size(); ++i)
    {
        std::cout<<"xofball: " << xOfBall << " i: "<< i<< " sectors: " <<sectorsOfPlatform[i]<< std::endl;
        if (xOfBall < sectorsOfPlatform[i] && xOfBall < sectorsOfPlatform.back())
        {
            return i;
        }
    }
    return -1;
}