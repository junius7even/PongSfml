//
// Created by Junius7 on 2023-08-11.
//

#ifndef PONG_ENGINE_H
#define PONG_ENGINE_H
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class Engine {
public:
    Engine();
    void Run();
    void Draw();
    void HandleControls();
private:
    RenderWindow window;
};


#endif //PONG_ENGINE_H
