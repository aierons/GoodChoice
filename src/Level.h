#pragma once
#ifndef Level_hpp
#define Level_hpp

#include "Platform.hpp"
#include "Bullet.h"
#include "PlatformBullet.h"
#include "EnemyBullet.h"
#include "NormalEnemy.hpp"
#include "FlyingEnemy.hpp"

struct Level {
public:
	vector<Platform> platforms;
	vector<PlatformBullet> pBullets;
	vector<EnemyBullet> eBullets;
	vector<NormalEnemy> enemies;
	vector<FlyingEnemy> flyingenemies;
	Goal * goal;
};
#endif
