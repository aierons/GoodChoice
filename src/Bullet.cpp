#include "Bullet.h"

	Bullet::Bullet(Vector pos, Vector vel) {
		position = pos;
		velocity = vel;
		lifetime = 100; //could be anything, just a dummy value for now
	}
	void Bullet::updatePosition() {
		position += velocity;
	}
	void Bullet::updateLifetime() {
		if (lifetime == 0) {
			delete this;
			return;
		}
		lifetime--;
	}
