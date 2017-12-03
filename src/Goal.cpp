#include "Goal.h"
#include "TextureManager.hpp"

Goal::Goal(Vector pos) {
	position = pos;
}
bool Goal::collides(Vector v) {
	return (v.getX() - position.getX() < 20 && v.getX() - position.getX() > -20)
		&& (v.getY() - position.getY() < 20 && v.getY() - position.getY() > -20);
}
void Goal::render(SDL_Renderer * renderer) {
	SDL_Texture * tex;
	SDL_Rect destRect;

	tex = TextureManager::loadTexture("res/Goal.png", renderer);
	destRect.w = 30;
	destRect.h = 30;

	destRect.x = position.getX();
	destRect.y = (630 - destRect.h) - position.getY();

	SDL_RenderCopy(renderer, tex, NULL, &destRect);
	SDL_DestroyTexture(tex);
}