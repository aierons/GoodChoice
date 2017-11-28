#include "Enemy.h"
#include "Vector.hpp"
#include <vector>
#include "TextureManager.hpp"

Enemy::Enemy(Vector s, Vector e) {
	start = s;
	end = e;
	direction = true;
	posn = s;
	velocity = Vector(5, 0);
	acceleration = Vector(0, 0);
}
void Enemy::die() {
  delete this;
}

bool Enemy::collides(Vector v) {
	vector<Vector> hitBox = this->getHitBox();
	return v.getX() > hitBox.at(0).getX() && v.getX() > hitBox.at(1).getX()
			&& v.getX() < hitBox.at(2).getX() && v.getX() < hitBox.at(3).getX()
			&& v.getY() < hitBox.at(0).getY() && v.getY() < hitBox.at(1).getY()
			&& v.getY() > hitBox.at(2).getY() && v.getY() < hitBox.at(3).getY();
}


void Enemy::updatePosition() {
	if (this->direction) {
		posn += velocity;
	} else {
		posn -= velocity;
	}

	cout << posn << endl;
}

void Enemy::move() {
	if (this->direction) {
		velocity[0] = 5; // Moves Right
	}
	else {
		velocity[0] = -5; //Moves Left
	}
}

bool Enemy::reachEnd() {
	return posn.getX() < start.getX()
		&& posn.getX() > end.getX();
}

void Enemy::updateEnemy() {
	if (reachEnd()) {
		flip();
	}
	updatePosition();
}

void Enemy::updateVelocity() {
	velocity += acceleration;
}

void Enemy::flip() {
	this->direction = !this->direction;
}

vector<Vector> Enemy::getHitBox(){
	int enemySize = 23;
	vector<Vector> points;
	//Top Left
	points.push_back(Vector(this->posn.getX() - enemySize / 2, this->posn.getY() - enemySize / 2));
	//Bottom Left .. etc
	points.push_back(Vector(this->posn.getX() - enemySize / 2, this->posn.getY() + enemySize / 2));
	points.push_back(Vector(this->posn.getX() + enemySize / 2, this->posn.getY() - enemySize / 2));
	points.push_back(Vector(this->posn.getX() - enemySize / 2, this->posn.getY() + enemySize / 2));

  return points;
}

void Enemy::render(SDL_Renderer * renderer) {
	SDL_Texture * platformTex;
	SDL_Rect destRect;

	platformTex = TextureManager::loadTexture("res/enemy.png", renderer);
	destRect.w = 23;
	destRect.h = 23;

	destRect.x = posn.getX();
	destRect.y = 600 - posn.getY();

	SDL_RenderCopy(renderer, platformTex, NULL, &destRect);
}
