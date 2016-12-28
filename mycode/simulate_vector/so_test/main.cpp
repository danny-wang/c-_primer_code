#include "Blob.h"
#include <iostream>
using namespace std;

int main() {
  Blob<int> squares={0,1,2,3,4,5,6,7,8};
  cout<<squares.size()<<endl;
  cout<<squares[0]<<endl;
  return 0;
}