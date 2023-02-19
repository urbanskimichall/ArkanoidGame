#include "FasterBall.h"
#include "Ball.h"

void FasterBall::setUpBonusIcon(float xBall, float yBall)
{
    fasterBallTexture.loadFromFile("../Pictures/FasterBall.png");
    fasterBallSprite.setTexture(fasterBallTexture);
    fasterBallSprite.setPosition(xBall, yBall);
}

void
FasterBall::activationOfBonus(std::vector<sf::RectangleShape> &rectangles, Platform &platform, std::vector<Ball> &balls)
{
    isActive = true;
    float currentYBonusIconPosition = fasterBallSprite.getPosition().y;
    float currentXBonusIconPosition = fasterBallSprite.getPosition().x;
    currentYBonusIconPosition += 2.7;
    fasterBallSprite.setPosition(currentXBonusIconPosition, currentYBonusIconPosition);
    if (isBonusCaughtByPlatform(platform, currentXBonusIconPosition, currentYBonusIconPosition))
    {
        for (int i = 0; i < balls.size(); i++)
        {
            balls[i].setBallSpeed(75);
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

void FasterBall::deactivationOfBonus()
{
    counterOfElapsedTimeUntilBallBonusWasActivated = 0;
    isActive = false;
}

void FasterBall::drawBonus(sf::RenderWindow &window)
{
    window.draw(fasterBallSprite);
}

bool FasterBall::isBonusActivated()
{
    return isActive && counterOfElapsedTimeUntilBallBonusWasActivated > 0;
}
