#ifndef GAME_H
#define GAME_H
#include <graphics.h>
#include <board.h>
#include <controller.h>

class Game {
    Board *board;
    Graphics *graphics;
    Controller *controller;

public:
    Game();

    void init() const;

    void run() const;

    void clean() const;
};

#endif //GAME_H
