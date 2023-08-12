//
// Created by Junius7 on 2023-08-11.
//

#include "Engine.h"

Engine::Engine() {

}


void Engine::Run() {
    const int windowWidth = 12 * 80;
    const int windowHeight = 600;
    RenderWindow window(VideoMode(windowWidth, windowHeight), "Pong", Style::Default);

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
        HandleControls();

        window.clear(Color::Black);
        Draw();
        window.display();
    }
}

void Engine::Draw() {

}

void Engine::HandleControls() {
    if (Keyboard::isKeyPressed(Keyboard::W)) {

    }
}
