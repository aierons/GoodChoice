#pragma once
#ifndef Enemy_hpp
#define Enemy_hpp

#include "Vector.hpp"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "Platform.hpp"

class Enemy { //maybe this will be abstract if there are multiple types of enemies
public:
    Enemy(Vector pos, Platform platform);

    void updatePosition();

    void die();

    bool collidesWithPlatform(Platform p);

    void render(SDL_Renderer *renderer);
    //do we need to check for colliding with platforms? If we make it so the player can drop them we should. If they stay on on-platform paths we don't have to
private:
    Vector newPosition(); //Move the enemy to its new position (one forward)
    void flip(); //Flips the enemy's direction
    Vector position;
    bool direction; // If true moves right, if false moves left
    Platform platform; //Platform in which the enemy resides on
};


#endif
