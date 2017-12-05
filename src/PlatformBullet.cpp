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
	SDL_Rect destRect;

    if (texture == NULL){
	texture = TextureManager::loadTexture("res/PlatformBullet.png", renderer);
    }
	destRect.w = width;
	destRect.h = height;

	destRect.x = position.getX();
	destRect.y = (630 - destRect.h) - position.getY();

	SDL_RenderCopy(renderer, texture, NULL, &destRect);
}


bool PlatformBullet::collidesWithEnemy(Enemy& e) {
	return e.collides(position);
}

void PlatformBullet::deleteTexture(){
    SDL_DestroyTexture(texture);
}
