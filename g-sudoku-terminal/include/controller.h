#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <board.h>
#include <graphics.h>

class Controller {
    Board *board;
    Graphics *graphics;

    void init_cursor();

public:
    Controller(Board *board, Graphics *graphics);

    void init();

    void run();
};

#endif //CONTROLLER_H
