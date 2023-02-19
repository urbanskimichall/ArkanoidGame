#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>
#include "BonusManager.h"
#include "Blocks.h"
#include "SmallerPlatform.h"
#include "BiggerPlatform.h"
#include "Shooting.h"
#include "FasterBall.h"
#include "SlowerBall.h"
#include "DoubleBall.h"
#include <random>

BonusManager::BonusManager(Blocks &blocks)
{
    Ball ball(blocks.getBlock(), BallDirections::UP_RIGHT);
    balls.push_back(ball);
}

void BonusManager::generateBonus(std::vector<sf::RectangleShape> &rectangles, Platform &platform)
{
    for (auto &ball: balls)
    {
        if (ball.getIsBonusDropped())
        {
            std::random_device rd; // obtain a random number from hardware
            std::mt19937 gen(rd()); // seed the generator
            std::uniform_int_distribution<> distr(1, 6);
            std::cout << distr(gen) << std::endl;
            auto biggerPlatform = std::make_shared<DoubleBall>();
            biggerPlatform->setUpBonusIcon(ball.getXYofBall().first, ball.getXYofBall().second);
            bonuses.push_back(biggerPlatform);
            counterOfRemovedRectangles++;
        }
        ball.setIsBonusDropped(false);
    }
    updateBonusIconPosition(platform, rectangles);
}

void BonusManager::drawBonus(sf::RenderWindow &window)
{
    for (auto bonus: bonuses)
    {
        bonus->drawBonus(window);
    }
}

void BonusManager::updateBonusIconPosition(Platform &platform, std::vector<sf::RectangleShape> &rectangles)
{
    for (auto bonus: bonuses)
    {
        bonus->activationOfBonus(rectangles, platform, balls);
    }
}

std::vector<Ball> &BonusManager::getBalls()
{
    return balls;
}





