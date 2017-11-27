#include "Bullet.h"

	Bullet::Bullet(Vector pos, Vector vel) {
		position = pos;
		velocity = vel;
		lifetime = 50; //could be anything, just a dummy value for now
	}

	void Bullet::shoot() { 
		if (event.key == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
			position = player.position;
			render();
			updatePosition();
		}
	}
	
	void Bullet::updatePosition() {
		position += velocity; 
	}

	bool Bullet::isAlive() {
		if (bullet.position > SCREEN_WIDTH) {
			alive = false;
		}
		return alive;
	}

	bool Bullet::collidesWithPlatform(Platform& p) {
		return p.collides(position);
	} 

	bool Bullet::collidesWithEnemy(Enemy& e) {
		return e.collides(position);
	}

	void Bullet::render() {
		SDL_Texture * tex;
		SDL_Rect destRect;

		tex = TextureManager::loadTexture("res/pixel_bullet.png", renderer); // this only faces left so might have to change the chosen picture
		destRect.w = 100;
		destRect.h = 100;

		destRect.x = position.getX();
		destRect.y = 600 - position.getY();

		SDL_RenderCopy(renderer, tex, NULL, &destRect);
	}
