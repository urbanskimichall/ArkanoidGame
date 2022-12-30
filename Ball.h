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

    void setBallPosition(Platform &platform);

    sf::CircleShape getBall();


    bool isBallReleased{false};

private:
     void checkDirections(Platform &platform);

    void updateBallPosition(Platform &platform);

    void setBallPositionDependOnPlatform(Platform &platform);

    void fillUpSectorsValues(Platform &platform);

    int calculateSectorOfPickup();

    sf::CircleShape ball;
    sf::Color colorOfBall{20, 40, 200};
    sf::Color outlineColorOfBall{20, 240, 140};
    float radius{10.f};
    float thickness{2.f};
    float currentXballPosition{0.f};
    float currentYballPosition{0.f};
    BallMovement ballMovement;

};


#endif //ARKANOID_BALL_H
