
#ifndef ARKANOID_SLOWERBALL_H
#define ARKANOID_SLOWERBALL_H

#include "BonusInterface.h"

class SlowerBall : public BonusInterface
{
public:
    void setUpBonusIcon(float xBall, float yBall) override;

    void activationOfBonus(std::vector<sf::RectangleShape> &rectangles, Platform &platform,
                           std::vector<Ball> &balls) override;

    void deactivationOfBonus() override;

    void drawBonus(sf::RenderWindow &window) override;

    bool isBonusActivated() override;

private:
    sf::Texture slowerBallTexture;
    sf::Sprite slowerBallSprite;
    int counterOfElapsedTimeUntilBallBonusWasActivated{0};
    bool isActive{false};
};

#endif //ARKANOID_SLOWERBALL_H
