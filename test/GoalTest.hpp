#include <cxxtest/TestSuite.h>
#include <iostream>
#include "Goal.h"
#include "Vector.hpp"

class GoalTest : public CxxTest::TestSuite
{
public:
  //testing if the goal constructs and collides accordingly
  void testGoalCollidesr(void) {
    Vector *v1 = new Vector(40, 54);
    Goal g1 = new Goal(v1);
    Vector *v2 = new Vector(30, 40);
    TS_ASSERT(g1.collides(v2));
  }
};
