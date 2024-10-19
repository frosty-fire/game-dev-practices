#include "Apple.h"
#include "Board.h"
#include <random>

Apple::Apple(const char icon, const int score) {
    this->icon = icon;
    this->score = score;
}

int randomInt(int low, int high) {
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> distr(low, high);
    return distr(gen);
}

void Apple::display(Board *board) {
    int xBound = board->getHeight();
    int yBound = board->getWidth();

    while (true) {
        int x = randomInt(0, xBound - 1);
        int y = randomInt(0, yBound - 1);
        if (board->isValidCell(x,y)) {
            board->
        }
    }


    board->set()
}
