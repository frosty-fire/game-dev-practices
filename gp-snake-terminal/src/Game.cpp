#include "Game.h"

Game::Game() {
    running = false;
    score = 0;

    snake = new Snake();
    board = new Board(10, 10);
    apple = new Apple(1);

    controller = new Controller();
}

void Game::init() {
    board->display();
    apple->display(board);

    running = true;
    score = 0;
}

void Game::run() {
    // while (this->running) {
    //     this->update();
    // }
    // this->clean();
}

void Game::update() {
    snake->update();
}

void Game::clean() {
}
