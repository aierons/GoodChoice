#include "PlatformBullet.h"
#include "Platform.hpp"

PlatformBullet::PlatformBullet(Vector pos, Vector vel) : Bullet(pos, vel) { }

bool PlatformBullet::collidesWithPlatform(Platform& p) {
	if (p.collides(position)) {
		if (!p.isVisible()) {
			p.show();
		}
		return true;
	}
	return false;
}

void PlatformBullet::render(SDL_Renderer* renderer) {
	SDL_Texture * tex;
	SDL_Rect destRect;

	tex = TextureManager::loadTexture("res/PlatformBullet.png", renderer);
	destRect.w = width;
	destRect.h = height;

	destRect.x = position.getX();
	destRect.y = (630 - destRect.h) - position.getY();

	SDL_RenderCopy(renderer, tex, NULL, &destRect);
}

bool PlatformBullet::collidesWithEnemy(Enemy& e) {
	return e.collides(position);
}
