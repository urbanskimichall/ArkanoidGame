
#ifndef ARKANOID_FASTERBALL_H
#define ARKANOID_FASTERBALL_H

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "BonusInterface.h"
#include "Ball.h"

class FasterBall : public BonusInterface
{
public:
    void setUpBonusIcon(float xBall, float yBall) override;

    void activationOfBonus(std::vector<sf::RectangleShape> &rectangles, Platform &platform,
                           std::vector<Ball> &balls) override;

    void deactivationOfBonus() override;

    void drawBonus(sf::RenderWindow &window) override;

    bool isBonusActivated() override;

private:
    sf::Texture fasterBallTexture;
    sf::Sprite fasterBallSprite;
    int counterOfElapsedTimeUntilBallBonusWasActivated{0};
    bool isActive{false};

};

#endif //ARKANOID_FASTERBALL_H
