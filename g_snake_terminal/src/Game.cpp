#include "Game.h"

Game::Game() {
    this->snake = nullptr;
    this->board = nullptr;
    this->running = false;

    this->apple = nullptr;
    this->score = 0;

    this->controller = nullptr;
}

void Game::init() {
    this->board->display();
    this->apple->display();
    this->running = true;
    this->score = 0;
}

void Game::run() {
    while (this->running) {
        this->update();
    }
    this->clean();
}

void Game::update() {
    this->snake->update();

}

void Game::clean() {

}





