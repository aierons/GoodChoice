
#include "NormalEnemy.hpp"

NormalEnemy::NormalEnemy(Vector s, Vector e) : Enemy(s, e) {}

NormalEnemy::NormalEnemy(Platform p, Vector spawn, bool d) : Enemy(p, spawn, d){}
 
void NormalEnemy::update(Player player) {
    if (direction) {
        velocity[0] = 2;
    } else {
        velocity[0] = -2;
    }
    updatePosition(player);
    updateDirection();
}
void NormalEnemy::updatePosition(Player player) {
    position += velocity;
}
void NormalEnemy::render(SDL_Renderer * renderer) {
    SDL_Rect destRect;

    if (texture == NULL){
    texture = TextureManager::loadTexture("res/enemy.png", renderer);
    }
    destRect.w = 100;
    destRect.h = 100;

    destRect.x = position.getX();
    destRect.y = 600 - position.getY();

    SDL_RenderCopy(renderer, texture, NULL, &destRect);
    
    
}
