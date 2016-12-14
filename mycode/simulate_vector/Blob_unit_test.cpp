
#include "Blob.h"
#include "gtest/gtest.h"
using namespace std;

TEST(BlobTest, Negative) {
  Blob<int> squares={0,1,2,3,4,5,6,7,8};
  EXPECT_EQ(9, squares.size());
  EXPECT_EQ(0, squares[0]);
  EXPECT_EQ(5, squares[5]);
  Blob<string> squares2;
  EXPECT_TRUE(squares2.empty());
  squares2.push_back("sssss");
  squares2.push_back("ddffdsf");
  EXPECT_EQ(2, squares2.size());
  EXPECT_STREQ("sssss", squares2[0].c_str());
  squares2.pop_back();
  EXPECT_EQ(1, squares2.size());
  EXPECT_STREQ("sssss", squares2.front().c_str());
  EXPECT_STREQ("sssss", squares2.back().c_str());

  const Blob<int> squares3={0,1,2,3,4,5,6,7,8};
  EXPECT_EQ(1, squares3[1]);
}