#include <iostream>
#include "ShootingBonus.h"

void ShootingBonus::drawGuns(sf::RenderWindow &window)
{
    window.draw(leftGun);
    window.draw(rightGun);
    for (const auto &[bullet, xBulletPosition, yBulletPosition]: bullets)
    {
        window.draw(bullet);
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

    if (!isBulletFired && counter % bulletSpeed == 0)
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

        bullets.emplace_back(std::make_tuple(leftBullet, xLeftBulletPosition, yBulletPosition));
        bullets.emplace_back(std::make_tuple(rightBullet, xLeftBulletPosition + xSizeOfPlatform, yBulletPosition));
    }
    else
    {
        int i{0};
        for (auto &[bullet, xBulletPosition, yBulletPosition]: bullets)
        {
            yBulletPosition -= 5;
            if (i % 2 == 0)
            {
                bullet.setPosition(xBulletPosition, yBulletPosition);
            }
            else
            {
                bullet.setPosition(xBulletPosition + xSizeOfPlatform, yBulletPosition);
            }
        }
        if (counter % bulletSpeed == bulletSpeed - 1)
        {
            isBulletFired = false;
        }
    }

}

std::vector<std::tuple<sf::RectangleShape, float, float>> &ShootingBonus::getBullets()
{
    return bullets;
}
