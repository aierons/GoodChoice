#ifndef Platform_hpp
#define Platform_hpp

class Platform {
public:
	Platform(Vector start_v, Vector end_v);
	Platform(Vector start_v, Vector end_v, bool vis);
private:
	int start_x; //lower or left end
	int start_y; //lower or left end
	int end_x; //upper or right end
	int end_y; //upper or right end
	bool visible;
};

#endif