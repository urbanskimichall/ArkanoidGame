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
#include "BonusInterface.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <map>
#include <memory>

class BonusManager
{
public:
    BonusManager(Blocks &blocks);

    void drawBonus(sf::RenderWindow &window);

    void generateBonus(std::vector<sf::RectangleShape> &rectangles, Platform &platform);

    void updateBonusIconPosition(Platform &platform, std::vector<sf::RectangleShape> &rectangles);

    std::vector<Ball> &getBalls();

private:
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
    int counterOfElapsedTimeUntilBallBonusWasActivated{0};
    std::vector<Ball> balls;
    std::vector<std::shared_ptr<BonusInterface>> bonuses;


};

#endif //ARKANOID_BONUSMANAGER_H
