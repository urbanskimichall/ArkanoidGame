#ifndef ARKANOID_BALLMOVEMENT_H
#define ARKANOID_BALLMOVEMENT_H


#include <vector>
#include "Platform.h"

class BallMovement {
private:
    void checkCeilingTouch(float xOfBall, float yOfBall, Platform &platform);

    bool isLeftWallTouched{false};
    bool isRightWallTouched{false};
    bool isDirectionUp{true};
    float xOfBall{0};
    float yOfBall{0};
    const float numberOfSectors{20};
    int indexOfSector{0};
    std::vector<float> directionsOfBall{-0.1,-0.09,-0.08,-0.07,-0.06,-0.05,-0.04,-0.03,-0.02,-0.01,0.0, 0.01,
                                        0.02, 0.03, 0.04, 0.05, 0.06, 0.07, 0.08, 0.09, 0.1};
    std::vector<float> sectorsOfPlatform{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

public:
    void fillUpSectorsValues(Platform &platform);

    std::pair<float,float>changePositionOfBall(Platform &platform, float currentXposition, float currentYposition);


};


#endif //ARKANOID_BALLMOVEMENT_H
