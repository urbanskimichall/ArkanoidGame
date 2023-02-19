#include "Shooting.h"

void Shooting::setUpBonusIcon(float xBall, float yBall)
{
    shootingTexture.loadFromFile("../Pictures/Shooting.png");
    shootingSprite.setTexture(shootingTexture);
    shootingSprite.setPosition(xBall, yBall);
}

void
Shooting::activationOfBonus(std::vector<sf::RectangleShape> &rectangles, Platform &platform, std::vector<Ball> &balls)
{
    isActive = true;
    float currentYBonusIconPosition = shootingSprite.getPosition().y;
    float currentXBonusIconPosition = shootingSprite.getPosition().x;
    currentYBonusIconPosition += 2.7;
    shootingSprite.setPosition(currentXBonusIconPosition, currentYBonusIconPosition);
    if (isBonusCaughtByPlatform(platform, currentXBonusIconPosition, currentYBonusIconPosition))
    {
        platform.setShootingBonusActiveFlag(true);
    }
    if (counterOfElapsedTimeUntilBallBonusWasActivated == 1200 && isActive)
    {
        platform.setShootingBonusActiveFlag(false);
        deactivationOfBonus();
    }
    else if (isActive)
    {
        counterOfElapsedTimeUntilBallBonusWasActivated++;
    }
}

void Shooting::deactivationOfBonus()
{
    counterOfElapsedTimeUntilBallBonusWasActivated = 0;
    isActive = false;
}

void Shooting::drawBonus(sf::RenderWindow &window)
{
    window.draw(shootingSprite);
}

bool Shooting::isBonusActivated()
{
    return isActive && counterOfElapsedTimeUntilBallBonusWasActivated > 0;
}
