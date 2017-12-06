#include "Vector.hpp"
#include <iostream>
#include <cxxtest/TestSuite.h>

class VectorTest : public CxxTest::TestSuite {
  public:
    //testing if the default constructor works appropriately
    static void testDefaultConstructor(void) {
      Vector *v1 = new Vector();
      TS_ASSERT_EQUALS(v1->getX(), 0);
      TS_ASSERT_EQUALS(v1->getY(), 0);
    }

    //testing if the Vector constructs correctly
	static void testVectorConstructor(void) {
      Vector *v1 = new Vector(2, 4);
      TS_ASSERT_EQUALS(v1->getX(), 2);
      TS_ASSERT_EQUALS(v1->getY(), 4);
      Vector *v2 = new Vector(*v1);
      TS_ASSERT_EQUALS(v2->getX(), 2);
      TS_ASSERT_EQUALS(v2->getY(), 4);
    }

    //testing if the set methods work accordingly
	static void testSetMethods(void) {
      Vector *v1 = new Vector();
      v1->setX(2);
      v1->setY(4);
      TS_ASSERT_EQUALS(v1->getX(), 2);
      TS_ASSERT_EQUALS(v1->getY(), 4);
    }

    //testing if the getters work accordingly
	static void testGetterMethods(void) {
      Vector *v1 = new Vector(2, 4);
      TS_ASSERT_EQUALS(v1->getX(), 2);
      TS_ASSERT_EQUALS(v1->getY(), 4);
    }

    //testing the operator[]
	static void testOperatorIndex(void) {
      Vector *v1 = new Vector(2, 4);
      TS_ASSERT_EQUALS(v1[0], 2);
      TS_ASSERT_EQUALS(v1[1], 4);
    }

    //testing the operator=
	static void testOperatorAssignment(void) {
      Vector *v1 = new Vector(2, 4);
      Vector *v2 = new Vector(3, 5);
      v1 = v2;
      TS_ASSERT_EQUALS(v1->getX(), 3);
      TS_ASSERT_EQUALS(v1->getY(), 5);
    }

    //testing the operator==
	static void testOperatorEquals(void) {
      Vector *v1 = new Vector(2, 4);
      Vector *v2 = new Vector(2, 4);
      Vector *v3 = new Vector(3, 4);
      TS_ASSERT(*v1==*v2);
      TS_ASSERT_EQUALS(*v1==*v3, false);
    }

    //testing the operator!=
	static void testOperatorNotEquals(void) {
      Vector *v1 = new Vector(2, 4);
      Vector *v2 = new Vector(2, 4);
      Vector *v3 = new Vector(3, 4);
      TS_ASSERT(*v1!=*v2);
      TS_ASSERT_EQUALS(*v1==*v3, false);
    }

    //testing the operator-
	static void testOperatorNegative(void) {
      Vector *v1 = new Vector(2, 4);
      Vector *v2 = new Vector(-(*v1));
      TS_ASSERT_EQUALS(v2->getX(), -2);
      TS_ASSERT_EQUALS(v2->getY(), -4);
    }

    //testing the operator-=
	static void testOperatorMinusEqual(void) {
      Vector *v1 = new Vector(2, 4);
      Vector *v2 = new Vector(1, 3);
      *v1 -= *v2;
      TS_ASSERT_EQUALS(v1->getX(), 1);
      TS_ASSERT_EQUALS(v1->getX(), 1);
    }

    //testing the operator*
	static void testOperatorMultiplyDouble(void) {
      Vector *v1 = new Vector(2,4);
      *v1 *= 3;
      TS_ASSERT_EQUALS(v1->getX(), 6);
      TS_ASSERT_EQUALS(v1->getY(), 12);
    }

};
