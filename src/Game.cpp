#include "Game.hpp"
#include "TextureManager.hpp"
#include "Player.hpp"
#include "Platform.hpp"
#include "Bullet.h"
#include "PlatformBullet.h"
#include <vector>

SDL_Event Game::event;
Player * player;
vector<Platform> platforms;
vector<PlatformBullet> pBullets;
KeysPressed * keys;

/*
 * This constructor will initialize the Player, KeyPressed, and platforms
 */
Game::Game() {
  player = new Player();
  keys = new KeysPressed();
  platforms = vector<Platform>();
  pBullets = vector<PlatformBullet>();

  //testing platform bullet
  pBullets.push_back(PlatformBullet(Vector(200, 200), Vector(5, 0)));

  platforms.push_back(Platform(Vector(50, 20), Vector(550, 90)));
  platforms.push_back(Platform(Vector(300, 150), Vector(400, 180)));
  platforms.push_back(Platform(Vector(400, 250), Vector(500, 300)));
  platforms.push_back(Platform(Vector(100, 375), Vector(270, 400)));

  //testing invisible platform
  platforms.push_back(Platform(Vector(400, 200), Vector(450, 205), false));
}

/*
 * This destructor will delete the pointers to player and keys;
 */
Game::~Game() {
  delete player;
  delete keys;
}

/*
 * Initializes the game by creating a window and renderer.
 */
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
  } else {
    isRunning = false;
  }
}

/*
 * Handles user input such as keyboard, mouse, and quitting
 */
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

/*
 * Updates the state of the game.
 */
void Game::update() {
  player->update(keys, platforms);
  for (int count = 0; count < pBullets.size(); count++) {
		  pBullets[count].updatePosition();
		  bool exists = true;
		  if (!pBullets[count].isAlive()) {
			  pBullets.erase(pBullets.begin() + count);
			  exists = false;
		  }
		  for (int i = 0; i < platforms.size() && exists; i++) {
			  if (pBullets[count].collidesWithPlatform(platforms[i])) {
					  pBullets.erase(pBullets.begin() + count);
					  exists = false;
			  }
		  }
  }
}

/*
 * Renders all given game objects
 */
void Game::render() {
  SDL_RenderClear(renderer);
  player->render(renderer);

  for (Platform platform : platforms) {
    if(platform.isVisible()) { platform.render(renderer); }
  }

  for (int count = 0; count < pBullets.size(); count++) {
	  pBullets[count].render(renderer);
  }

  SDL_RenderPresent(renderer);
}

/*
 * Cleans up the game by destroying the window and renderer.
 */
void Game::clean() {
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
  std::cout << "Game Cleaned!" << std::endl;
}

/*
 * Getter for isRunning, which determines if the game is running.
 */
bool Game::running() {
  return isRunning;
}

/*void Game::shoot() {
	if (event.key == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
		position = player.position;
		alive = true;
		updatePosition();
		render();
	}
}*/