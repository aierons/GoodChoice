#include "Platform.hpp"
#include "Vector.hpp"

Platform::Platform(Vector start_v, Vector end_v, bool vis) {
	start_x = start_v.getX();
	start_y = start_v.getY();
	end_x = end_v.getX();
	end_y = end_v.getY();
	visible = vis;
}

Platform::Platform(Vector start_v, Vector end_v) : Platform(start_v, end_v, true) { }