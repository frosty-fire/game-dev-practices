#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <board.h>
#include <graphics.h>

class Controller {
    Board *board;
    Graphics *graphics;

    int x_coord{0};
    int y_coord{0};

    void init_cursor();

    void move_cursor(int x, int y);

    void move_left();

    void move_up();

    void move_down();

    void move_right();

    void handle_update(int ch);

public:
    Controller(Board *board, Graphics *graphics);

    void init();

    void run();
};

#endif //CONTROLLER_H
