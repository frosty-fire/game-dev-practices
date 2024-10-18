#include <game.h>

int main() {
    const Game game;
    game.init();
    game.run();
    game.clean();
    return 0;
}
