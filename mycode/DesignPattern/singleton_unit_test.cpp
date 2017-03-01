#include "Singleton.h"
#include "gtest/gtest.h"
#include <iostream>
using namespace std;

TEST(Singleton, Message) {
  singleton* s = singleton::instance();
  cout<<s<<endl;
}