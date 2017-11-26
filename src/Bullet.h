#pragma once
#ifndef Bullet_hpp
#define Bullet_hpp
#include "Vector.hpp"
#include "Platform.hpp"
#include "SDL.h"
#include "SDL_image.h"

class Bullet { //abstract class Bullet - will be extended by each type of bullet
public:
	Bullet(Vector pos, Vector vel);
	void updatePosition();
	void updateLifetime();
	bool done();
	virtual bool collidesWithPlatform(Platform& p) = 0; //alternatively could take in list of platforms
	virtual void render(SDL_Renderer* renderer) = 0;
protected:
	int lifetime;
	Vector position;
	Vector velocity;
	int width = 7;
	int height = 7;
};
#endif