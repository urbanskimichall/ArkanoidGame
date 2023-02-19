#ifndef ARKANOID_BONUSINTERFACE_H
#define ARKANOID_BONUSINTERFACE_H

#include <SFML/Graphics/RectangleShape.hpp>
#include "Platform.h"
#include "Bonus.h"
#include "Ball.h"

class BonusInterface
{
public:
    virtual void setUpBonusIcon(float xBall, float yBall) = 0;

    virtual void deactivationOfBonus() = 0;

    virtual void
    activationOfBonus(std::vector<sf::RectangleShape> &rectangles, Platform &platform, std::vector<Ball> &balls) = 0;

    virtual bool isBonusActivated() = 0;

    virtual void drawBonus(sf::RenderWindow &window) = 0;

    bool isBonusCaughtByPlatform(Platform &platform, float xIconPosition, float yIconPosition)
    {
        return platform.getYOfPlatform() < yIconPosition &&
               platform.getXOfPlatform() < xIconPosition &&
               platform.getXOfPlatform() + platform.getSizeXOfPlatform() > xIconPosition;
    }

};

#endif //ARKANOID_BONUSINTERFACE_H
