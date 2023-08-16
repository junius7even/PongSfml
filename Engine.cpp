//
// Created by Junius7 on 2023-08-11.
//

#include "Engine.h"
#include <iostream>

Engine::Engine() {
    resolution = Vector2f(800, 600);
    window.create(VideoMode(resolution.x, resolution.y), "Pong", Style::Default);
    window.setFramerateLimit(FPS);

    mainFont.loadFromFile("../Fonts/slant_regular.ttf");
    setupText(&titleText, mainFont, "PONG", 140, Color(106, 90, 205));
    titleText.setOrigin(titleText.getLocalBounds().width/2, titleText.getLocalBounds().height/2 + 45);
    titleText.setPosition(resolution.x/2, resolution.y/2);

    playerMoveSpeed = 2;
    playerOne = Player(resolution.x/10, resolution.y/2, 30, 130, Color::Magenta,Color::White);
    playerTwo = Player(resolution.x/10 * 9, resolution.y/2, 30, 130, Color::Blue,Color::White);

    pongBall = Ball(ballSize, Color::White);
    pongBall.ballShape.setPosition(resolution.x/2, resolution.y/2);

    currentGameState = GameState::RESET;
}


void Engine::Run() {
    while (window.isOpen()) {
        sf::Event windowEvent;
        while (window.pollEvent(windowEvent)) {
            switch (windowEvent.type) {
                case sf::Event::Closed: {
                    window.close();
                    break;
                }
            }
        }
        HandlePhysics();
        HandleControls();

        if (GameState::PLAYING)
            pongBall.moveBall();

        window.clear(Color::Black);
        Draw();
        window.display();
    }
}
void setupWall(RectangleShape &wall) {
    wall.setFillColor(Color(90, 90, 90));
}

void Engine::Draw() {
    window.draw(titleText);
    window.draw(playerOne.playerRect);
    window.draw(playerTwo.playerRect);
    // Draw Ball
    if (currentGameState == GameState::PLAYING)
        window.draw(pongBall.ballShape);

    // Draw walls

    RectangleShape topWall = RectangleShape(Vector2f(resolution.x, resolution.y/12));
    RectangleShape botWall = RectangleShape(Vector2f(resolution.x, resolution.y/12));
    botWall.setPosition(botWall.getPosition().x, resolution.y/12 * 11);
    setupWall(topWall);
    setupWall(botWall);

    window.draw(topWall);
    window.draw(botWall);
}

void Engine::HandleControls() {
    if (Keyboard::isKeyPressed(Keyboard::P))
        swapStates(currentGameState == GameState::PAUSED ? GameState::PLAYING : GameState::PAUSED);

    if (currentGameState == GameState::PAUSED)
        return;

    playerOneControls();
    playerTwoControls();
    if (Keyboard::isKeyPressed(Keyboard::R)) {
        StartGame();
        swapStates(GameState::PLAYING);
    }

}

void Engine::playerControls(RectangleShape &rectToMove, float moveSpeed) {

    if (Keyboard::isKeyPressed(Keyboard::S)) {
        rectToMove.move(Vector2f(0, moveSpeed));
    }

    if (Keyboard::isKeyPressed(Keyboard::W)) {
        rectToMove.move(Vector2f(0, -moveSpeed));
    }
}

void Engine::playerOneControls() {
    if (Keyboard::isKeyPressed(Keyboard::S)) {
        playerOne.playerRect.move(Vector2f(0, playerMoveSpeed));
    }

    if (Keyboard::isKeyPressed(Keyboard::W)) {
        playerOne.playerRect.move(Vector2f(0, -playerMoveSpeed));
    }
}
void Engine::playerTwoControls() {
    if (Keyboard::isKeyPressed(Keyboard::Up)) {
        playerTwo.playerRect.move(Vector2f(0, -playerMoveSpeed));
    }
    if (Keyboard::isKeyPressed(Keyboard::Down)) {
        playerTwo.playerRect.move(Vector2f(0, playerMoveSpeed));
    }
}

void Engine::resetBall() {
    pongBall = Ball(ballSize, Color::White);
    pongBall.changeDirection(Vector2f(-1, 0));
    pongBall.ballShape.setPosition(resolution.x/2, resolution.y/2);
    pongBall.changeSpeed(ballSpeed);
}

void Engine::StartGame() {
    resetBall();
}

void Engine::setupText(sf::Text *textItem, const Font &font, const string &value, int size, sf::Color colour) {
    textItem->setFont(font);
    textItem->setString(value);
    textItem->setCharacterSize(size);
    textItem->setFillColor(colour);
}

void Engine::swapStates(Engine::GameState nextGameState) {
    lastGameState = currentGameState;
    currentGameState = nextGameState;
}

void Engine::HandlePhysics() {
    if (currentGameState == GameState::PLAYING)
        pongBall.moveBall();
}

