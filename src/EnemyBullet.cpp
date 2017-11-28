#include "EnemyBullet.h"
#include "Platform.hpp"

EnemyBullet::EnemyBullet(Vector pos, Vector vel) : Bullet(pos, vel) { }

bool EnemyBullet::collidesWithPlatform(Platform& p) {
	return p.collides(position) && p.isVisible();
}

void EnemyBullet::render(SDL_Renderer* renderer) {
	SDL_Texture * tex;
	SDL_Rect destRect;

	tex = TextureManager::loadTexture("res/EnemyBullet.png", renderer);
	destRect.w = width;
	destRect.h = height;

	destRect.x = position.getX();
	destRect.y = (630 - destRect.h) - position.getY();

	SDL_RenderCopy(renderer, tex, NULL, &destRect);
}

bool EnemyBullet::collidesWithEnemy(Enemy& e) {
	if(e.collides(position)) {
		e.die();
		return true;
	}
	return false;
}


Vector EnemyBullet::getPosition() {
	return position;
}

