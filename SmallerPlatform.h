#ifndef ARKANOID_SMALLERPLATFORM_H
#define ARKANOID_SMALLERPLATFORM_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "BonusInterface.h"

class SmallerPlatform : public BonusInterface
{
public:
    void setUpBonusIcon(float xBall, float yBall) override;

    void activationOfBonus(std::vector<sf::RectangleShape> &rectangles, Platform &platform,
                           std::vector<Ball> &balls) override;

    void deactivationOfBonus() override;

    void drawBonus(sf::RenderWindow &window) override;

    bool isBonusActivated() override;

private:
    sf::Texture smallerPlatformTexture;
    sf::Sprite smallerPlatformSprite;
    int counterOfElapsedTimeUntilBallBonusWasActivated{0};
    bool isActive{false};

};

#endif //ARKANOID_SMALLERPLATFORM_H
