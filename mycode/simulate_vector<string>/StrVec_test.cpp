
#include "StrVec.h"
#include "gtest/gtest.h"
using namespace std;

TEST(StrVecTest, Negative) {
  StrVec str_vec;
  string str("123");
  str_vec.push_back("asdfasdfasdf");
  str_vec.push_back(str);
  str_vec.push_back(str);
  EXPECT_EQ(3, str_vec.size());


}