
#ifndef ARKANOID_SHOOTING_H
#define ARKANOID_SHOOTING_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "BonusInterface.h"

class Shooting : public BonusInterface
{
public:
    void setUpBonusIcon(float xBall,float yBall) override;

    void activationOfBonus(std::vector<sf::RectangleShape> &rectangles, Platform &platform, std::vector<Ball> &balls) override;

    void deactivationOfBonus() override;

    void drawBonus(sf::RenderWindow &window) override;

    bool isBonusActivated() override;

private:
    sf::Texture shootingTexture;
    sf::Sprite shootingSprite;
    int counterOfElapsedTimeUntilBallBonusWasActivated{0};
    bool isActive{false};

};

#endif //ARKANOID_SHOOTING_H
