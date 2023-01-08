#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>
#include "BonusManager.h"
#include "Blocks.h"

BonusManager::BonusManager(Blocks &blocks)
{
    Ball ball(blocks.getBlock(), BallDirections::UP_RIGHT);
    balls.push_back(ball);
//    Ball ball2(blocks.getBlock(), BallDirections::UP_LEFT);
//    balls.push_back(ball2);
//    Ball ball3(blocks.getBlock(), BallDirections::UP_RIGHT);
//    balls.push_back(ball3);
//    Ball ball4(blocks.getBlock(), BallDirections::UP_LEFT);
//    balls.push_back(ball4);
    setUpDoubleBallBonusIcon();
    setUpShootingBonusIcon();
}

void BonusManager::generateBonus(std::vector<sf::RectangleShape> &rectangles, Platform &platform)
{
    for (auto &ball: balls)
    {
        if (ball.getIsBonusDropped())
        {
            counterOfRemovedRectangles++;
            if (counterOfRemovedRectangles % 3 == 1)
            {
                auto iter = bonuses.find(static_cast<Bonus>(4));
                if (iter == bonuses.end())
                {
                    shootingSprite.setPosition(ball.getXYofBall().first, ball.getXYofBall().second);
                    bonuses[static_cast<Bonus>(4)] = false;
                }
            }
        }
        ball.setIsBonusDropped(false);
    }
    updateBonusIconPosition(platform, rectangles);
}

void BonusManager::setUpDoubleBallBonusIcon()
{
    doubleBallTexture.loadFromFile("../Pictures/DoubleBall.png");
    doubleBallSprite.setTexture(doubleBallTexture);
    doubleBallSprite.setPosition(-200, -200);
}

void BonusManager::drawBonus(sf::RenderWindow &window)
{
    window.draw(doubleBallSprite);
    window.draw(shootingSprite);
}

void BonusManager::updateBonusIconPosition(Platform &platform, std::vector<sf::RectangleShape> &rectangles)
{
    for (auto [bonus, activationState]: bonuses)
    {
        switch (bonus)
        {
        case Bonus::DOUBLE_BALL:
        {
            float currentYBonusIconPosition = doubleBallSprite.getPosition().y;
            float currentXBonusIconPosition = doubleBallSprite.getPosition().x;
            currentYBonusIconPosition += 2.7;
            doubleBallSprite.setPosition(currentXBonusIconPosition, currentYBonusIconPosition);
            if (isBonusCaughtByPlatform(platform, currentXBonusIconPosition, currentYBonusIconPosition))
            {
                activationOfDoubleBallBonus(bonus, rectangles);
            }
            if (counterOfElapsedTimeUntilBallBonusWasActivated == 1200 && bonuses[bonus])
            {
                deactivationOfDoubleBall(bonus);
            }
            else if (bonuses[bonus])
            {
                counterOfElapsedTimeUntilBallBonusWasActivated++;
            }
            break;
        }

        case Bonus::SHOOTING:
        {
            float currentYBonusIconPosition = shootingSprite.getPosition().y;
            float currentXBonusIconPosition = shootingSprite.getPosition().x;
            currentYBonusIconPosition += 2.7;
            shootingSprite.setPosition(currentXBonusIconPosition, currentYBonusIconPosition);
            std::cout << counterOfElapsedTimeUntilBallBonusWasActivated << std::endl;
            if (isBonusCaughtByPlatform(platform, currentXBonusIconPosition, currentYBonusIconPosition))
            {
                bonuses[bonus] = true;
                platform.setShootingBonusActiveFlag(true);
            }
            if (counterOfElapsedTimeUntilBallBonusWasActivated == 1200 && bonuses[bonus])
            {
                platform.setShootingBonusActiveFlag(false);
                deactivationOfShootingBonus(bonus);
            }
            else if (bonuses[bonus])
            {
                counterOfElapsedTimeUntilBallBonusWasActivated++;
            }
            break;
        }

        default:
            break;
        }
    }
}

std::map<Bonus, bool> &BonusManager::getBonuses()
{
    return bonuses;
}

std::vector<Ball> &BonusManager::getBalls()
{
    return balls;
}

void BonusManager::deactivationOfDoubleBall(Bonus bonus)
{
    bonuses[bonus] = false;
    std::cout << bonuses.size() << std::endl;
    balls.pop_back();
    bonuses.erase({Bonus::DOUBLE_BALL});
    counterOfGeneratedBalls = 0;
    counterOfElapsedTimeUntilBallBonusWasActivated = 0;
}

void BonusManager::deactivationOfShootingBonus(Bonus bonus)
{
    bonuses[bonus] = false;
    bonuses.erase({Bonus::SHOOTING});
    counterOfGeneratedBalls = 0;
    counterOfElapsedTimeUntilBallBonusWasActivated = 0;
}


void BonusManager::activationOfDoubleBallBonus(const Bonus bonus, std::vector<sf::RectangleShape> &rectangles)
{
    bonuses[bonus] = true;
    if (counterOfGeneratedBalls < 1)
    {
        Ball ball2(rectangles, BallDirections::UP_LEFT);
        balls.push_back(ball2);
    }
    counterOfGeneratedBalls++;
}

bool BonusManager::isBonusCaughtByPlatform(Platform &platform, float xIconPosition, float yIconPosition)
{
    return platform.getYOfPlatform() < yIconPosition &&
           platform.getXOfPlatform() < xIconPosition &&
           platform.getXOfPlatform() + platform.getSizeXOfPlatform() > xIconPosition;
}

void BonusManager::setUpShootingBonusIcon()
{
    shootingTexture.loadFromFile("../Pictures/Shooting.png");
    shootingSprite.setTexture(shootingTexture);
    shootingSprite.setPosition(-200, -200);
}
