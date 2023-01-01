#ifndef ARKANOID_BALLMOVEMENT_H
#define ARKANOID_BALLMOVEMENT_H

#include <vector>
#include "Platform.h"
#include "BallDirections.h"
#include "GameOver.h"

class BallMovement
{
public:
    BallMovement(float radiusOfBall);

    void fillUpSectorsValues(Platform &platform);

    std::pair<float, float>
    changePositionOfBall(Platform &platform, float currentXposition, float currentYposition, int xSizeOfWindow,
                         int ySizeOfWindow);

private:
    void checkCeilingTouch(float xOfBall, float yOfBall);

    void checkPlatformTouch(float xOfBall, float yOfBall, Platform &platform, int ySizeOfWindow);

    void checkLeftWallTouch(float xOfBall, float yOfBall);

    void checkRightWallTouch(float xOfBall, float yOfBall, int xSizeOfWindow);

    bool checkBallOnPlatform(float xOfBall, float yOfBall, Platform &platform, int ySizeOfWindow);

    std::pair<float, float> updateBallPosition(float currentXPosition, float currentYPosition);

    float radiusOfBall{0};
    const float numberOfSectors{20};
    int indexOfSector{0};
    std::vector<float> directionsOfBall{-0.1, -0.09, -0.08, -0.07, -0.06, -0.05, -0.04, -0.03, -0.02, -0.01, 0.0, 0.01,
                                        0.02, 0.03, 0.04, 0.05, 0.06, 0.07, 0.08, 0.09, 0.1};
    std::vector<float> sectorsOfPlatform{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    BallDirections ballDirections{BallDirections::UP_RIGHT};
    GameOver gameOver;

};

#endif //ARKANOID_BALLMOVEMENT_H
