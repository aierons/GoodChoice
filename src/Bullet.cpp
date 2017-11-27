#include "Bullet.h"

	Bullet::Bullet(Vector pos, Vector vel) {
		position = pos;
		velocity = vel;
		lifetime = 100; //could be anything, just a dummy value for now
	}
	
	void Bullet::updatePosition() {
		position += velocity;
		lifetime--;
	}

	bool Bullet::isAlive() {
		/*if (bullet.position > SCREEN_WIDTH) {
			alive = false;
		}
		return alive;*/
		return lifetime >= 0;
	}