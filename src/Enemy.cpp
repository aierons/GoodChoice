#include "Enemy.h"

Enemy::Enemy(Vector s, Vector e) {
    start = s;
    end = e;
    direction = true;
    position = s;
    velocity = Vector(1, 0);
    acceleration = Vector(0, 0);
}

Enemy::Enemy(Platform p, Vector spawn, bool d){
    start = Vector(p.getStartX(), p.getEndY());
    end = Vector(p.getEndX(), p.getEndY());
    direction = d;
    position = spawn;
    velocity = Vector(1, 0);
    acceleration = Vector(0, 0);
    platform = p;
}
Enemy::Enemy() {
	start = Vector(1, 0);
	end = Vector(0, 0);
	direction = true;
	position = start;
	velocity = Vector(1, 0);
	acceleration = Vector(0, 0);
}

bool Enemy::facingRight() {
	return direction;
}

Vector Enemy::getPostion() {
	return Vector(position.getX(), position.getY());
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
    
    if (direction == RIGHT) {
        enemyTex = TextureManager::loadTexture("res/enemyRight.png", renderer);
    }
    else{
        enemyTex = TextureManager::loadTexture("res/enemyLeft.png", renderer);
    }
    destRect.w = 50;
    destRect.h = 50;
    
    destRect.x = position.getX();
    destRect.y = 600 - position.getY();
    
    SDL_RenderCopy(renderer, enemyTex, NULL, &destRect);
    SDL_DestroyTexture(enemyTex);
}


void Enemy::updateDirection() {
    if (position.getX() < start.getX() && !direction) {
        direction = true;
    }
    else if (position.getX() > end.getX() && direction) {
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
