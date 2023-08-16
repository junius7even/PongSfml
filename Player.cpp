//
// Created by Junius7 on 2023-08-11.
//

#include "Player.h"
#include <iostream>
using namespace std;
using namespace sf;

Player::Player(int xPosition, int yPosition, int width, int length, sf::Color fillColor, sf::Color outlineColor) {
    // playerRect.setPosition(Vector2f(xPosition, yPosition));
    playerRect = sf::RectangleShape(Vector2f((float)width, (float)length));
    playerRect.setPosition((float)xPosition, (float)yPosition);
    playerRect.setOutlineColor(outlineColor);
    playerRect.setFillColor(fillColor);
    playerRect.setOrigin(((float)width)/2, ((float)length)/2);
    playerRect.setOutlineThickness(3);
}

void Player::Move(int x, int y) {
    playerRect.move((float)x, (float)y);
}

Player::Player() {

}