#ifndef Player_hpp
#define Player_hpp
#include "Vector.hpp"
#include "SDL.h"
#include "SDL_image.h"
#include "TextureManager.hpp"
#include "KeysPressed.hpp"
#include "Platform.hpp"

class Player {
  public:
    Player();
    void jump();
    void updatePosition();
    void updateVelocity();
    void updateAcceleration();
    bool isColliding(Platform platform);
    void checkColliding(vector<Platform> platforms);
    void update(KeysPressed * keys, vector<Platform> platforms);

    void moveLeft();
    void moveRight();
    void idle();

    void render(SDL_Renderer * renderer);

  private:
    Vector position;
    Vector velocity;
    Vector acceleration;
    bool isFalling;
};

#endif