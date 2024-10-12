#ifndef GAME_H
#define GAME_H

#include "Snake.h"
#include "Board.h"
#include "Apple.h"
#include "Controller.h"

class Game {
    Snake *snake;
    Board *board;
    bool running;

    Apple *apple;
    int score;

    Controller *controller;

public:
    Game();

    void init();

    void run();

    void update();

    void generateApple();

    void clean();

    void increaseSpeed();

};

#endif
