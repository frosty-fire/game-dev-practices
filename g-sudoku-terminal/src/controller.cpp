#include <controller.h>
#include <iostream>
#include <csignal>
#include <curses.h>

Graphics *global_graphics;

void exit_signal(int signum);

//===============================================================
// PUBLIC

Controller::Controller(Board *board, Graphics *graphics) {
    this->board = board;
    this->graphics = graphics;
    global_graphics = graphics;
}

void Controller::init() {
    init_cursor();

    signal(SIGINT, exit_signal);
    signal(SIGTSTP, exit_signal);
}


void Controller::run() {
    int ch;
    while ((ch = getch()) != 4) {
    }
}

//===============================================================
// PRIVATE

void Controller::init_cursor() {
    auto [x, y] = board->first_empty();
    graphics->move_cursor(x, y);
}

void exit_signal(int signum) {
    global_graphics->clean();
    exit(0);
}
