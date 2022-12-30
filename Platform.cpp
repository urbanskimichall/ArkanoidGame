#include "Platform.h"

Platform::Platform(float xSizeOfWindow)
{
    this->xSizeOfWindow = xSizeOfWindow;
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
    return sizeXofPlatform;
}

float Platform::getSizeYOfPlatform()
{
    return sizeYofPlatform;
}
