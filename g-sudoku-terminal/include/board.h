#ifndef BOARD_H
#define BOARD_H

#define BOARD_SIZE 9
#include <utility>

class Board {
    int **board;

    int rand_range(int low, int high);

    bool is_valid(int x, int y, int v);

    bool fill_board();

    std::tuple<int, int, int> remove_random_cell(int **board);

    long count_possibility();

public:
    Board();

    void generate();

    int get(int x, int y) const;

    std::pair<int, int> first_empty() const;
};

#endif //BOARD_H
