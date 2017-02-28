#include <iostream>
#include "Sort.h"
#include "gtest/gtest.h"
using namespace std;

TEST(Sort, InsertionSort) {
	vector<int> a={9,7,5,8,100,2,6,8,4};
	insertion_sort(a);
	EXPECT_EQ(2,a[0]);
	EXPECT_EQ(4,a[1]);
	EXPECT_EQ(5,a[2]);
	EXPECT_EQ(6,a[3]);
	EXPECT_EQ(7,a[4]);
	for(auto i : a){
		cout<<i<<" ";
	}
	cout<<endl;
}
TEST(Sort, ShellSort) {
	vector<int> a={9,7,5,8,100,2,6,8,4};
	shell_sort(a);
	EXPECT_EQ(2,a[0]);
	EXPECT_EQ(4,a[1]);
	EXPECT_EQ(5,a[2]);
	EXPECT_EQ(6,a[3]);
	EXPECT_EQ(7,a[4]);
	for(auto i : a){
		cout<<i<<" ";
	}
	cout<<endl;
}
TEST(Sort, BubbleSort) {
	vector<int> a={9,7,5,8,100,2,6,8,4};
	bubble_sort(a);
	EXPECT_EQ(2,a[0]);
	EXPECT_EQ(4,a[1]);
	EXPECT_EQ(5,a[2]);
	EXPECT_EQ(6,a[3]);
	EXPECT_EQ(7,a[4]);
	for(auto i : a){
		cout<<i<<" ";
	}
	cout<<endl;
}
TEST(Sort, QuickSort) {
	vector<int> a={9,7,5,8,100,2,6,8,4};
	quick_sort(a,0,a.size()-1);
	EXPECT_EQ(2,a[0]);
	EXPECT_EQ(4,a[1]);
	EXPECT_EQ(5,a[2]);
	EXPECT_EQ(6,a[3]);
	EXPECT_EQ(7,a[4]);
	for(auto i : a){
		cout<<i<<" ";
	}
	cout<<endl;
}
TEST(Sort, SelectSort) {
	vector<int> a={9,7,5,8,100,2,6,8,4};
	select_sort(a);
	EXPECT_EQ(2,a[0]);
	EXPECT_EQ(4,a[1]);
	EXPECT_EQ(5,a[2]);
	EXPECT_EQ(6,a[3]);
	EXPECT_EQ(7,a[4]);
	for(auto i : a){
		cout<<i<<" ";
	}
	cout<<endl;
}
TEST(Sort, MergeSort) {
	int a[]={9,7,5,8,100,2,6,8,4};
	merge_sort(a,0,sizeof(a)/sizeof(int));
	EXPECT_EQ(2,a[0]);
	EXPECT_EQ(4,a[1]);
	EXPECT_EQ(5,a[2]);
	EXPECT_EQ(6,a[3]);
	EXPECT_EQ(7,a[4]);
	for(auto i : a){
		cout<<i<<" ";
	}
	cout<<endl;
}
