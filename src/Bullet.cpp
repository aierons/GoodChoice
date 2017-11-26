#include "Bullet.h"

	Bullet::Bullet(Vector pos, Vector vel) {
		position = pos;
		velocity = vel;
		lifetime = 50; //could be anything, just a dummy value for now
	}
	void Bullet::updatePosition() {
		position += velocity;
	}
	void Bullet::updateLifetime() {
		lifetime--;
	}
	bool Bullet::done() {
		return lifetime <= 0;
	}
