#pragma once

#include "Game.hpp"

/*
 * This class will facilitate adding images from files into the renderer.
 */
class TextureManager {
  public:
    static SDL_Texture * loadTexture(const char * fileName, SDL_Renderer * renderer);
};