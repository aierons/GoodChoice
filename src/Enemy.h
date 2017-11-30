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
	Enemy();
	Enemy(Vector start, Vector end);
	void jump();
	virtual void updatePosition();
	void updateVelocity();
	void updateAcceleration();
	void update(vector<Platform> platforms);
	virtual void render(SDL_Renderer * renderer);
	void updateDirection();
	Vector position;
	void die();
	bool collides(Vector v);
	//do we need to check for colliding with platforms? If we make it so the player can drop them we should. If they stay on on-platform paths we don't have to
protected:
	Vector velocity;
	Vector acceleration;
	bool isFalling;
	Vector start;
	Vector end;

	bool direction;
	vector<Vector> getHitBox();
	
};

#endif
