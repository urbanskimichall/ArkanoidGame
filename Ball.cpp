#include <iostream>
#include "Ball.h"

Ball::Ball(std::vector<sf::RectangleShape> &rectangles, BallDirections ballDirections)
{
    this->ballDirections1=ballDirections;
    this->rectangles = rectangles;
    ball.setRadius(radius);
    ball.setFillColor(colorOfBall);
    ball.setOutlineColor(outlineColorOfBall);
    ball.setOutlineThickness(thickness);
}

void Ball::setBallPosition(Platform &platform, int xSizeOfWindow, int ySizeOfWindow,
                           std::vector<sf::RectangleShape> &rectangles1)
{
    std::tuple<float, float, bool> ballCords;
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
        currentXballPosition = std::get<0>(ballCords);
        currentYballPosition = std::get<1>(ballCords);
        ball.setPosition(std::get<0>(ballCords), std::get<1>(ballCords));
        if(std::get<2>(ballCords))
        {
            isBonusDropped=true;
        }
       // bonusManager.updateBonusIconPosition(platform);
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

void Ball::drawBonus(sf::RenderWindow &window)
{
    //bonusManager.drawBonus(window);
}

bool Ball::isDoubleBallActive()
{
//    for(const auto [bonus,activationState] : bonusManager.getBonuses())
//    {
//        if(bonus==Bonus::DOUBLE_BALL && activationState)
//        {
//            return true;
//        }
//    }
//    std::cout << "isDoubleballactive false" << std::endl;
    return false;
}

void Ball::setBallReleased(bool b)
{
    isBallReleased = b;
}

bool Ball::getIsBonusDropped()
{
    return isBonusDropped;
}

std::pair<float, float> Ball::getXYofBall()
{
    return std::pair<float, float>(currentXballPosition,currentYballPosition);
}

void Ball::setIsBonusDropped(bool changedBonusDroppedFlag)
{
    isBonusDropped=changedBonusDroppedFlag;
}
