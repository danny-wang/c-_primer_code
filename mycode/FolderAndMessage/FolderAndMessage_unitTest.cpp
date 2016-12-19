#include "FolderAndMessage.h"
#include "gtest/gtest.h"
#include <iostream>
using namespace std;

TEST(MessagesTest, Message) {
  Message m_a{"wangjian"};
  Folder f_a,f_b,f_c;
  m_a.save(f_a);
  m_a.save(f_b);
  Message m_b("danny");
  m_b.save(f_a);
  Message m_c(m_a);
  cout<<f_a;
  EXPECT_EQ(3, f_a.size());
  EXPECT_EQ(2, f_b.size());
  m_a.remove(f_a);
  cout<<f_a;
  EXPECT_EQ(2, f_b.size());
  EXPECT_EQ(2, f_a.size());
  cout<<f_b;
}

TEST(FolderTest, Folder) {
  Message m_a{"wangjian"};
  Message m_b{"danny"};
  Message m_c{"BOB"};
  Folder f_a,f_b,f_c;
  m_a.save(f_a);
  m_a.save(f_b);
  m_a.save(f_c);
  m_b.save(f_a);
  m_c.save(f_a);
  EXPECT_EQ(3, f_a.size());
  EXPECT_EQ(1, f_b.size());
  EXPECT_EQ(1, f_c.size());
  EXPECT_EQ(3, m_a.get_reference_num());
  f_b=f_a;
  EXPECT_EQ(3, m_a.get_reference_num());
  EXPECT_EQ(2, m_b.get_reference_num());
  cout<<f_b;
  Folder f_d(f_a);
  EXPECT_EQ(3, f_d.size());
  EXPECT_EQ(4, m_a.get_reference_num());
  EXPECT_EQ(3, m_b.get_reference_num());
}
