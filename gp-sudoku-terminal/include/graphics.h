#ifndef GRAPHICS_H
#define GRAPHICS_H
#include <board.h>

class Graphics {

	void define_color();
	std::pair<int, int> board_coord_to_graphic_coord(int x, int y);

public:
	void init();
	void set_board(Board board);
	void update_board(int x, int y, int value);
	void move_cursor(int x, int y);
	void render();
	void clean();
};

#endif // GRAPHICS_H