#ifndef APPLE_H
#define APPLE_H
#include "Board.h"

class Apple {
    char icon;
    int score;
public:
    Apple(int score);

    void display(Board *board);
};

#endif
