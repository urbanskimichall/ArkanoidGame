#include <iostream>
#include "ShootingBonus.h"

void ShootingBonus::drawGuns(sf::RenderWindow &window)
{
    window.draw(leftGun);
    window.draw(rightGun);
    for (const auto &[leftBullet, rightBullet, xBulletPosition, yBulletPosition]: bullets)
    {
        window.draw(leftBullet);
        window.draw(rightBullet);
    }
}

void ShootingBonus::setGunsPosition(float xPositionOfPlatform, float yPositionOfPlatform, float xSizeOfPlatform)
{
    leftGun.setPosition(xPositionOfPlatform, yPositionOfPlatform - gunSize);
    leftGun.setSize({gunSize, gunSize});
    leftGun.setFillColor({180, 0, 255});
    rightGun.setPosition(xPositionOfPlatform + xSizeOfPlatform - gunSize, yPositionOfPlatform - gunSize);
    rightGun.setSize({gunSize, gunSize});
    rightGun.setFillColor({180, 0, 255});

    counter++;
    std::cout << counter << std::endl;

    if (!isBulletFired && counter % 15 == 0)
    {
        sf::RectangleShape rightBullet;
        sf::RectangleShape leftBullet;
        rightBullet.setPosition(xPositionOfPlatform + xSizeOfPlatform - gunSize, yPositionOfPlatform - gunSize);
        rightBullet.setSize({bulletSize, bulletSize});
        rightBullet.setFillColor({180, 0, 255});
        isBulletFired = true;
        xRightBulletPosition = xPositionOfPlatform + xSizeOfPlatform - gunSize;

        leftBullet.setPosition(xPositionOfPlatform - gunSize, yPositionOfPlatform - gunSize);
        leftBullet.setSize({bulletSize, bulletSize});
        leftBullet.setFillColor({180, 0, 255});
        xLeftBulletPosition = xPositionOfPlatform - gunSize;
        yBulletPosition = yPositionOfPlatform - gunSize;

        bullets.emplace_back(std::make_tuple(leftBullet, rightBullet, xLeftBulletPosition, yBulletPosition));
    }
    else
    {
        for (auto &[leftBullet, rightBullet, xBulletPosition, yBulletPosition]: bullets)
        {
            yBulletPosition -= 5;
            leftBullet.setPosition(xBulletPosition, yBulletPosition);
            rightBullet.setPosition(xBulletPosition + xSizeOfPlatform, yBulletPosition);
        }
        if (counter % 15 == 14)
        {
            isBulletFired = false;
        }
    }

}
