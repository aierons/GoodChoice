#ifndef Player_hpp
#define Player_hpp
#include "Vector.hpp"
#include "SDL.h"
#include "SDL_image.h"
#include "TextureManager.hpp"
#include "KeysPressed.hpp"
#include "Platform.hpp"
#include "Goal.h"

/*
 * Represents the player that is given its current position, velocity, and
 * acceleration.
 */
class Player {
  public:
    Player();
    void jump();
    void updatePosition();
    void updateVelocity();
    void updateAcceleration();
    bool isColliding(Platform platform);
    bool isColliding(Goal goal);
    void checkColliding(vector<Platform> platforms);
    void update(KeysPressed * keys, vector<Platform> platforms);
    void deleteTexture();
    void moveLeft();
    void moveRight();
    void idle();
    bool isIdle();
    void render(SDL_Renderer * renderer);
    Vector position;
     void deleteTexture();

  private:
    Vector velocity;
    Vector acceleration;
    bool isFalling;
    SDL_Texture * texture = NULL;
};

#endif
