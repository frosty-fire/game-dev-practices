#ifndef GAME_H
#define GAME_H
#include <board.h>
#include <controller.h>

class Game {
    Board *board;
    Controller *controller;

public:
    Game();
    void init();
    void run();
    void clean();
};

#endif //GAME_H
