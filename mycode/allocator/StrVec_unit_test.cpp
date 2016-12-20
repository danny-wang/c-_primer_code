
#include "StrVec.h"
#include "gtest/gtest.h"
using namespace std;

TEST(StrVecTest, Negative) {
  StrVec a;
  a.push_back("danny");
  a.push_back("wangjian");
  a.push_back("bob");
  EXPECT_EQ(3, a.size());
  EXPECT_STREQ("danny", a[0].c_str());
  EXPECT_STREQ("wangjian", a[1].c_str());
  EXPECT_STREQ("bob", a[2].c_str());
  StrVec b(a);
  EXPECT_EQ(3, b.size());
  EXPECT_STREQ("danny", b[0].c_str());
  EXPECT_STREQ("wangjian", b[1].c_str());
  EXPECT_STREQ("bob", b[2].c_str());
  StrVec c(std::move(a));
  EXPECT_EQ(3, c.size());
  EXPECT_STREQ("danny", c[0].c_str());
  EXPECT_STREQ("wangjian", c[1].c_str());
  EXPECT_STREQ("bob", c[2].c_str());
  EXPECT_EQ(0, a.size());
}