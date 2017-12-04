
#include "NormalEnemy.hpp"

NormalEnemy::NormalEnemy(Vector s, Vector e) : Enemy(s, e) {}
 
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
    SDL_Texture * enemyTex;
    SDL_Rect destRect;

    enemyTex = TextureManager::loadTexture("/Users/wesleyjiang/Desktop/Final/Final/res/enemy.png", renderer);
    destRect.w = 100;
    destRect.h = 100;

    destRect.x = position.getX();
    destRect.y = 600 - position.getY();

    SDL_RenderCopy(renderer, enemyTex, NULL, &destRect);
    SDL_DestroyTexture(enemyTex);
}
