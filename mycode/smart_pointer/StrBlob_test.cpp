
#include "StrBlobPtr.h"
#include "gtest/gtest.h"


using namespace std;

TEST(StrBlobTest, Negative) {
  StrBlob al={"hi","bye","now"};
  StrBlobPtr p(al);
  *p="okay";
  EXPECT_EQ(4, p->size());
  EXPECT_EQ(4,(*p).size());


}
