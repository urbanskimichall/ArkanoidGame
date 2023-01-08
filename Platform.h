#ifndef ARKANOID_PLATFORM_H
#define ARKANOID_PLATFORM_H

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "ShootingBonus.h"

class Platform
{
public:
    Platform()
    {}

    Platform(float xSizeOfWindow, float ySizeOfWindow);

    sf::RectangleShape getPlatform();

    void setPlatformPosition(int xMousePosition);

    float getYOfPlatform();

    float getXOfPlatform();

    float getSizeXOfPlatform();

    float getSizeYOfPlatform();

    void drawPlatform(sf::RenderWindow &window);

    std::vector<std::tuple<sf::RectangleShape, float, float>> &getBullets();

    void setShootingBonusActiveFlag(bool isShootingActive);

    void setIsBiggerPlatformBonusActive(bool isPlatformBigger);

    void setIsSmallerPlatformBonusActive(bool isPlatformSmaller);

private:
    bool checkMousePosition(int xMousePosition);

    float sizeXofPlatform{100};
    float sizeYofPlatform{20};
    sf::RectangleShape platform;
    sf::Vector2f sizeOfPlatform{sizeXofPlatform, sizeYofPlatform};
    sf::Color colorOfPlatform{100, 200, 50};
    sf::Color colorOfOutline{200, 20, 110};
    float thicknessOfPlatform{4};
    float xSizeOfWindow{0};
    float ySizeOfWindow{0};
    float xOfPlatform{350};
    float yOfPlatform{ySizeOfWindow - 50};
    bool isShootingBonusActive{false};
    bool isBiggerPlatformBonusActive{false};
    bool isSmallerPlatformBonusActive{false};

    ShootingBonus shootingBonus;

    void clearBullets();
};

#endif //ARKANOID_PLATFORM_H
