#pragma once
#ifndef PlatformBullet_hpp
#define PlatformBullet_hpp

#include "Bullet.h"

class PlatformBullet : Bullet {
public:
	virtual bool collidesWithPlatform(Platform p); //alternatively could take in list of platforms
private:
	int lifetime;
	Vector position;
	Vector velocity;
};

#endif