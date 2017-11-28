#include "Enemy.h"
#include "Vector.hpp"

Enemy::Enemy() { 
	position = Vector(0, 0);
}
	//idk if we want this
Enemy::Enemy(Vector pos) {
	position = pos;
}
void Enemy::updatePosition() {}
void Enemy::die() {}
bool Enemy::collides(Vector v) { return false; }//dummy for now