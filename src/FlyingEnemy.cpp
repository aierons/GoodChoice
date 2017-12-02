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
    Vector slope = Vector((x2 - x) / 100, (y2 - y) / 100);
    if (this->position.getX() > player.position.getX()){
         this->position += slope;
    } else {
         this->position -= -1 * slope;
    }
}
void FlyingEnemy::render(SDL_Renderer * renderer) {
    SDL_Texture * enemyTex;
    SDL_Rect destRect;
    
    enemyTex = TextureManager::loadTexture("/Users/wesleyjiang/Desktop/Testing/res/flying.png", renderer);
    destRect.w = 23;
    destRect.h = 23;
    
    destRect.x = position.getX();
    destRect.y = 600 - position.getY();
    
    SDL_RenderCopy(renderer, enemyTex, NULL, &destRect);
}



