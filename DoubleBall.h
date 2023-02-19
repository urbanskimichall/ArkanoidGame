#ifndef ARKANOID_DOUBLEBALL_H
#define ARKANOID_DOUBLEBALL_H

#include "BonusInterface.h"

class DoubleBall: public BonusInterface
{
public:
    void setUpBonusIcon(float xBall, float yBall) override;

    void activationOfBonus(std::vector<sf::RectangleShape> &rectangles, Platform &platform,
                           std::vector<Ball> &balls) override;

    void deactivationOfBonus() override;

    void drawBonus(sf::RenderWindow &window) override;

    bool isBonusActivated() override;

private:
    sf::Texture doubleBallTexture;
    sf::Sprite doubleBallSprite;
    int counterOfElapsedTimeUntilBallBonusWasActivated{0};
    bool isActive{false};

};

#endif //ARKANOID_DOUBLEBALL_H
