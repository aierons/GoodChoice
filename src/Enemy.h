#pragma once
#ifndef Enemy_hpp
#define Enemy_hpp
#include "Vector.hpp"
#include "SDL.h"
#include "SDL_image.h"

class Enemy { //maybe this will be abstract if there are multiple types of enemies
public:
	Enemy(Vector start, Vector end);
	void updatePosition();
	void render(SDL_Renderer * renderer);
	void updateEnemy();
	void die();
	bool collides(Vector v);
	//do we need to check for colliding with platforms? If we make it so the player can drop them we should. If they stay on on-platform paths we don't have to
private:
	Vector start;
	Vector end;
	Vector posn;
	Vector velocity;
	Vector acceleration;
	bool direction;

	bool reachEnd();
	void move();
	void flip();
	void updateVelocity();
	
};

#endif
