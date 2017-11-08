#ifndef Platform_hpp
#define Platform_hpp
#include "Vector.hpp"

class Platform {
public:
	Platform(Vector start_v, Vector end_v);
	Platform(Vector start_v, Vector end_v, bool vis);
	bool collides(Vector v);
private:
	double start_x; //lower or left end
	double start_y; //lower or left end
	double end_x; //upper or right end
	double end_y; //upper or right end
	bool visible;
};

#endif