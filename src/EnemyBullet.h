#pragma once
#ifndef EnemyBullet_hpp
#define EnemyBullet_hpp

#include "Bullet.h"

class EnemyBullet : public Bullet {
public:
	EnemyBullet(Vector pos, Vector vel);
	virtual bool collidesWithPlatform(Platform& p); //alternatively could take in list of platforms
	virtual void render(SDL_Renderer* renderer);
	virtual bool collidesWithEnemy(Enemy& e);
};

#endif