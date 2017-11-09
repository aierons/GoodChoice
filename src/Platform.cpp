#include "Platform.hpp"

Platform::Platform(Vector start_v, Vector end_v, bool vis) {
  start_x = start_v.getX();
  start_y = start_v.getY();
  end_x = end_v.getX();
  end_y = end_v.getY();
  visible = vis;
}

Platform::Platform(Vector start_v, Vector end_v) : Platform(start_v, end_v, true) { }

bool Platform::collides(Vector v) {
  return v.getX() >= start_x 
      && v.getY() >= start_y
      && v.getX() <= end_x
      && v.getY() <= end_y;
}

void Platform::render(SDL_Renderer * renderer) {
  SDL_Texture * platformTex;
  SDL_Rect destRect;

  platformTex = TextureManager::loadTexture("res/platform.png", renderer);
  destRect.w = end_x - start_x;
  destRect.h = end_y - start_y;

  destRect.x = start_x;
  destRect.y = (630 - destRect.h) - start_y;

  SDL_RenderCopy(renderer, platformTex, NULL, &destRect);
}

int Platform::getEndY() {
  return end_y;
}