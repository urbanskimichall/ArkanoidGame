//
// Created by urbmi on 19.02.2023.
//

#include <iostream>
#include "BiggerPlatform.h"

void BiggerPlatform::setUpBonusIcon(float xBall, float yBall)
{
    biggerPlatformTexture.loadFromFile("../Pictures/BiggerPlatform.png");
    biggerPlatformSprite.setTexture(biggerPlatformTexture);
    biggerPlatformSprite.setPosition(xBall, yBall);
}

void BiggerPlatform::activationOfBonus(std::vector<sf::RectangleShape> &rectangles, Platform &platform,
                                       std::vector<Ball> &balls)
{
    isActive = true;
    float currentYBonusIconPosition = biggerPlatformSprite.getPosition().y;
    float currentXBonusIconPosition = biggerPlatformSprite.getPosition().x;
    currentYBonusIconPosition += 2.7;
    biggerPlatformSprite.setPosition(currentXBonusIconPosition, currentYBonusIconPosition);
    if (isBonusCaughtByPlatform(platform, currentXBonusIconPosition, currentYBonusIconPosition))
    {
        platform.setIsBiggerPlatformBonusActive(true);
    }
    if (counterOfElapsedTimeUntilBallBonusWasActivated == 1200 && isActive)
    {
        platform.setIsBiggerPlatformBonusActive(false);
        deactivationOfBonus();
    }
    else if (isActive)
    {
        counterOfElapsedTimeUntilBallBonusWasActivated++;
    }
}

void BiggerPlatform::deactivationOfBonus()
{
    counterOfElapsedTimeUntilBallBonusWasActivated = 0;
    isActive = false;
}

bool BiggerPlatform::isBonusActivated()
{
    return isActive && counterOfElapsedTimeUntilBallBonusWasActivated > 0;
}

void BiggerPlatform::drawBonus(sf::RenderWindow &window)
{
    window.draw(biggerPlatformSprite);
}
