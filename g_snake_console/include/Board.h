#ifndef BOARD_H
#define BOARD_H

class Board {
    int xSize;
    int ySize;
    char *board;

public:
    Board(int x, int y);

    void display();

    void get(int x, int y);

    void set(int x, int y, char val);

    int getXSize();

    int getYSize();

    ~Board();
};

#endif
