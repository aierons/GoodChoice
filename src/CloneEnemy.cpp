#include "CloneEnemy.h"

CloneEnemy::CloneEnemy(Platform p, Vector spawn, bool d){
	start = Vector(p.getStartX(), p.getEndY());
	end = Vector(p.getEndX(), p.getEndY());
	direction = d;
	position = spawn;
	velocity = Vector(4, 0);
	acceleration = Vector(0, 0);
	platform = p;
	hasCloned = false;
}

void CloneEnemy::update(Player player) {
	if (direction) {
		velocity[0] = 2;
	}
	else {
		velocity[0] = -2;
	}
	updatePosition(player);
	updateDirection();
}
void CloneEnemy::updatePosition(Player player) {
	position += velocity;
}
void CloneEnemy::render(SDL_Renderer * renderer) {
	SDL_Texture * enemyTex;
	SDL_Rect destRect;
    if (direction == RIGHT) {
        enemyTex = TextureManager::loadTexture("/Users/ChrisRisley/Desktop/fk/fk/res/cloneRight.png", renderer);
    }
    else {
        enemyTex = TextureManager::loadTexture("/Users/ChrisRisley/Desktop/fk/fk/res/cloneLeft.png", renderer);
    }
	destRect.w = 32;
	destRect.h = 32;

	destRect.x = position.getX();
	destRect.y = 600 - position.getY() + 5;

	SDL_RenderCopy(renderer, enemyTex, NULL, &destRect);
}

