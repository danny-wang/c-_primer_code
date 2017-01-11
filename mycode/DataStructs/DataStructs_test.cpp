
#include "BinarySearchTree.h"
#include "gtest/gtest.h"
#include <string>
#include <iostream>
using namespace std;


TEST(BinarySearchTree_test, Normal) {
    BST<int> bst;
    bst.insert(1);
    bst.insert(2);
    bst.insert(5);
    bst.insert(8);
    EXPECT_EQ((bst.find(8))->data, 8);
    EXPECT_EQ(bst.size(),4);
    bst.traversal();
    cout<<endl;
    bst.Delete(1);
    EXPECT_EQ(bst.size(),3);
    bst.insert(8);
    EXPECT_EQ(bst.size(),4);
    EXPECT_EQ((bst.find(8))->freq, 2);
    bst.traversal();

}