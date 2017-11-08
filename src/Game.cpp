#include "Game.hpp"
#include "TextureManager.hpp"
#include "Player.hpp"
#include <vector>

SDL_Event Game::event;
Player * player;
KeysPressed * keys;

Game::Game() {
  player = new Player();
  keys = new KeysPressed();
}

Game::~Game() {

}

void Game::init(const char * title, int xpos, int ypos, int width, int height, bool fullscreen) {

  int flags = 0;
  if (fullscreen) {
    flags = SDL_WINDOW_FULLSCREEN;
  }

  if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
    std::cout << "Subsystems Initialized..." << std::endl;
    window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

    if (window) {
      std::cout << "Window Created!" << std::endl;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer) {
      SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
      std::cout << "Renderer Created!" << std::endl;
    }

    isRunning = true;
	platforms(new Platform(Vector(100, 100), Vector(150, 100));
  } else {
    isRunning = false;
  }
}

void Game::handleEvents() {
  SDL_PollEvent(&event);

  switch (event.type) {
     case SDL_QUIT:
       isRunning = false;
       break;
     case SDL_KEYDOWN:
       keys->addKeyCode(event.key.keysym.sym);
       break;
     case SDL_KEYUP:
       keys->removeKeyCode(event.key.keysym.sym);
     default:
       break;
  }
}

void Game::update() {
	player->isColliding(platforms);
	player->update(keys);
}

void Game::render() {
  SDL_RenderClear(renderer);
  player->render(renderer);
  //SDL_RenderCopy(renderer, playerTex, NULL, &destRect);
  SDL_RenderPresent(renderer);
}

void Game::clean() {
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
  std::cout << "Game Cleaned!" << std::endl;
}

bool Game::running() {
  return isRunning;
}