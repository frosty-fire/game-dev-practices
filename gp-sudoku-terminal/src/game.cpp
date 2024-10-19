#include <game.h>
#include <graphics.h>

//===============================================================
// PUBLIC

Game::Game() {
    board = new Board();
    graphics = new Graphics();
    controller = new Controller(board, graphics);
}

void Game::init() const {
    graphics->init();
    board->generate();
    graphics->set_board(*board);
    controller->init();
}

void Game::run() const {
    graphics->render();
    controller->run();
}

void Game::clean() const {
    graphics->clean();
}
