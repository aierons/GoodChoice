#pragma once
#ifndef PlatformBullet_hpp
#define PlatformBullet_hpp

#include "Bullet.h"

class PlatformBullet : public Bullet {
public:
	PlatformBullet(Vector pos, Vector vel);
	virtual bool collidesWithPlatform(Platform& p); //alternatively could take in list of platforms
	virtual void render(SDL_Renderer* renderer);
};

#endif