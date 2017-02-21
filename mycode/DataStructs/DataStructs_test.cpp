#include "AVL_Tree.h"
#include "BinarySearchTree.h"
#include "SmallHeap.h"
#include "BinaryTree.h"
#include "gtest/gtest.h"
#include <string>
#include <iostream>
using namespace std;

TEST(AVL_test, Normal) {
    using namespace avl;
    AVLTree<int> tree;
    tree.insert(3);
    tree.insert(2);
    tree.insert(1);
    tree.traversal();
    cout<<endl;
    tree.insert(4);
    tree.insert(5);
    tree.insert(6);
    tree.insert(7);
    tree.insert(16);
    tree.insert(15);
    tree.insert(14);
    tree.insert(13);
    tree.insert(12);
    tree.insert(11);
    tree.insert(10);
    tree.insert(8);
    tree.insert(9);
    tree.traversal();





}


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


TEST(SmallHeap_Test, Normal) {

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
        // for (int i = 0;i < jb.size();i++) {
        //     printf("%d\n",p[i]);
        // }
        jb.HeapSort();
        printf("HeapSort\n");
        p=jb.getMinHeap();
        // for (int i = 0;i < jb.size();i++) {
        //     printf("%d\n",p[i]);
        // }
        EXPECT_EQ(8, jb.size());
        jb.add(3);
        // for (int i = 0;i < jb.size();i++) {
        //     printf("%d\n",p[i]);
        // }
        jb.add(-10);
        // for (int i = 0;i < jb.size();i++) {
        //     printf("%d\n",p[i]);
        // }
}

TEST(Bianry_tree_test,function){
    using namespace bt;
    BiTree T;
	CreateBiTree(T);
	printf("先序遍历：\n");
	PreOrder(T);
	printf("\n");
	printf("先序遍历(非递归)：\n");
	PreOrder2(T);
	printf("\n");
	printf("中序遍历：\n");
	InOrder(T);
	printf("\n");
	printf("中序遍历(非递归)：\n");
	InOrder2(T);
	printf("\n");
	printf("后序遍历：\n");
	PostOrder(T);
	printf("\n");
	printf("后序遍历(非递归)：\n");
	PostOrder2(T);
	printf("\n");
	printf("层次遍历：\n");
	LevelOrder(T);
	printf("\n");
}
