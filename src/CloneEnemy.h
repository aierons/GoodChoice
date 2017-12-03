#pragma once
#ifndef CloneEnemy_hpp
#define CloneEnemy_hpp
#include "Enemy.h"

class CloneEnemy : public Enemy {
public:
	CloneEnemy(Platform p, Vector Spawn, bool direction);
	virtual void render(SDL_Renderer * renderer);
	virtual void updatePosition(Player player);
	virtual void update(Player player);

	Platform platform;
	bool hasCloned;

};


#endif /* CloneEnemy_hpp */
