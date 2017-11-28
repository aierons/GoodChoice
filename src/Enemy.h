#pragma once
#ifndef Enemy_hpp
#define Enemy_hpp
#include "Vector.hpp"
#include "SDL.h"
#include "SDL_image.h"

class Enemy { //maybe this will be abstract if there are multiple types of enemies
	Enemy(Vector start, Vector end);
	void render(SDL_Renderer * renderer);
	void updatePosition();
	void updateEnemy();

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
