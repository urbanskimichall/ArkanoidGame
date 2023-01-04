#ifndef ARKANOID_SHOOTINGBONUS_H
#define ARKANOID_SHOOTINGBONUS_H

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class ShootingBonus
{
public:

    void drawGuns(sf::RenderWindow &window);

    void setGunsPosition(float xPositionOfPlatform, float yPositionOfPlatform, float xSizeOfPlatform);

private:

    sf::RectangleShape leftGun;
    sf::RectangleShape rightGun;
    const float gunSize{10};
    sf::RectangleShape rightBullet;
    sf::RectangleShape leftBullet;
    const float bulletSize{6};
    float xRightBulletPosition{0};
    float xLeftBulletPosition{0};
    float yBulletPosition{0};
    bool isBulletFired{false};
    std::vector<std::tuple<sf::RectangleShape, sf::RectangleShape, float,float>> bullets;
    int counter{0};
};

#endif //ARKANOID_SHOOTINGBONUS_H
