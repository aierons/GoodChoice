#include <cxxtest/TestSuite.h>
#include <iostream>
#include "Bullet.hpp"

class BulletTestSuite:public CxxTest::TestSuite
{
  //testing if the bullet is alive when it's initially created
  void testIsAlive(void) {
    Vector v1 = new Vector(50, 50);
    Vector v2 = new Vector(100, 100);
    Bullet bullet = new Bullet(v1, v2);
    TS_ASSERT(bullet.isAlive());
  }

  //testing if updatePosition updates the bullet's position properly and if the bullet is still alive
  void testUpdatePosition(void) {
    Vector v1 = new Vector(50, 50);
    Vector v2 = new Vector(100, 100);
    Bullet bullet = new Bullet(v1, v2);
    bullet.updatePosition();
    TS_ASSERT_EQUALS(bullet.getPosition(), new Vector(150, 150));
    TS_ASSERT(bullet.isAlive());
  }
}
