#include "Enemy.h"
#include "Vector.hpp"

Enemy::Enemy(Vector s, Vector e) {
	start = s;
	end = e;
	direction = true;
	posn = Vector(s);
	velocity = Vector(5, 0);
	acceleration = Vector(0, 0);
}
void Enemy::die() {}
bool Enemy::collides(Vector v) { return false; }//dummy for now

void g::updatePosition() {
	if (this->direction) {
		posn += velocity;
	}
	else {
		posn -= velocity;
	}
	cout << posn.getX() << endl;
}

void g::move() {
	if (this->direction) {
		velocity[0] = 5; // Moves Right
	}
	else {
		velocity[0] = -5; //Moves Left
	}
}

bool g::reachEnd() {
	return posn.getX() < start.getX()
		&& posn.getX() > end.getX();
}

void g::updateEnemy() {
	if (reachEnd()) {
		flip();
	}
	updatePosition();
}

void g::updateVelocity() {
	velocity += acceleration;
}

void g::flip() {
	this->direction = !this->direction;
}

void g::render(SDL_Renderer * renderer) {
	SDL_Texture * platformTex;
	SDL_Rect destRect;

	platformTex = TextureManager::loadTexture("res/enemy.png", renderer);
	destRect.w = 23;
	destRect.h = 23;

	destRect.x = posn.getX();
	destRect.y = 600 - posn.getY();

	SDL_RenderCopy(renderer, platformTex, NULL, &destRect);
}
