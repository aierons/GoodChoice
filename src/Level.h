#pragma once
#ifndef Level_hpp
#define Level_hpp

#include "Platform.hpp"
#include "Bullet.h"
#include "PlatformBullet.h"
#include "EnemyBullet.h"
#include "NormalEnemy.hpp"
#include "FlyingEnemy.hpp"
#include "cloneEnemy.h"

struct Level {
public:
	vector<Platform> platforms;
	vector<PlatformBullet> pBullets;
	vector<EnemyBullet> eBullets;
	vector<NormalEnemy> normalEnemies;
	vector<FlyingEnemy> flyingenemies;
	vector<CloneEnemy> cloneEnemies;
	Goal * goal;
};
#endif
