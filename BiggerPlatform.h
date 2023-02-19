//
// Created by urbmi on 19.02.2023.
//

#ifndef ARKANOID_BIGGERPLATFORM_H
#define ARKANOID_BIGGERPLATFORM_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "BonusInterface.h"

class BiggerPlatform : public BonusInterface
{
public:
    void setUpBonusIcon(float xBall, float yBall) override;

    void activationOfBonus(std::vector<sf::RectangleShape> &rectangles, Platform &platform,
                           std::vector<Ball> &balls) override;

    void deactivationOfBonus() override;

    void drawBonus(sf::RenderWindow &window) override;

    bool isBonusActivated() override;

private:
    sf::Texture biggerPlatformTexture;
    sf::Sprite biggerPlatformSprite;
    int counterOfElapsedTimeUntilBallBonusWasActivated{0};
    bool isActive{false};
};

#endif //ARKANOID_BIGGERPLATFORM_H
