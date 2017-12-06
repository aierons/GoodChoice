#include "BulletTest.hpp"
#include "EnemyTest.hpp"
#include "GoalTest.hpp"
#include "PlatformTest.hpp"
#include "VectorTest.hpp"
#include <iostream>
#include <cxxtest/TestSuite.h>
using namespace std;

int main(int argc, char * argv[]) {
  bool allPass = true;
    if (!BulletTest::testConstructor(void))  {
      allPass = false;
      cout << "testConstructor in BulletTest failed" << endl;
    }
    if (!BulletTest::testIsAlive(void))  {
      allPass = false;
      cout << "testIsAlive in BulletTest failed" << endl;
    }
    if (!BulletTest::testUpdatePosition(void))  {
      allPass = false;
      cout << "testUpdatePosition in BulletTest failed" << endl;
    }
    if (!EnemyTest::EnemyConstructor(void)) {
      allPass = false;
      cout << "EnemyConstructor in EnemyTest failed" << endl;
    }
    if (!EnemyTest::EnemySpawnConstructor(void)) {
      allPass = false;
      cout << "EnemySpawnConstructor in EnemyTest failed" << endl;
    }
    if (!EnemyTest::EnemyUpdateVelocity(void)) {
      allPass = false;
      cout << "EnemyUpdateVelocity in EnemyTest failed" << endl;
    }
    if (!EnemyTest::EnemyUpdateDirection(void)) {
      allPass = false;
      cout << "EnemyUpdateDirection in EnemyTest failed" << endl;
    }
    if (!EnemyTest::EnemeyCollide(void)) {
      allPass = false;
      cout << "EnemeyCollide in EnemyTest failed" << endl;
    }
    if (!EnemyTest::EnemyFacingRight(void)) {
      allPass = false;
      cout << "EnemyFacingRight in EnemyTest failed" << endl;
    }
    if (!EnemyTest::EnemyGetPosition(void)) {
      allPass = false;
      cout << "EnemyGetPosition in EnemyTest failed" << endl;
    }
    if (!GoalTest::testGoalCollides(void)) {
      allPass = false;
      cout << "testGoalCollides in GoalTest failed" << endl;
    }
    if (!PlatformTest::testPlatformConstructor(void)) {
      allPass = false;
      cout << "testPlatformConstructor in PlatformTest failed"  <<  endl;
    }
    if (!PlatformTest::testPlatformCollides(void)) {
      allPass = false;
      cout << "testPlatformCollides in PlatformTest failed"  <<  endl;
    }
    if (!PlatformTest::testPlatformGetters(void)) {
      allPass = false;
      cout << "testPlatformGetters in PlatformTest failed"  <<  endl;
    }
    if (!PlatformTest::testPlatformShow(void)) {
      allPass = false;
      cout << "testPlatformShow in PlatformTest failed"  <<  endl;
    }
    if(!VectorTest::testDefaultConstructor(void)) {
      allPass = false;
      cout << "testDefaultConstructor in VectorTest failed" << endl;
    }
    if (!VectorTest::testVectorConstructor(void)) {
      allPass = false;
      cout << "testVectorConstructor in VectorTest failed" << endl;
    }
    if (!VectorTest::testSetMethods(void)) {
      allPass = false;
      cout << "testSetMethods in VectorTest failed" << endl;
    }
    if (!VectorTest::testGetterMethods(void)) {
      allPass = false;
      cout << "testGetterMethods in VectorTest failed" << endl;
    }
    if (!VectorTest::testOperatorIndex(void)) {
      allPass = false;
      cout << "testOperatorIndex in VectorTest failed" << endl;
    }
    if (!VectorTest::testOperatorEquals(void)) {
      allPass = false;
      cout << "testOperatorEquals in VectorTest failed" << endl;
    }
    if (!VectorTest::testOperatorAssignment(void)) {
      allPass = false;
      cout << "testOperatorAssignment in VectorTest failed" << endl;
    }
    if (!VectorTest::testOperatorNotEquals(void)) {
      allPass = false;
      cout << "testOperatorNotEquals in VectorTest failed" << endl;
    }
    if (!VectorTest::testOperatorNegative(void)) {
      allPass = false;
      cout << "testOperatorNegative in VectorTest failed" << endl;
    }
    if (!VectorTest::testOperatorMinusEqual(void)) {
      allPass = false;
      cout << "testOperatorMinusEqual in VectorTest failed" << endl;
    }
    if (!VectorTest::testOperatorMultiplyDouble(void)) {
      allPass = false;
      cout << "testOperatorMultiplyDouble in VectorTest failed" << endl;
    }
    if (!VectorTest::testOperatorMultiplyEqual(void)) {
      allPass = false;
      cout << "testOperatorMultiplyEqual in VectorTest failed" << endl;
    }
    if (!VectorTest::testOperatorDivide(void)) {
      allPass = false;
      cout << "testOperatorDivide in VectorTest failed" << endl;
    }
    if (!VectorTest::testOperatorDivideEqual(void)) {
      allPass = false;
      cout << "testOperatorDivideEqual in VectorTest failed" << endl;
    }
    if (allPass) {
      cout << "All tests passed!" << endl;
    }
  }
}
