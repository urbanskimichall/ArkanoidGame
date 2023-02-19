#include <iostream>
#include "Platform.h"

Platform::Platform(float xSizeOfWindow, float ySizeOfWindow)
{
    this->xSizeOfWindow = xSizeOfWindow;
    this->ySizeOfWindow = ySizeOfWindow;
    yOfPlatform = ySizeOfWindow - 50;
    platform.setPosition(xOfPlatform, yOfPlatform);
    platform.setSize(sizeOfPlatform);
    platform.setFillColor(colorOfPlatform);
    platform.setOutlineThickness(thicknessOfPlatform);
    platform.setOutlineColor(colorOfOutline);
}

sf::RectangleShape Platform::getPlatform()
{
    return platform;
}

void Platform::setPlatformPosition(int xMousePosition)
{
    if (checkMousePosition(xMousePosition))
    {
        xOfPlatform = xMousePosition - sizeOfPlatform.x / 2;
        platform.setPosition(xOfPlatform, yOfPlatform);
        if (isShootingBonusActive)
        {
            shootingBonus.setGunsPosition(xOfPlatform, yOfPlatform, sizeXofPlatform);
        }

    }
    if (isBiggerPlatformBonusActive)
    {
        sizeOfPlatform = {sizeXofPlatform * 2, sizeYofPlatform};
        platform.setSize(sizeOfPlatform);
    }
    if (isSmallerPlatformBonusActive)
    {
        sizeOfPlatform = {sizeXofPlatform / 2, sizeYofPlatform};
        platform.setSize(sizeOfPlatform);
    }
    else if (!isSmallerPlatformBonusActive && !isBiggerPlatformBonusActive)
    {
        sizeOfPlatform = {sizeXofPlatform, sizeYofPlatform};
        platform.setSize(sizeOfPlatform);
    }
}

bool Platform::checkMousePosition(int xMousePosition)
{
    return xMousePosition > 0 + sizeOfPlatform.x / 2 + thicknessOfPlatform &&
           xMousePosition < xSizeOfWindow - sizeOfPlatform.x / 2 - thicknessOfPlatform;
}

float Platform::getYOfPlatform()
{
    return yOfPlatform;
}

float Platform::getXOfPlatform()
{
    return xOfPlatform;
}

float Platform::getSizeXOfPlatform()
{
    return sizeOfPlatform.x;
}

float Platform::getSizeYOfPlatform()
{
    return sizeYofPlatform;
}

void Platform::drawPlatform(sf::RenderWindow &window)
{
    window.draw(platform);
    if (isShootingBonusActive)
    {
        shootingBonus.drawGuns(window);
    }

}

std::vector<std::tuple<sf::RectangleShape, float, float>> &Platform::getBullets()
{
    return shootingBonus.getBullets();
}

void Platform::setShootingBonusActiveFlag(bool isShootingActive)
{
    this->isShootingBonusActive = isShootingActive;
    if (!isShootingActive)
    {
        clearBullets();
    }

}

void Platform::clearBullets()
{
    getBullets().clear();
}

void Platform::setIsBiggerPlatformBonusActive(bool isPlatformBigger)
{
    this->isBiggerPlatformBonusActive = isPlatformBigger;
}

void Platform::setIsSmallerPlatformBonusActive(bool isPlatformSmaller)
{
    this->isSmallerPlatformBonusActive = isPlatformSmaller;
}
