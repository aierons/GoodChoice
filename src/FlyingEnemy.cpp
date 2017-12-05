#include "FlyingEnemy.hpp"
FlyingEnemy::FlyingEnemy(Vector s){
    start = s;
    direction = RIGHT;
    position = s;
    velocity = Vector(1, 0);
    upAndDown = 0;
}

void FlyingEnemy::update(Player player) {
    updatePosition(player);
}

void FlyingEnemy::updatePosition(Player player) {
    int x = (int) this->position.getX();
    int y = (int) this->position.getY();
    int x2 = (int) player.position.getX();
    int y2 = (int) player.position.getY();
    Vector slope = Vector((x2 - x) / 25, (y2 - y) / 25);
    Vector inverse_slope = Vector((x2 - x) / 25, (y2 - y) / 25) * -1;
    if (player.isIdle()) {
        if (this->position.getX() <= player.position.getX()) {
            this->position += slope / 5;
            direction = RIGHT;
        }
        else {
            this->position -= inverse_slope / 5;
            direction = LEFT;
        }
    } else {
        if (this->position.getX() <= player.position.getX()) {
            this->position += slope;
            direction = RIGHT;
        }
        else {
            this->position -= inverse_slope;
            direction = LEFT;
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

