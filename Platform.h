#ifndef ARKANOID_PLATFORM_H
#define ARKANOID_PLATFORM_H
#include <SFML/Graphics/RectangleShape.hpp>

class Platform
{
public:
    Platform(float xSizeOfWindow);

    sf::RectangleShape getPlatform();

    void setPlatformPosition(int xMousePosition);

    float getYOfPlatform();
    float getXOfPlatform();
    float getSizeXOfPlatform();
private:
    bool checkMousePosition(int xMousePosition);

    sf::RectangleShape platform;
    sf::Vector2f sizeOfPlatform{100,20};
    sf::Color colorOfPlatform{100,200,50};
    sf::Color colorOfOutline{200,20,110};
    float xOfPlatform{350};
    float yOfPlatform{550};
    float thicknessOfPlatform{4};
    float xSizeOfWindow{0};
    float sizeXofPlatform{100};



};


#endif //ARKANOID_PLATFORM_H
