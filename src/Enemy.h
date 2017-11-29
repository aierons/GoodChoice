#pragma once
#ifndef Enemy_hpp
#define Enemy_hpp
#include "Vector.hpp"
#include "SDL.h"
#include "SDL_image.h"
#include <vector>
#include "TextureManager.hpp"
#include "Platform.hpp"


class Enemy { //maybe this will be abstract if there are multiple types of enemies
public:
	Enemy(Vector start, Vector end);
    void jump();
    void updatePosition();
    void updateVelocity();
    void updateAcceleration();
    bool isColliding(Platform platform);
    void checkColliding(vector<Platform> platforms);
    void update(vector<Platform> platforms);
    void idle();
    void render(SDL_Renderer * renderer);
    void updateDirection();
    Vector position;
    
    void die();
    bool collides(Vector v);
    
private:
    Vector velocity;
    Vector acceleration;
    bool isFalling;
    Vector start;
    Vector end;
    
    bool direction;
    vector<Vector> getHitBox();
	
};

#endif
