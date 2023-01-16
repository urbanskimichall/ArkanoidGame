#ifndef ARKANOID_BONUSMANAGER_H
#define ARKANOID_BONUSMANAGER_H

#include <vector>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "Bonus.h"
#include "Platform.h"
#include "Ball.h"
#include "Blocks.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <map>

class BonusManager
{
public:
    BonusManager(Blocks &blocks);

    void drawBonus(sf::RenderWindow &window);

    void generateBonus(std::vector<sf::RectangleShape> &rectangles, Platform &platform);

    void updateBonusIconPosition(Platform &platform, std::vector<sf::RectangleShape> &rectangles);

    std::map<Bonus, bool> &getBonuses();

    std::vector<Ball> &getBalls();

private:
    void setUpDoubleBallBonusIcon();

    void setUpShootingBonusIcon();

    void setUpSmallerPlatformBonusIcon();

    void setUpBiggerPlatformBonusIcon();

    void setUpFasterBallBonusIcon();

    void setUpSlowerBallBonusIcon();

    void deactivationOfDoubleBall(Bonus bonus);

    void deactivationOfBiggerPlatform(Bonus bonus);

    void deactivationOfShooting(Bonus bonus);

    void deactivationOfSmallerPlatform(const Bonus bonus);

    void deactivationOfFasterBall(const Bonus bonus);

    void activationOfDoubleBallBonus(const Bonus, std::vector<sf::RectangleShape> &rectangles);

    bool isBonusCaughtByPlatform(Platform &platform, float xIconPosition, float yIconPosition);

    int counterOfRemovedRectangles{0};
    sf::Sprite doubleBallSprite;
    sf::Texture doubleBallTexture;
    sf::Sprite shootingSprite;
    sf::Texture shootingTexture;
    sf::Texture biggerPlatformTexture;
    sf::Sprite biggerPlatformSprite;
    sf::Texture smallerPlatformTexture;
    sf::Sprite smallerPlatformSprite;
    sf::Texture fasterBallTexture;
    sf::Sprite fasterBallSprite;
    sf::Texture slowerBallTexture;
    sf::Sprite slowerBallSprite;
    std::map<Bonus, bool> bonuses;
    int counterOfElapsedTimeUntilBallBonusWasActivated{0};
    std::vector<Ball> balls;
    int counterOfGeneratedBalls{0};

    void deactivationOfSlowerBall(const Bonus bonus);
};

#endif //ARKANOID_BONUSMANAGER_H
