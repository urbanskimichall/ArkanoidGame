#include <iostream>
#include "SmallerPlatform.h"

void SmallerPlatform::setUpBonusIcon(float xBall, float yBall)
{
    smallerPlatformTexture.loadFromFile("../Pictures/SmallerPlatform.png");
    smallerPlatformSprite.setTexture(smallerPlatformTexture);
    smallerPlatformSprite.setPosition(xBall, yBall);
}

void SmallerPlatform::activationOfBonus(std::vector<sf::RectangleShape> &rectangles, Platform &platform,
                                        std::vector<Ball> &balls)
{
    isActive = true;
    float currentYBonusIconPosition = smallerPlatformSprite.getPosition().y;
    float currentXBonusIconPosition = smallerPlatformSprite.getPosition().x;
    currentYBonusIconPosition += 2.7;
    smallerPlatformSprite.setPosition(currentXBonusIconPosition, currentYBonusIconPosition);
    std::cout << counterOfElapsedTimeUntilBallBonusWasActivated << std::endl;
    if (isBonusCaughtByPlatform(platform, currentXBonusIconPosition, currentYBonusIconPosition))
    {
        platform.setIsSmallerPlatformBonusActive(true);
    }
    if (counterOfElapsedTimeUntilBallBonusWasActivated == 1200 && isActive)
    {
        platform.setIsSmallerPlatformBonusActive(false);
        deactivationOfBonus();
    }
    else if (isActive)
    {
        counterOfElapsedTimeUntilBallBonusWasActivated++;
    }
}

void SmallerPlatform::deactivationOfBonus()
{
    counterOfElapsedTimeUntilBallBonusWasActivated = 0;
    isActive = false;
}

bool SmallerPlatform::isBonusActivated()
{
    return isActive && counterOfElapsedTimeUntilBallBonusWasActivated > 0;
}

void SmallerPlatform::drawBonus(sf::RenderWindow &window)
{
    window.draw(smallerPlatformSprite);
}
