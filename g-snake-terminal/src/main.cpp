#include <cstdlib>

#include "Game.h"

int main() {
    Game game;

    game.init();
    game.run();
    game.clean();

    return EXIT_SUCCESS;
}
