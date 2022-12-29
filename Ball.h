#ifndef ARKANOID_BALL_H
#define ARKANOID_BALL_H


#include <SFML/Graphics/CircleShape.hpp>
#include "Platform.h"
#include <vector>

class Ball
{
public:
    Ball();

    void setBallPosition(Platform &platform);

    sf::CircleShape getBall();


    bool isBallReleased{false};

private:
    std::vector<float> directionsOfBall{-0.1,-0.09,-0.08,-0.07,-0.06,-0.05,-0.04,-0.03,-0.02,-0.01,0.0, 0.01,
                                        0.02, 0.03, 0.04, 0.05, 0.06, 0.07, 0.08, 0.09, 0.1};

    void checkDirections(Platform &platform);

    void updateBallPosition(Platform &platform);

    void setBallPositionDependOnPlatform(Platform &platform);

    void fillUpSectorsValues(Platform &platform);

    int calculateSectorOfPickup();

    sf::CircleShape ball;
    sf::Color colorOfBall{20, 40, 200};
    sf::Color outlineColorOfBall{20, 240, 140};
    float radius{10};
    float thickness{2};
    float xOfBall{0};
    float yOfBall{0};
    bool isDirectionUp{true};
    bool isLeftWallTouched{true};
    const float numberOfSectors{20};
    std::vector<float> sectorsOfPlatform{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int indexOfSector{0};

};


#endif //ARKANOID_BALL_H
