#include "strategy.h"
#include <iostream>
#include "gtest/gtest.h"
using namespace std;

TEST(StrategyTest, normal) {
  GameCharacter gc;
  EXPECT_EQ(gc.healthValue(), 1);
  EvilBadGuy ebg(new SlowHealthLoser());
  EXPECT_EQ(ebg.healthValue(), 2);
  EvilBadGuy ebg2(new FastHealthLoser());
  EXPECT_EQ(ebg2.healthValue(), 3);
  EyeCandyCharacter ecc(new FastHealthLoser());
  EXPECT_EQ(ecc.healthValue(), 3);
}