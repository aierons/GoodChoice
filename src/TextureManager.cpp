#include "TextureManager.hpp"

/*
 * Loads the image file on to the renderer
 */
SDL_Texture * TextureManager::loadTexture(const char * fileName, SDL_Renderer * renderer) {
  SDL_Surface * tmpSurface = IMG_Load(fileName);
  SDL_Texture * tex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
  SDL_FreeSurface(tmpSurface);
  return tex;
}