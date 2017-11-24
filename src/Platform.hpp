#ifndef Platform_hpp
#define Platform_hpp
#include "Vector.hpp"
#include "SDL.h"
#include "SDL_image.h"
#include "TextureManager.hpp"

/*
 * Represents a platform that is given the x and y coordinates of the bottom-left
 * corner and the top-right corner.
 */
class Platform {
public:
  Platform(Vector start_v, Vector end_v);
  Platform(Vector start_v, Vector end_v, bool vis);
  bool collides(Vector v);

  void render(SDL_Renderer * renderer);

  int getEndY();

  bool isVisible();

  void show();
private:
  int start_x; //lower or left end
  int start_y; //lower or left end
  int end_x; //upper or right end
  int end_y; //upper or right end
  bool visible;
};

#endif