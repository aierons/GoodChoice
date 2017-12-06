#include <cxxtest/TestSuite.h>
#include <iostream>
#include "Vector.hpp"
#include "TextureManager.hpp"
#include "KeysPressed.hpp"
#include "Platform.hpp"
#include "Player.hpp"

class EnemyTest : public CxxTest::TestSuite
{
public:

    //testing if the enemy constructor for start and end work appropriately
    void EnemyConstructor(void) {
      Vector v1 = new Vector(50, 50);
      Vector v2 = new Vector(100, 100);
      Enemy e1 = new Enemy(v1, v2);
      TS_ASSERT_EQUALS(e1.start, v1);
      TS_ASSERT_EQUALS(e1.end, v2);
    }

    //testing if the enemy constructor for spawning works appropriately
    void EnemySpawnConstructor(void) {
      Vector v1 = new Vector(50, 50);
      Vector v2 = new Vector(100, 100);
      Vector spawn = new Vector(65, 60);
      Platform platform = new Platform(v1,v2);
      Enemy e1 = new Enemy(platform, spawn, true);
      TS_ASSERT_EQUALS(e1.platform, platform);
      TS_ASSERT_EQUALS(e1.getPosition(), spawn);
      TS_ASSERT(e1.d, true);
    }

    //testing if the enemy updates its velocity appropriately
    void EnemyUpdateVelocity(void) {
      Vector v1 = new Vector(50, 50);
      Vector v2 = new Vector(100, 100);
      Enemy e1 = new Enemy(v1, v2);
      e1.updateVelocity();
      TS_ASSERT_EQUALS(e1.velocity, new Vector(1,0));
    }

    //testing if the enemy updates its direction accordingly
    void EnemyUpdateDirection(void) {
      Vector v1 = new Vector(50, 50);
      Vector v2 = new Vector(100, 100);
      Platform platform = new Platform(v1,v2);
      Vector spawn = new Vector(65, 60);
      Enemy e1 = new Enemy(platform, spawn, true);
      TS_ASSERT(e1.updateDirection());
    }

    //testing if the enemy collides with anything
    void EnemeyCollide(void) {
      Vector v1 = new Vector(50, 50);
      Vector v2 = new Vector(100, 100);
      Vector collide = new Vector(65, 60);
      Enemy e1 = new Enemy(v1, v2);
      TS_ASSERT_EQUALS(e1.collides(collide), false);
    }

    //testing if the enemy is facing RIGHT
    void EnemyFacingRight(void) {
      Vector v1 = new Vector(50, 50);
      Vector v2 = new Vector(100, 100);
      Platform platform = new Platform(v1,v2);
      Vector spawn = new Vector(65, 60);
      Enemy e1 = new Enemy(platform, spawn, true);
      Enemy e2 = new Enemy(platform, spawn, false);
      TS_ASSERT(e1.facingRight());
      TS_ASSERT_EQUALS(e1.facingRight(), false);
    }

    //testing if getPosition() grabs the enemy's position
    void EnemyGetPosition(void) {
      Vector v1 = new Vector(50, 50);
      Vector v2 = new Vector(100, 100);
      Platform platform = new Platform(v1,v2);
      Vector spawn = new Vector(65, 60);
      Enemy e1 = new Enemy(platform, spawn, true);
      TS_ASSERT_EQUALS(e1.getPosition(), spawn);
    }
};
