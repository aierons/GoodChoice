#pragma once
#ifndef Goal_hpp
#define Goal_hpp

#include "Vector.hpp"
#include "SDL.h"
#include "SDL_image.h"

class Goal {
public:
	Goal(Vector pos);
	bool collides(Vector p);
	void render(SDL_Renderer * renderer);
private:
	Vector position;
};

#endif