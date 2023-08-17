//
// Created by Junius7 on 2023-08-11.
//

#ifndef PONG_BALL_H
#define PONG_BALL_H

#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class Ball {
public:
    CircleShape ballShape;
    Ball();
    Ball(int size, Color color);
    void changeDirection(Vector2f velocityVector);
    void moveBall();
    Vector2f direction;
    void changeSpeed(float newSpeed);
    float speedupValue = 0.5;

private:

    float baseSpeed = 3;
    float speed;
};


#endif //PONG_BALL_H
