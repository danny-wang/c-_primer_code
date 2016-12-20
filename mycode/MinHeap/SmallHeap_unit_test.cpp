
#include "SmallHeap.h"
#include "gtest/gtest.h"
using namespace std;

TEST(SmallHeapTest, Negative) {
 
        MinHeap<int> jb(10);
        
        jb.add(20);
        jb.add(18);
        jb.add(19);
        jb.add(13);
        jb.add(42);
        jb.add(5);
        jb.add(100);
        jb.add(1);
        jb.createMinHeap();
        int *p=jb.getMinHeap();
        printf("整理为最小堆：\n");
        for (int i = 0;i < jb.size();i++) {
            printf("%d\n",p[i]);
        }
        jb.HeapSort();
        printf("HeapSort\n");
        p=jb.getMinHeap();
        for (int i = 0;i < jb.size();i++) {
            printf("%d\n",p[i]);
        }


        EXPECT_EQ(8, jb.size());
  
}

