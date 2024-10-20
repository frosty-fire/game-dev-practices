#ifndef GAME_H
#define GAME_H
#include <board.h>
#include <controller.h>
#include <graphics.h>

class Game {

	Board *board;
	Graphics *graphics;
	Controller *controller;

public:
	Game();
	void init() const;
	void run() const;
	void clean() const;
};

#endif // GAME_H