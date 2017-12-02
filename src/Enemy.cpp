#include "Enemy.h"

Enemy::Enemy(Vector s, Vector e) {
    start = s;
    end = e;
    direction = true;
    position = s;
    velocity = Vector(1, 0);
    acceleration = Vector(0, 0);
}

void Enemy::updateVelocity() {
    velocity += acceleration;
}
void Enemy::updateAcceleration() {
    //if (isFalling) {
    //    acceleration[1] -= .1;
    //} else {
    //    acceleration[1] = 0;
    //}
}

void Enemy::update(Player player) {
    if (direction) {
        velocity[0] = 2;
    } else {
        velocity[0] = -2;
    }
    updatePosition(player);
    updateDirection();
}
void Enemy::updatePosition(Player player) {
    position += velocity;
}
void Enemy::render(SDL_Renderer * renderer) {
    SDL_Texture * enemyTex;
    SDL_Rect destRect;
    
    enemyTex = TextureManager::loadTexture("/Users/wesleyjiang/Desktop/Testing/res/enemy.png", renderer);
    destRect.w = 23;
    destRect.h = 23;
    
    destRect.x = position.getX();
    destRect.y = 600 - position.getY();
    
    SDL_RenderCopy(renderer, enemyTex, NULL, &destRect);
}


void Enemy::updateDirection() {
    if (position.getX() <= start.getX() && !direction) {
        direction = true;
    }
    else if (position.getX() >= end.getX() && direction) {
        direction = false;
    }
}

bool Enemy::collides(Vector point) {
    if (point.getX() <= position.getX() + 15 && point.getX() >= position.getX() - 15
        && point.getY() <= position.getY() + 15 && point.getY() >= position.getY() - 15) {
        return true;
    }
    else {
        return false;
    }
}
