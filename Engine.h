//
// Created by Junius7 on 2023-08-11.
//

#ifndef PONG_ENGINE_H
#define PONG_ENGINE_H
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Ball.h"
using namespace sf;
using namespace std;

class Engine {
public:
    enum GameState {RESET, PAUSED, PLAYING};
    Engine();
    void Run();



private:
    const unsigned int ballSize = 10;

    Vector2f resolution;
    RenderWindow window;
    const unsigned int FPS = 60;
    const float ballSpeed = 2;
    static const Time TimePerFrame;

    Font mainFont;
    Text titleText;
    Text playerOneScoreText;
    Text playerTwoScoreText;
    Text pressEnterText;

    int currentGameState;
    int lastGameState;

    void StartGame();
    void Draw();
    void HandleControls();
    void HandlePhysics();
    void setupText(sf::Text *textItem, const sf::Font &font, const std::string &value, int size, sf::Color colour);

    void swapStates(GameState nextGameState);

    const float playerMoveSpeed = 4;
    void playerControls(RectangleShape &rectToMove, float moveSpeed);
    void playerOneControls();
    void playerTwoControls();

    void wallRectCollision(RectangleShape& wallRect);
    void playerRectCollision(RectangleShape& playerRect);

    void resetBall();

    Ball pongBall;

    RectangleShape topWall;
    RectangleShape botWall;

    float maxBounceAngle = 85;
    Player playerOne;
    Player playerTwo;
};


#endif //PONG_ENGINE_H
