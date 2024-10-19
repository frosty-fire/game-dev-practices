#ifndef BOARD_H
#define BOARD_H

#include "Cell.h"

class Board {
    int height;
    int width;

    int currentX;
    int currentY;

    int cellHeight;
    int cellWidth;
    Cell **board;

public:
    Board(int height, int width);

    void display() const;

    bool isValidCell(int x, int y) const;

    void set(int x, int y, char value);

    int getHeight() const;

    int getWidth() const;
};

#endif
