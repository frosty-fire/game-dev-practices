#ifndef BOARD_H
#define BOARD_H

#define BOARD_SIZE 9

class Board {
    int **board;

    int renderSpeedInMs{200};
    int cursorRow{0};
    int cursorCol{0};

public:
    Board();

    void generate();

    void render();
};

#endif //BOARD_H
