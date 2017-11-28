#pragma once
#ifndef Bullet_hpp
#define Bullet_hpp
#include "Vector.hpp"
#include "Platform.hpp"
#include "Enemy.h"
#include "SDL.h"
#include "SDL_image.h"

#include <math.h>

class Bullet { //abstract class Bullet - will be extended by each type of bullet
public:
	Bullet(Vector pos, Vector vel);
	//void shoot(); // not sure if this is the most appropriate place to put it
	void updatePosition();
	bool isAlive();
  static Vector getInitialVector(Vector pVector, Vector mVector);
	virtual bool collidesWithPlatform(Platform& p) = 0; //alternatively could take in list of platforms
	virtual bool collidesWithEnemy(Enemy& e) = 0;
	virtual void render(SDL_Renderer* renderer) = 0;

	virtual Vector getPosition();

protected:
	bool alive;
	Vector position;
	Vector velocity;
	int lifetime;
	int width = 7;
	int height = 7;
};
#endif
