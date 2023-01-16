#ifndef ARKANOID_BALL_H
#define ARKANOID_BALL_H

#include <SFML/Graphics/CircleShape.hpp>
#include "Platform.h"
#include <vector>
#include"BallMovement.h"

class Ball
{
public:
    Ball(std::vector<sf::RectangleShape> &rectangles, BallDirections ballDirections);


    void setBallPosition(Platform &platform, int xSizeOfWindow, int ySizeOfWindow,
                         std::vector<sf::RectangleShape> &rectangles);

    sf::CircleShape getBall();

    bool isBallReleased{false};

    std::vector<sf::RectangleShape> &getLeftBlocks();

    void setRectangles(std::vector<sf::RectangleShape> &rect);

    void drawBonus(sf::RenderWindow &window);

    bool isDoubleBallActive();

    void setBallReleased(bool b);

    bool getIsBonusDropped();

    std::pair<float, float> getXYofBall();

    void setIsBonusDropped(bool b);

    void setBallSpeed(float speed);

private:
    sf::CircleShape ball;
    sf::Color colorOfBall{20, 40, 200};
    sf::Color outlineColorOfBall{20, 240, 140};
    float radius{10.f};
    float thickness{2.f};
    float currentXballPosition{0.f};
    float currentYballPosition{0.f};
    BallDirections ballDirections1;
    BallMovement ballMovement{radius, ballDirections1};
    std::vector<sf::RectangleShape> rectangles;
    bool isBonusDropped{false};
    //BonusManager bonusManager;
};

#endif //ARKANOID_BALL_H
