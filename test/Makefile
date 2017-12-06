HEADERS = Bullet.h CloneEnemy.h Enemy.h EnemyBullet.h PlatformBullet.h Vector.hpp FlyingEnemy.hpp NormalEnemy.hpp Goal.h Game.hpp
OBJECTS = Bullet.o CloneEnemy.o Enemy.o EnemyBullet.o PlatformBullet.o Vector.o FlyingEnemy.o NormalEnemy.o Goal.o Game.o
INC=-I/usr/local/include/SDL2 #replace this with the path that SDL2 is installed, may also need the path for SDL2_image

.PHONY: all clean

all: main

main: $(OBJECTS)
	g++ $^ -o main

%.o: %.cpp $(HEADERS)
	g++ $(INC) -c $< -o $@

clean:
	rm -f $(OBJECTS) main
