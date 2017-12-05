#pragma once
#ifndef Enemy_hpp
#define Enemy_hpp
#include "Vector.hpp"
#include <SDL.h> 
#include <SDL_image.h>
#include <vector>
#include "TextureManager.hpp"
#include "KeysPressed.hpp"
#include "Platform.hpp"
#include "Player.hpp"
#define RIGHT true
#define LEFT false

class Enemy {
public:
    // Constructor
	Enemy(Vector start, Vector end);
    Enemy(Platform p, Vector spawn, bool d);
	Enemy();
    
    void updateVelocity();
    void updateAcceleration();
    void updateDirection();
    bool collides(Vector v);
    
    virtual void render(SDL_Renderer * renderer);
    virtual void updatePosition(Player play);
    virtual void update(Player player);
	bool facingRight();
	Vector getPostion();
    
protected:
    Platform platform;
    Vector velocity;
    Vector acceleration;
    bool isFalling;
    Vector start;
    Vector end;
    bool direction;
    Vector position;
};

#endif
