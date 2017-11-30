#include "Enemy.h"

Enemy::Enemy(Vector s, Vector e) {
    start = s;
    end = e;
    direction = true;
    position = s;
    velocity = Vector(1, 0);
    acceleration = Vector(0, 0);
}
Enemy::Enemy() {}
void Enemy::jump() {
    velocity[1] += 1;
    acceleration.setY(1.2);
}
void Enemy::updatePosition() {
    position += velocity;
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


void Enemy::updateDirection() {
    if (position.getX() <= start.getX() && !direction) {
        direction = true;
    }
    else if (position.getX() >= end.getX() && direction) {
        direction = false;
    }
}

void Enemy::update(vector<Platform> platforms) {
    if (direction) {
        velocity[0] = 2;
    } else {
        velocity[0] = -2;
    }
    updatePosition();
    updateDirection();
}

void Enemy::die() {
    
}
bool Enemy::collides(Vector v) {
    vector<Vector> hitBox = this->getHitBox();
		return v.getX() > hitBox.at(0).getX() && v.getX() > hitBox.at(1).getX()
           && v.getX() < hitBox.at(2).getX() && v.getX() < hitBox.at(3).getX()
           && v.getY() < hitBox.at(0).getY() && v.getY() < hitBox.at(1).getY()
           && v.getY() > hitBox.at(2).getY() && v.getY() < hitBox.at(3).getY();
	//return v == this->position;
}

vector<Vector> Enemy::getHitBox(){
    int enemySize = 23;
    vector<Vector> points;
    //Top Left
    points.push_back(Vector(this->position.getX() - enemySize / 2, this->position.getY() - enemySize / 2));
    //Bottom Left .. etc
    points.push_back(Vector(this->position.getX() - enemySize / 2, this->position.getY() + enemySize / 2));
    points.push_back(Vector(this->position.getX() + enemySize / 2, this->position.getY() - enemySize / 2));
    points.push_back(Vector(this->position.getX() - enemySize / 2, this->position.getY() + enemySize / 2));
    return points;
}

void Enemy::render(SDL_Renderer * renderer) {
    SDL_Texture * enemyTex;
    SDL_Rect destRect;

    enemyTex = TextureManager::loadTexture("res/enemy.png", renderer);
    destRect.w = 23;
    destRect.h = 23;

    destRect.x = position.getX();
    destRect.y = 600 - position.getY();

    SDL_RenderCopy(renderer, enemyTex, NULL, &destRect);
}
