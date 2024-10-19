#include <controller.h>
#include <curses.h>
#include <cmath>
#include <csignal>
#include <cstdlib>

Graphics *global_graphics;

void exit_signal(int signum);

//===============================================================
// PUBLIC

Controller::Controller(Board *board, Graphics *graphics) {
	this->board = board;
	this->graphics = graphics;
	global_graphics = graphics;
}

void Controller::init() {
	init_cursor();

	signal(SIGINT, exit_signal);
	signal(SIGTSTP, exit_signal);
}

// TODO Need to enhanced
void Controller::run() {
	int ch;
	while ((ch = getch()) != 4) {
		if (ch == 27) {
			if (getchar() == '[') {
				switch (getchar()) {
					case 'A':
						move_up();
						break;
					case 'B':
						move_down();
						break;
					case 'C':
						move_right();
						break;
					case 'D':
						move_left();
						break;
					default:
						continue;
				}
			} else {
				continue;
			}
		}

		switch (ch) {
			case 'w':
				move_up();
				break;
			case 's':
				move_down();
				break;
			case 'd':
				move_right();
				break;
			case 'a':
				move_left();
				break;
			default:
				if (ch >= '1' && ch <= '9') {
					handle_update(ch);
				}
		}
	}
}

//===============================================================
// PRIVATE

void Controller::init_cursor() {
	auto [x, y] = board->first_empty();
	move_cursor(x, y);
}

void Controller::move_cursor(int x, int y) {
	graphics->move_cursor(x, y);
	x_coord = x;
	y_coord = y;
}

void Controller::move_left() {
	const int curr_coord = x_coord * BOARD_SIZE + y_coord;
	for (int i = curr_coord - 1; i >= 0; i--) {
		int x = std::floor(i / BOARD_SIZE);
		int y = i % BOARD_SIZE;
		if (board->get(x, y) == -1) {
			move_cursor(x, y);
			return;
		}
	}
}

void Controller::move_right() {
	const int curr_coord = x_coord * BOARD_SIZE + y_coord;
	for (int i = curr_coord + 1; i < BOARD_SIZE * BOARD_SIZE; i++) {
		int x = std::floor(i / BOARD_SIZE);
		int y = i % BOARD_SIZE;
		if (board->get(x, y) == -1) {
			move_cursor(x, y);
			return;
		}
	}
}

void Controller::move_up() {
	for (int x = x_coord - 1; x >= 0; x--) {
		int ly = y_coord, ry = y_coord;
		while (ly >= 0 || ry < BOARD_SIZE) {
			if (ly >= 0 && board->get(x, ly) == -1) {
				move_cursor(x, ly);
				return;
			}
			if (ry < BOARD_SIZE && board->get(x, ry) == -1) {
				move_cursor(x, ry);
				return;
			}
			ly--;
			ry++;
		}
	}
}

void Controller::move_down() {
	for (int x = x_coord + 1; x < BOARD_SIZE; x++) {
		int ly = y_coord, ry = y_coord;
		while (ly >= 0 || ry < BOARD_SIZE) {
			if (ly >= 0 && board->get(x, ly) == -1) {
				move_cursor(x, ly);
				return;
			}
			if (ry < BOARD_SIZE && board->get(x, ry) == -1) {
				move_cursor(x, ry);
				return;
			}
			ly--;
			ry++;
		}
	}
}

void Controller::handle_update(const int ch) {
	if (board->is_valid(x_coord, y_coord, ch - '0')) {
		printw("%c", ch);
	} else {
		printw(".");
	}
	move_cursor(x_coord, y_coord);
}

void exit_signal(const int signum) {
	global_graphics->clean();
	exit(signum);
}
