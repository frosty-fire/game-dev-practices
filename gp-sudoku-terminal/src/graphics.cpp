#include <board.h>
#include <curses.h>
#include <graphics.h>
#include <cmath>

enum ColorPair {
	DEFAULT = 1,
	EMPTY_CELL = 2,
	INIT_CELL = 3,
	UPDATED_CELL = 4
};

//===============================================================
// PUBLIC

void Graphics::init() {
	initscr();
	define_color();

	noecho();
	curs_set(2);
}

void Graphics::set_board(const Board board) {
	attron(COLOR_PAIR(DEFAULT));
	for (int i = 0; i < BOARD_SIZE; i++) {
		if (i % 3 == 0) {
			printw("+  -  -  -  +  -  -  -  +  -  -  -  +\n");
		}
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (j % 3 == 0) {
				printw("|  ");
			}
			if (board.get(i, j) == -1) {
				attroff(COLOR_PAIR(DEFAULT));
				attron(A_DIM | COLOR_PAIR(EMPTY_CELL));
				printw(".  ");
				attroff(A_DIM | COLOR_PAIR(EMPTY_CELL));
				attron(COLOR_PAIR(DEFAULT));
			} else {
				attroff(COLOR_PAIR(DEFAULT));
				attron(A_BOLD | COLOR_PAIR(INIT_CELL));
				printw("%c  ", '0' + board.get(i, j));
				attroff(A_BOLD | COLOR_PAIR(INIT_CELL));
				attron(COLOR_PAIR(DEFAULT));
			}
		}
		printw("|\n");
	}
	printw("+  -  -  -  +  -  -  -  +  -  -  -  +\n");
	attroff(COLOR_PAIR(DEFAULT));
}

void Graphics::update_board(const int x, const int y, const int value) {
	auto [c_x, c_y] = board_coord_to_graphic_coord(x, y);
	attron(A_BOLD | COLOR_PAIR(UPDATED_CELL));
	mvprintw(c_x, c_y, "%c  ", '0' + value);
	attroff(A_BOLD | COLOR_PAIR(UPDATED_CELL));
}

void Graphics::move_cursor(const int x, const int y) {
	auto [c_x, c_y] = board_coord_to_graphic_coord(x, y);
	move(c_x, c_y);
}

void Graphics::render() {
	refresh();
}

void Graphics::clean() {
	endwin();
	curs_set(2);
	printf("\033[?12;2h");
}

//===============================================================
// PRIVATE

void Graphics::define_color() {
	start_color();
	use_default_colors();

	init_color(100, 850, 400, 200);

	init_pair(DEFAULT, COLOR_GREEN, -1);
	init_pair(EMPTY_CELL, COLOR_YELLOW, -1);
	init_pair(INIT_CELL, COLOR_CYAN, -1);
	init_pair(UPDATED_CELL, 100, -1);
}

std::pair<int, int> Graphics::board_coord_to_graphic_coord(const int x, const int y) {
	const int c_x = (static_cast<int>(std::floor(x / 3)) + x + 1);
	const int c_y = (static_cast<int>(std::floor(y / 3)) + y + 1) * 3;
	return std::make_pair(c_x, c_y);
}
