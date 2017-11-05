#include "Game.hpp"

Game * game = nullptr;

int main(int argc, char * argv[]) {

  /*
  while (game is running) {
    handle any user inputs;
    update all objects;
    render changes to display;
  }
  */

  game = new Game();
  game->init("", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

  while (game->running()) {
    game->handleEvents();
    game->update();
    game->render();
  }

  game->clean();

  return 0;
}