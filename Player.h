//
// Created by Junius7 on 2023-08-11.
//

#ifndef PONG_PLAYER_H
#define PONG_PLAYER_H
#include <SFML/Graphics.hpp>

class Player {
public:
    explicit Player(int xPosition, int yPosition, int width, int length, sf::Color color, sf::Color outlineColor);
    explicit Player();
    void Move(int x, int y);
    sf::RectangleShape playerRect;
private:
    int xPosition;
    int yPosition;
};


#endif //PONG_PLAYER_H
