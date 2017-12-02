#ifndef Game_hpp
#define Game_hpp
#include "SDL.h"
#include "SDL_image.h"
#include "KeysPressed.hpp"
#include <iostream>

/*
 * Represents the state of the Game. This class will constantly handle user input,
 * update the state of the game, and render all images in the game. 
 */
class Game {
  public:
    Game();
    ~Game();
    void init(const char * title, int xpos, int ypos, int width, int height, bool fullscreen);
    void handleEvents();
    void update();
	void load();
    void reset();
    void render();
    void clean();

    bool running();

    static SDL_Event event;

  private:
    bool isRunning;
    SDL_Window * window;
    SDL_Renderer * renderer;
};

#endif
