#include "SlowerBall.h"

void SlowerBall::setUpBonusIcon(float xBall, float yBall)
{
    slowerBallTexture.loadFromFile("../Pictures/SlowerBall.png");
    slowerBallSprite.setTexture(slowerBallTexture);
    slowerBallSprite.setPosition(xBall, yBall);
}

void
SlowerBall::activationOfBonus(std::vector<sf::RectangleShape> &rectangles, Platform &platform, std::vector<Ball> &balls)
{
    isActive = true;
    float currentYBonusIconPosition = slowerBallSprite.getPosition().y;
    float currentXBonusIconPosition = slowerBallSprite.getPosition().x;
    currentYBonusIconPosition += 2.7;
    slowerBallSprite.setPosition(currentXBonusIconPosition, currentYBonusIconPosition);
    if (isBonusCaughtByPlatform(platform, currentXBonusIconPosition, currentYBonusIconPosition))
    {
        for (int i = 0; i < balls.size(); i++)
        {
            balls[i].setBallSpeed(25);
        }
    }
    if (counterOfElapsedTimeUntilBallBonusWasActivated == 1200 && isActive)
    {
        deactivationOfBonus();
        for (int i = 0; i < balls.size(); i++)
        {
            balls[i].setBallSpeed(50);
        }
    }
    else if (isActive)
    {
        counterOfElapsedTimeUntilBallBonusWasActivated++;
    }
}

void SlowerBall::deactivationOfBonus()
{
    counterOfElapsedTimeUntilBallBonusWasActivated = 0;
    isActive = false;
}

void SlowerBall::drawBonus(sf::RenderWindow &window)
{
    window.draw(slowerBallSprite);
}

bool SlowerBall::isBonusActivated()
{
    return isActive && counterOfElapsedTimeUntilBallBonusWasActivated > 0;
}
