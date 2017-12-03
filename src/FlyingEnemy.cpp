//
//  NormalEnemy.cpp
//  testing
//
//  Created by Wesley Jiang on 12/1/17.
//  Copyright © 2017 Wesley Jiang. All rights reserved.
//

#include "FlyingEnemy.hpp"

FlyingEnemy::FlyingEnemy(Vector s, Vector e) : Enemy(s, e) {}

void FlyingEnemy::update(Player player) {
    if (direction) {
        velocity[0] = 2;
    } else {
        velocity[0] = -2;
    }
    updatePosition(player);
    updateDirection();
}

void FlyingEnemy::updatePosition(Player player) {
    int x = (int) this->position.getX();
    int y = (int) this->position.getY();
    int x2 = (int) player.position.getX();
    int y2 = (int) player.position.getY();
    Vector slope = Vector((x2 - x) / 25, (y2 - y) / 25);
	if (player.isIdle()) {
		// still gotta move if it is idle
	}
	else {
		if (this->position.getX() > player.position.getX()) {
			this->position += slope;
		}
		else {
			this->position -= -1 * slope;
		}
	}

}
void FlyingEnemy::render(SDL_Renderer * renderer) {
    SDL_Texture * enemyTex;
    SDL_Rect destRect;
    
    enemyTex = TextureManager::loadTexture("res/flying.png", renderer);
    destRect.w = 40;
    destRect.h = 40;
    
    destRect.x = position.getX();
    destRect.y = 600 - position.getY();
    
    SDL_RenderCopy(renderer, enemyTex, NULL, &destRect);
	SDL_DestroyTexture(enemyTex);
}



