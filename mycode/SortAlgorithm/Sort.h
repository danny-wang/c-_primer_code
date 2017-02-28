#pragma once
#include <vector>
using namespace std;
/**
template<typename T>
void swap(T a, T b){//大部分排序都用的到，单独封装出来
	T temp=a;
	a=b;
	b=temp;
}
**/
/**
插入排序：每次将一个待排序的关键字，按照其关键字的大小插入到已经排好的部分的适当位置上，直到插入完成
基本思想：当插入第i(i≥1)个对象时,前面的V[0],V[1],…,V[i−1]已经排好序。这时,用V[i]的排序码与V[i−1],V[i−2],…,V[0]的排序码顺序进行比较,找到插入位置即将V[i]插入,原来位置上的对象向后顺移。
**/
template<typename T>
void insertion_sort(vector<T>& a){
	for(int i=1; i<a.size(); i++){
		T value=a[i];
		int j=i;
		while(j>0 && value<a[j-1]){
			a[j]=a[j-1];
			j--;
		}
		a[j]=value;
	}
}
/**
算法性能：在内层循环中this[j]=this[j-1]，这句是作为基本操作。考虑最坏情况，即整个序列是逆序的，则其基本操作总的执行次数为n*(n-1)/2，
其时间复杂度为O(n*n)。考虑最好情况，即整个序列已经有序，则循环内的操作均为常量级，其时间复杂度为O(n)。
因此本算法平均时间复杂度为O(n*n)。算法所需的额外空间只有一个value，因此空间复杂度为O(1)。
**/

/**
希尔排序:
先将整个待排元素序列分割成若干个子序列（由相隔某个“增量”的元素组成的）分别进行直接插入排序，然后依次缩减增量再进行排序，
待整个序列中的元素基本有序（增量足够小）时，再对全体元素进行一次直接插入排序。因为直接插入排序在元素基本有序的情况下（接近最好情况），效率是很高的，
因此希尔排序在时间效率上比前两种方法有较大提高。
**/
template<typename T>
void shell_sort(vector<T>& a){
	for(int step=a.size()>>1; step>0; step>>=1){
		for(int i=0; i<step; i++){
			for(int j=i+step; j<a.size(); j+=step ){
				T value=a[j];
				int k=j;
				while(k>=step && value<a[k-step]){
					a[k]=a[k-step];
					k-=step;
				}
				a[k]=value;
			}
		}
	}
}
/**
算法性能：希尔排序的时间复杂度平均情况为O(nlogn)，空间复杂度为O(1)。
希尔排序的增量取法要注意，首先增量序列的最后一个值一定是1，其次增量序列中的值没有除1之外的公因子，如8，4，2，1这样的序列就不要取（有公因子2）
**/

/**
冒泡排序

算法思想：通过一系列的“交换”动作完成的，首先第一个记录与第二个记录比较，如果第一个大，则二者交换，否则不交换；
然后第二个记录和第三个记录比较，如果第二个大，则二者交换，否则不交换，以此类推，最终最大的那个记录被交换到了最后，
一趟冒泡排序完成。在这个过程中，大的记录就像一块石头一样沉底，小的记录逐渐向上浮动。冒泡排序算法结束的条件是一趟排序没有发生元素交换。
**/
template<typename T>
void bubble_sort(vector<T>& a){
	for(int i=a.size()-1;i>0;i--){
		for(int j=0;j<i;j++){
			if(a[j]>a[j+1])
				swap(a[j],a[j+1]);
		}
	}
}
/**
算法性能：最内层循环的元素交换操作是算法的基本操作。
最坏情况，待排序列逆序，则基本操作的总执行次数为(n-1+1)*(n-1)/2=n(n-1)/2，其时间复杂度为O(n*n)；
最好情况，待排序列有序，则时间复杂度为O(n)，因此平均情况下的时间复杂度为O(n*n)。算法的额外辅助空间只有一个用于交换的temp，所以空间复杂度为O(1)。
**/

/**
快速排序

算法思想：以军训排队为例，教官说以第一个同学为中心，比他矮的站他左边，比他高的站他右边，这就是一趟快速排序。
因此，一趟快速排序是以一个枢轴，将序列分成两部分，枢轴的一边比它小（或小于等于），另一边比它大（或大于等于）。
**/
template<typename T>
void quick_sort(vector<T>& a,int left, int right){ //default left=0, right=a.size()-1
	if(left>right)
		return;
	T temp=a[left]; //base number
	int i=left;
	int j=right;
	while(i!=j){
		//start from right side
		while(a[j]>=temp && i<j)
			j--;
		while(a[i]<=temp && i<j)
			i++;
		if(i<j){
			swap(a[i],a[j]);
		}
	}
	a[left]=a[i];
	a[i]=temp;
	quick_sort(a, left, i-1);
	quick_sort(a, i+1, right);
}
/**
算法性能：快速排序最好情况下时间复杂度为O(nlogn)，待排序列越接近无序，则该算法效率越高，在最坏情况下时间复杂度为O(n*n)，
待排序列越接近有序，则该算法效率越低，算法的平均时间复杂度为O(nlogn)。
就平均时间而言，快速排序是所有排序算法中最好的。该算法的空间复杂度为O(logn)，快速排序是递归进行的，需要栈的辅助，因此需要的辅助空间比前面几类排序方法要多。
**/

/**
选择排序

算法思想：该算法的主要动作就是“选择”，采用简单的选择方式，从头至尾顺序扫描序列，找出最小的一个记录，和第一个记录交换，
接着从剩下的记录中继续这种选择和交换，最终使序列有序。
**/
template<typename T>
void select_sort(vector<T>& a){
	for(int i=0;i<a.size();i++){
		int index=i;
		for(int j=i+1; j<a.size();j++){
			if(a[j]<a[index])
				index=j;
		}
		swap(a[i],a[index]);
	}
}
/**
算法性能：将最内层循环中的比较视为基本操作，其执行次数为(n-1+1)*(n-1)/2=n(n-1)/2，其时间复杂度为O(n*n)，本算法的额外空间只有一个temp，因此空间复杂度为O(1)。
**/