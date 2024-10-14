#include "Board.h"
#include <iostream>

Board::Board(const int height, const int width, int cellHeight, int cellWidth) {
    this->height = height;
    this->width = width;

    this->cellHeight = cellHeight;
    this->cellWidth = cellWidth;

    board = new Cell *[height];
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            board[i][j] = Cell();
        }
    }
}

void Board::display() const {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            std::cout << board[i][j] << "  ";
        }
        std::cout << std::endl;
    }
}

bool Board::isValidCell(int x, int y) const {
    return board[x][y] == 'O';
}

void Board::set(int x, int y, int value) {
    board[x][y] = value;
}


int Board::getHeight() const {
    return height;
}

int Board::getWidth() const {
    return width;
}
