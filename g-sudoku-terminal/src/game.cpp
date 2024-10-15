#include <game.h>
#include <iostream>

Game::Game() {
    board = new Board();
    controller = new Controller();
}

void Game::init() {
    std::cout << "\033[?25l" << std::flush;
    board->generate();
    board->render();
    std::cout << "\033[?25h" << std::flush;
}

void Game::run() {

}

void Game::clean() {

}


