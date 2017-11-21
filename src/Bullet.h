#pragma once
#ifndef Bullet_hpp
#define Bullet_hpp
#include "Vector.hpp"
#include "SDL.h"
#include "SDL_image.h"

class Bullet { //abstract class Bullet - will be extended by each type of bullet
public:
	Bullet();
	virtual ~Bullet() = 0;
	void updatePosition();
	void updateLifetime();
	bool collidesWithPlatform(Platform p); //alternatively could take in list of platforms
private:
	int lifetime;
	Vector postion;
	Vector velocity;
};
#endif