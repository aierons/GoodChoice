#include "Bullet.h"

int Bullet::count = 0;

Bullet::Bullet(Vector pos, Vector vel) {
	Bullet::count++;
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

Vector Bullet::getInitialVector(Vector pVector, Vector mVector) {
  double dx = mVector.getX() - pVector.getX();
  double dy = mVector.getY() - pVector.getY();

  cout << dx << endl;
  cout << dy << endl << endl;

  return (Vector(dx, dy) / sqrt(pow(dx, 2) + pow(dy, 2)) * 5);
}

Vector Bullet::getPosition() {
    return position;
}
