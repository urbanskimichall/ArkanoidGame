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
    std::pair<float,float>ballCords;
    if (isBallReleased == false)
    {
        currentXballPosition = platform.getXOfPlatform() + 4 * radius;
        currentYballPosition = platform.getYOfPlatform() - 2.6 * radius;
        ball.setPosition(currentXballPosition, currentYballPosition);
    }
    else
    {
        ballCords=ballMovement.changePositionOfBall(platform,currentXballPosition,currentYballPosition);
        //setBallPositionDependOnPlatform(platform);
        currentXballPosition = ballCords.first;
        currentYballPosition = ballCords.second;
        ball.setPosition(ballCords.first, ballCords.second);
    }
}

sf::CircleShape Ball::getBall()
{
    return ball;
}

//void Ball::setBallPositionDependOnPlatform(Platform &platform)
//{
//    checkDirections(platform);
//    fillUpSectorsValues(platform);
//    updateBallPosition(platform);
//
//    ball.setPosition(xOfBall, yOfBall);
//}

//void Ball::checkDirections(Platform &platform)
//{
//
//    if (yOfBall < 0)
//    {
//        isDirectionUp = false;
//
//    }
//    else if (yOfBall > platform.getYOfPlatform() - 2 * radius)
//    {
//        indexOfSector = calculateSectorOfPickup();
//        std::cout<< "komunikat index: " << indexOfSector << std::endl;
////        for (auto element : sectorsOfPlatform)
////        {
////            std::cout<< "komunikat element: " << element<<" " ;
////        }std::cout << std::endl;
//
//        isDirectionUp = true;
//    }
//    if (xOfBall <= 0)
//    {
//        isLeftWallTouched = true;
//        std::cout << "Left wall touched" <<indexOfSector<<" "<<directionsOfBall[indexOfSector]<< std::endl;
//    }
//    else if (xOfBall > 800 - 2 * radius)
//    {
//        isLeftWallTouched = false;
//        std::cout << "Right wall touched" << std::endl;
//    }
//}
//
//void Ball::updateBallPosition(Platform &platform)
//{
//    if (isLeftWallTouched)
//    {
//        if (isDirectionUp && directionsOfBall[indexOfSector] < 0)
//        {
//            xOfBall -= directionsOfBall[indexOfSector];
//            yOfBall -= 0.1;
//        }
//        else if (isDirectionUp && directionsOfBall[indexOfSector] > 0)
//        {
//            xOfBall += directionsOfBall[indexOfSector];
//            yOfBall -= 0.1;
//        }
//        else if (!isDirectionUp && directionsOfBall[indexOfSector] < 0)
//        {
//            xOfBall += -directionsOfBall[indexOfSector];
//            yOfBall += 0.1;
//            std::cout<<"Weszlismy do 1 if "<<directionsOfBall[indexOfSector]<<std::endl;
//        }
//        else if (!isDirectionUp && directionsOfBall[indexOfSector] >= 0)
//        {
//            xOfBall -= directionsOfBall[indexOfSector];
//            yOfBall += 0.1;
//            std::cout<<"Weszlismy do 2 if "<<directionsOfBall[indexOfSector]<<std::endl;
//        }
//    }
//
//    else
//    {
//        if (isDirectionUp && directionsOfBall[indexOfSector] < 0)
//        {
//            xOfBall += directionsOfBall[indexOfSector];
//            yOfBall -= 0.1;
//        }
//        else if(isDirectionUp && directionsOfBall[indexOfSector] > 0)
//        {
//            xOfBall -= directionsOfBall[indexOfSector];
//            yOfBall -= 0.1;
//        }
//        else if(!isDirectionUp && directionsOfBall[indexOfSector] < 0)
//        {
//            xOfBall += directionsOfBall[indexOfSector];
//            yOfBall += 0.1;
//        }
//        else if(!isDirectionUp && directionsOfBall[indexOfSector] > 0)
//        {
//            xOfBall -= directionsOfBall[indexOfSector];
//            yOfBall += 0.1;
//        }
//
//    }
//}
//
//int Ball::calculateSectorOfPickup()
//{
//
//    for (int i = 0; i < sectorsOfPlatform.size(); ++i)
//    {
//        std::cout<<"xofball: " << xOfBall << " i: "<< i<< " sectors: " <<sectorsOfPlatform[i]<< std::endl;
//        if (xOfBall < sectorsOfPlatform[i] && xOfBall < sectorsOfPlatform.back())
//        {
//            return i;
//        }
//    }
//    return -1;
//}
