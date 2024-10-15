#include <algorithm>
#include <board.h>
#include <format>
#include <iostream>
#include <random>
#include <thread>

int randRange(int low, int high);

bool isValid(int **board, int x, int y, int v);

std::pair<int, int> firstEmpty(int **board);

bool fillBoard(int **board);

std::tuple<int, int, int> removeRandomCell(int **board);

long countPossibility(int **board);

void moveCursor(int right, int down);


// ===============================================================

Board::Board() {
    board = new int *[9];
    for (int i = 0; i < 9; i++) {
        board[i] = new int[9];
        for (int j = 0; j < 9; j++) {
            board[i][j] = -1;
        }
    }
}

void Board::generate() {
    fillBoard(board);

    std::tuple<int, int, int> xyc;

    do {
        xyc = removeRandomCell(board);
    } while (countPossibility(board) == 1);

    if (std::get<2>(xyc) != -1) {
        board[std::get<0>(xyc)][std::get<1>(xyc)] = std::get<2>(xyc);
    }
}

void Board::render() {
    const std::string reset = "\033[0m";
    const std::string defaultColor = "\033[32m";
    const std::string filledColor = "\033[1;96m";
    const std::string emptyColor = "\033[2;93m";

    std::this_thread::sleep_for(std::chrono::milliseconds(renderSpeedInMs));
    moveCursor(-cursorCol, -cursorRow);

    for (int i = 0; i < 9; i++) {
        if (i % 3 == 0) {
            std::cout << defaultColor << "+  -  -  -  +  -  -  -  +  -  -  -  +" << reset <<
                    std::endl;
        }
        for (int j = 0; j < 9; j++) {
            if (j % 3 == 0) {
                std::cout << defaultColor << "|  " << reset;
            }
            if (board[i][j] == -1) {
                std::cout << emptyColor << '.' << reset << "  ";
            } else {
                std::cout << filledColor << board[i][j] << reset << "  ";
            }
        }
        std::cout << defaultColor << "|" << reset << std::endl;
    }
    std::cout << defaultColor << "+  -  -  -  +  -  -  -  +  -  -  -  +" << reset << std::endl;
    cursorRow = 14;
    cursorCol = 0;
}

// ===============================================================

int randRange(int low, int high) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(low, high);
    return dis(gen);
}

bool isValid(int **board, int x, int y, int v) {
    for (int i = 0; i < 9; i++) {
        if (i != x && board[i][y] == v || i != y && board[x][i] == v) {
            return false;
        }
    }
    int startX = floor(x / 3) * 3;
    int startY = floor(y / 3) * 3;
    for (int i = startX; i < startX + 3; i++) {
        for (int j = startY; j < startY + 3; j++) {
            if (i != x && j != y && board[i][j] == v) {
                return false;
            }
        }
    }
    return true;
}

std::pair<int, int> firstEmpty(int **board) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == -1) {
                return std::make_pair(i, j);
            }
        }
    }
    return std::make_pair(-1, -1);
}

bool fillBoard(int **board) {
    auto [x, y] = firstEmpty(board);
    if (x == -1 || y == -1) {
        return true;
    }

    std::vector digits = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::ranges::shuffle(digits, std::mt19937(std::random_device()()));

    for (int i: digits) {
        if (isValid(board, x, y, i)) {
            board[x][y] = i;

            if (fillBoard(board)) {
                return true;
            }

            board[x][y] = -1;
        }
    }
    return false;
}

std::tuple<int, int, int> removeRandomCell(int **board) {
    int x, y;
    do {
        x = randRange(0, 8);
        y = randRange(0, 8);
    } while (board[x][y] == -1);

    int v = board[x][y];
    board[x][y] = -1;
    return std::make_tuple(x, y, v);
}

long countPossibility(int **board) {
    auto [x, y] = firstEmpty(board);
    if (x == -1 || y == -1) {
        return 1;
    }

    std::vector digits = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::ranges::shuffle(digits, std::mt19937(std::random_device()()));

    int count = 0;
    for (int i: digits) {
        if (isValid(board, x, y, i)) {
            board[x][y] = i;
            count += countPossibility(board);
            board[x][y] = -1;
        }
    }
    return count;
}

void moveCursor(int right, int down) {
    if (right > 0) {
        std::cout << std::format("\033[{}C", right);
    } else {
        std::cout << std::format("\033[{}D", -right);
    }

    if (down > 0) {
        std::cout << std::format("\033[{}B", down);
    } else {
        std::cout << std::format("\033[{}A", -down);
    }
    std::cout << std::endl;
}
