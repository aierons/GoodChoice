#include "FlyingEnemy.hpp"

FlyingEnemy::FlyingEnemy(Vector s){
    start = s;
    direction = true;
    position = s;
    velocity = Vector(1, 0);
}

void FlyingEnemy::update(Player player) {

    updatePosition(player);
    updateDirection();
}

void FlyingEnemy::updatePosition(Player player) {
    int x = (int) this->position.getX();
    int y = (int) this->position.getY();
    int x2 = (int) player.position.getX();
    int y2 = (int) player.position.getY();
    Vector slope = Vector((x2 - x) / 15, (y2 - y) / 15);

	if (player.isIdle()) {
		// still gotta move if it is idle
	}
	else {
		if (this->position.getX() > player.position.getX()) {
			this->position += slope;
            direction = RIGHT;
		}
		else {
			this->position -= slope * -1;
		}
	}

}
void FlyingEnemy::render(SDL_Renderer * renderer) {
    SDL_Texture * enemyTex;
    SDL_Rect destRect;
    
    if (direction == RIGHT) {
        enemyTex = TextureManager::loadTexture("res/flyingRight.png", renderer);
    }
    else {
        enemyTex = TextureManager::loadTexture("res/flyingLeft.png", renderer);
    }
    destRect.w = 40;
    destRect.h = 40;
    
    destRect.x = position.getX();
    destRect.y = 600 - position.getY();
    
    SDL_RenderCopy(renderer, enemyTex, NULL, &destRect);
	SDL_DestroyTexture(enemyTex);
}


