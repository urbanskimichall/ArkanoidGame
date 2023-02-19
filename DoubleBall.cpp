#include "DoubleBall.h"

void DoubleBall::setUpBonusIcon(float xBall, float yBall)
{
    doubleBallTexture.loadFromFile("../Pictures/DoubleBall.png");
    doubleBallSprite.setTexture(doubleBallTexture);
    doubleBallSprite.setPosition(xBall, yBall);
}

void
DoubleBall::activationOfBonus(std::vector<sf::RectangleShape> &rectangles, Platform &platform, std::vector<Ball> &balls)
{
    isActive = true;
    float currentYBonusIconPosition = doubleBallSprite.getPosition().y;
    float currentXBonusIconPosition = doubleBallSprite.getPosition().x;
    currentYBonusIconPosition += 2.7;
    doubleBallSprite.setPosition(currentXBonusIconPosition, currentYBonusIconPosition);
    if (isBonusCaughtByPlatform(platform, currentXBonusIconPosition, currentYBonusIconPosition))
    {
        if (balls.size() <= 1)
        {
            Ball ball2(rectangles, BallDirections::UP_LEFT);
            balls.push_back(ball2);
        }
    }
    if (counterOfElapsedTimeUntilBallBonusWasActivated == 1200 && isActive)
    {
        deactivationOfBonus();
        balls.pop_back();
        counterOfElapsedTimeUntilBallBonusWasActivated = 0;
    }
    else if (isActive)
    {
        counterOfElapsedTimeUntilBallBonusWasActivated++;
    }
}

void DoubleBall::deactivationOfBonus()
{

    counterOfElapsedTimeUntilBallBonusWasActivated = 0;
    isActive = false;
}

void DoubleBall::drawBonus(sf::RenderWindow &window)
{
    window.draw(doubleBallSprite);
}

bool DoubleBall::isBonusActivated()
{
    return isActive && counterOfElapsedTimeUntilBallBonusWasActivated > 0;
}
