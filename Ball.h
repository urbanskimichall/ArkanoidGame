#ifndef ARKANOID_BALL_H
#define ARKANOID_BALL_H

#include <SFML/Graphics/CircleShape.hpp>
#include "Platform.h"
#include <vector>
#include"BallMovement.h"

class Ball
{
public:
    Ball();

    void setBallPosition(Platform &platform, int xSizeOfWindow, int ySizeOfWindow);

    sf::CircleShape getBall();

    bool isBallReleased{false};

private:
    sf::CircleShape ball;
    sf::Color colorOfBall{20, 40, 200};
    sf::Color outlineColorOfBall{20, 240, 140};
    float radius{10.f};
    float thickness{2.f};
    float currentXballPosition{0.f};
    float currentYballPosition{0.f};
    BallMovement ballMovement{radius};
};

#endif //ARKANOID_BALL_H
