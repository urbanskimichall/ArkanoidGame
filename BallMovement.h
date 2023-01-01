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

    void calculatePartOfPlatformWhereBallWasBounced(float xOfBall, Platform &platform);

    std::string printBallDirection(BallDirections ballDirections);


    float radiusOfBall{0};
    const float numberOfSectors{20};
    int indexOfSector{0};
    float ballBounceCoefficient{0.05f};
    std::vector<float> directionsOfBall{0.2, 0.17, 0.15, 0.12, 0.1, 0.07, 0.05, 0.03, 0.02, 0.0, 0.02, 0.03,
                                        0.05, 0.07, 0.1, 0.12, 0.15, 0.17, 0.19, 0.2};
    std::vector<float> sectorsOfPlatform{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    BallDirections ballDirections{BallDirections::UP_RIGHT};
    BallDirections prewiousState{BallDirections::UP_RIGHT};
    GameOver gameOver;

};

#endif //ARKANOID_BALLMOVEMENT_H
