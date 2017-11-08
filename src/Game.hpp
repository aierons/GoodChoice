#ifndef Game_hpp
#define Game_hpp
#include "SDL.h"
#include "SDL_image.h"
#include "KeysPressed.hpp"
#include "Platform.hpp"
#include <vector>


class Game {
  public:
    Game();
    ~Game();

    void init(const char * title, int xpos, int ypos, int width, int height, bool fullscreen);
    void handleEvents();
    void update();
    void render();
    void clean();

    bool running();

    static SDL_Event event;

  private:
    bool isRunning;
    SDL_Window * window;
    SDL_Renderer * renderer;
	std::vector<Platform> platforms;
};

#endif /* Game_hpp */
