#include <board.h>
#include <algorithm>
#include <random>

//===============================================================
// PUBLIC

Board::Board() {
	board = new int *[BOARD_SIZE];
	for (int i = 0; i < BOARD_SIZE; i++) {
		board[i] = new int[BOARD_SIZE];
		for (int j = 0; j < BOARD_SIZE; j++) {
			board[i][j] = -1;
		}
	}
}

void Board::generate() {
	fill_board();

	std::tuple<int, int, int> xyc;
	do {
		xyc = remove_random_cell(board);
	} while (count_possibility() == 1);
	if (std::get<2>(xyc) != -1) {
		board[std::get<0>(xyc)][std::get<1>(xyc)] = std::get<2>(xyc);
	}
}

int Board::get(const int x, const int y) const {
	return board[x][y];
}

bool Board::is_valid(const int x, const int y, const int v) {
	for (int i = 0; i < BOARD_SIZE; i++) {
		if (i != x && board[i][y] == v || i != y && board[x][i] == v) {
			return false;
		}
	}
	const int start_x = static_cast<int>(std::floor(x / 3)) * 3;
	const int start_y = static_cast<int>(std::floor(y / 3)) * 3;
	for (int i = start_x; i < start_x + 3; i++) {
		for (int j = start_y; j < start_y + 3; j++) {
			if (i != x && j != y && board[i][j] == v) {
				return false;
			}
		}
	}
	return true;
}

std::pair<int, int> Board::first_empty() const {
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (board[i][j] == -1) {
				return std::make_pair(i, j);
			}
		}
	}
	return std::make_pair(-1, -1);
}

//===============================================================
// PRIVATE

int Board::rand_range(const int low, const int high) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(low, high);
	return dis(gen);
}

std::tuple<int, int, int> Board::remove_random_cell(int **board) {
	int x, y;
	do {
		x = rand_range(0, 8);
		y = rand_range(0, 8);
	} while (board[x][y] == -1);

	int v = board[x][y];
	board[x][y] = -1;
	return std::make_tuple(x, y, v);
}

bool Board::fill_board() {
	auto [x, y] = first_empty();
	if (x == -1 || y == -1) {
		return true;
	}

	std::vector digits = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	std::ranges::shuffle(digits, std::mt19937(std::random_device()()));

	for (const int i : digits) {
		if (is_valid(x, y, i)) {
			board[x][y] = i;

			if (fill_board()) {
				return true;
			}

			board[x][y] = -1;
		}
	}
	return false;
}

long Board::count_possibility() {
	auto [x, y] = first_empty();
	if (x == -1 || y == -1) {
		return 1;
	}

	long count = 0;
	for (int i = 1; i <= 9; i++) {
		if (is_valid(x, y, i)) {
			board[x][y] = i;
			count += count_possibility();
			board[x][y] = -1;
		}
	}
	return count;
}