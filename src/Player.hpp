#ifndef Player_hpp
#define Player_hpp
#include "Vector.hpp"
#include "SDL.h"
#include "SDL_image.h"
#include "TextureManager.hpp"
#include "KeysPressed.hpp"

class Player {
  public:
    Player();
    void jump();
    void updatePosition();
    void updateVelocity();
    void updateAcceleration();
    void update(KeysPressed * keys);
    bool isFalling();

    void moveLeft();
    void moveRight();
    void idle();

    void render(SDL_Renderer * renderer);

  private:
    Vector position;
    Vector velocity;
    Vector acceleration;
};

#endif