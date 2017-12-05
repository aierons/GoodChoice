
#include "InvincibleEnemy.hpp"

InvincibleEnemy::InvincibleEnemy(Vector s, Vector e) : Enemy(s, e) {}

InvincibleEnemy::InvincibleEnemy(Platform p, Vector spawn, bool d) : Enemy(p, spawn, d){}


void InvincibleEnemy::update(Player player) {
    if (direction) {
        velocity[0] = 4;
    } else {
        velocity[0] = -4;
    }
    updatePosition(player);
    updateDirection();
}
void InvincibleEnemy::updatePosition(Player player) {
    position += velocity;
}

void InvincibleEnemy::render(SDL_Renderer * renderer) {
    SDL_Texture * enemyTex;
    SDL_Rect destRect;
    
    if (direction == RIGHT) {
        enemyTex = TextureManager::loadTexture("/Users/wesleyjiang/Desktop/works/works/invincibleRight.png", renderer);
    }
    else{
        enemyTex = TextureManager::loadTexture("/Users/wesleyjiang/Desktop/works/works/invincibleLeft.png", renderer);
    }
    cout << "got it" << endl;
    destRect.w = 60;
    destRect.h = 60;
    
    destRect.x = position.getX();
    destRect.y = 600 - position.getY();
    
    SDL_RenderCopy(renderer, enemyTex, NULL, &destRect);
    SDL_DestroyTexture(enemyTex);
}
