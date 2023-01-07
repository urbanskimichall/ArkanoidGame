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
}

void BonusManager::generateBonus(std::vector<sf::RectangleShape> &rectangles, Platform &platform)
{
    for (auto &ball: balls)
    {
        if (ball.getIsBonusDropped())
        {
            const unsigned long long int numberOfRectangles{rectangles.size()};

            counterOfRemovedRectangles++;
            if (counterOfRemovedRectangles % 3 == 1)
            {
                std::cout << "bonus is coming" << std::endl;
                auto iter = bonuses.find(static_cast<Bonus>(3));
                if (iter == bonuses.end())
                {
                    doubleBallSprite.setPosition(ball.getXYofBall().first, ball.getXYofBall().second);
                    bonuses[static_cast<Bonus>(3)] = false;
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
}

void BonusManager::updateBonusIconPosition(Platform &platform, std::vector<sf::RectangleShape> &rectangles)
{
    for (auto [bonus, activationState]: bonuses)
    {
        switch (bonus)
        {
        case Bonus::DOUBLE_BALL:

            float currentYBonusIconPosition = doubleBallSprite.getPosition().y;
            float currentXBonusIconPosiotion = doubleBallSprite.getPosition().x;
            currentYBonusIconPosition += 0.7;
            doubleBallSprite.setPosition(currentXBonusIconPosiotion, currentYBonusIconPosition);
            if (platform.getYOfPlatform() < currentYBonusIconPosition &&
                platform.getXOfPlatform() < currentXBonusIconPosiotion &&
                platform.getXOfPlatform() + platform.getSizeXOfPlatform() > currentXBonusIconPosiotion)
            {
                bonuses[bonus] = true;
                if (counterOfGeneratedBalls < 1)
                {
                    Ball ball2(rectangles, BallDirections::UP_LEFT);
                    balls.push_back(ball2);
                }
                counterOfGeneratedBalls++;
                std::cout << "bonus przejety" << std::endl;
            }

            if (counterOfElapsedTimeUntilBallBonusWasActivated == 1200 && bonuses[bonus] == true)
            {
                bonuses[bonus] = false;
                std::cout << bonuses.size() << std::endl;
                balls.pop_back();
                bonuses.erase({Bonus::DOUBLE_BALL});
            }
            else
            {
                counterOfElapsedTimeUntilBallBonusWasActivated++;
            }
//            if (bonuses[bonus])
//            {
//                counterOfElapsedTimeUntilBallBonusWasActivated++;
//            }

            break;

        }
    }
}

std::map<Bonus, bool> &BonusManager::getBonuses()
{
    return bonuses;
}

BonusManager::BonusManager()
{

}

std::vector<Ball> &BonusManager::getBalls()
{
    return balls;
}
