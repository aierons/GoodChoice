#include <cxxtest/TestSuite.h>
#include <iostream>

class PlatformTest : public CxxTest::TestSuite
{
public:
  //testing if the constructor works accordingly
  void testPlatformConstructor(void) {
    //tests the default constructor
    Platform p1 = new Platform();
    TS_ASSERT_EQUALS(p1.getStartX(), 50);
    TS_ASSERT_EQUALS(p1.getStartY(), 20);
    TS_ASSERT_EQUALS(p1.getEndX(), 550);
    TS_ASSERT_EQUALS(p1.getEndY(), 90);
    TS_ASSERT(p1.isVisible());
    //tests the constructor with 2 arguments
    Platform p1 = new Platform(new Vector(50, 40), new Vector(60, 40));
    TS_ASSERT_EQUALS(p1.getStartX(), 50);
    TS_ASSERT_EQUALS(p1.getStartY(), 40);
    TS_ASSERT_EQUALS(p1.getEndX(), 60);
    TS_ASSERT_EQUALS(p1.getEndY(), 40);
    TS_ASSERT(p1.isVisible());
    //tests the constructor with 3 arguments
    Platform p1 = new Platform(new Vector(50, 40), new Vector(60, 40), false);
    TS_ASSERT_EQUALS(p1.getStartX(), 50);
    TS_ASSERT_EQUALS(p1.getStartY(), 40);
    TS_ASSERT_EQUALS(p1.getEndX(), 60);
    TS_ASSERT_EQUALS(p1.getEndY(), 40);
    TS_ASSERT_EQUALS(p1.isVisible(), false);
  }

  //testing if the platform collides with anything
  void testPlatformCollides(void) {
      Platform p1 = new Platform(new Vector(50, 40), new Vector(60, 40), false);
      Vector *v1 = new Vector(50, 40);
      TS_ASSERT(p1.collides(v1));
  }

  //testing the getter methods
  void testPlatformGetters(void) {
    Platform p1 = new Platform(new Vector(50, 40), new Vector(60, 40), false);
    TS_ASSERT_EQUALS(p1.getStartX(), 50);
    TS_ASSERT_EQUALS(p1.getStartY(), 40);
    TS_ASSERT_EQUALS(p1.getEndX(), 60);
    TS_ASSERT_EQUALS(p1.getEndY(), 40);
    TS_ASSERT_EQUALS(p1.isVisible(), false);
  }

 //testing the show method
 void testPlatformShow(void) {
   Platform p1 = new Platform(new Vector(50, 40), new Vector(60, 40), false);
   p1.show();
   TS_ASSERT(p1.isVisible());
 }
};
