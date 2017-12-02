//
//  NormalEnemy.cpp
//  testing
//
//  Created by Wesley Jiang on 12/1/17.
//  Copyright © 2017 Wesley Jiang. All rights reserved.
//

#include "NormalEnemy.hpp"

NormalEnemy::NormalEnemy(Vector s, Vector e) : Enemy(s, e) {}
 
void NormalEnemy::update(Player player) {
    if (direction) {
        velocity[0] = 2;
    } else {
        velocity[0] = -2;
    }
    updatePosition(player);
    updateDirection();
}
void NormalEnemy::updatePosition(Player player) {
    position += velocity;
}
void NormalEnemy::render(SDL_Renderer * renderer) {
    SDL_Texture * enemyTex;
    SDL_Rect destRect;

    enemyTex = TextureManager::loadTexture("res/enemy.png", renderer);
    destRect.w = 23;
    destRect.h = 23;

    destRect.x = position.getX();
    destRect.y = 600 - position.getY();

    SDL_RenderCopy(renderer, enemyTex, NULL, &destRect);
}


