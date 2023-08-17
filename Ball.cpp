//
// Created by Junius7 on 2023-08-11.
//

#include "Ball.h"
#include <math.h>

using namespace sf;
Ball::Ball(int size, Color color) {
    speed = 0;
    ballShape = CircleShape((float)size);
    ballShape.setFillColor(color);
    ballShape.setOutlineThickness(1);
    ballShape.setOutlineColor(Color::Red);
    ballShape.setOrigin((float)size, (float)size);
}

void Ball::changeDirection(Vector2f velocityVector) {
    float magnitude = sqrt(velocityVector.x * velocityVector.x + velocityVector.y * velocityVector.y);
    direction = velocityVector/magnitude;
    speed = baseSpeed + speedupValue;
}

void Ball::moveBall() {
    ballShape.move(direction * speed);
    // TODO: Gradually increase speed of ball after each collision
    // speed += 0.01f;
}

Ball::Ball() {
    ballShape = CircleShape(0);
    speed = 0;
}

void Ball::changeSpeed(float newSpeed) {
    speed = newSpeed;
}
