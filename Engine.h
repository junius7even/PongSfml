//
// Created by Junius7 on 2023-08-11.
//

#ifndef PONG_ENGINE_H
#define PONG_ENGINE_H
#include <SFML/Graphics.hpp>
#include "Player.h"
using namespace sf;
using namespace std;

class Engine {
public:
    enum GameState {RESET, PAUSED, PLAYING};
    Engine();
    void Run();
    void Draw();
    void HandleControls();
private:
    Vector2f resolution;
    RenderWindow window;
    const unsigned int FPS = 60;
    static const Time TimePerFrame;

    Font mainFont;
    Text titleText;
    Text playerOneScoreText;
    Text playerTwoScoreText;
    Text pressEnterText;

    int currentGameState;
    int lastGameState;

    void StartGame();
    void setupText(sf::Text *textItem, const sf::Font &font, const std::string &value, int size, sf::Color colour);

    void swapStates();

    float playerMoveSpeed;
    void playerControls(RectangleShape &rectToMove, float moveSpeed);
    void playerOneControls();
    void playerTwoControls();

    Player playerOne;
    Player playerTwo;
};


#endif //PONG_ENGINE_H
