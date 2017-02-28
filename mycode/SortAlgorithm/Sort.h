#pragma once
#include <vector>
#include <limits.h>
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

/**
堆排序

算法思想：堆是一种数据结构，最好的理解堆的方式就是把堆看成一棵完全二叉树，
这个完全二叉树满足任何一个非叶节点的值，都不大于（或不小于）其左右孩子节点的值。
若父亲大孩子小，则这样的堆叫做大顶堆；若父亲小孩子大，这样的堆叫做小顶堆。
根据堆的定义，其根节点的值是最大（或最小），因此将一个无序序列调整为一个堆，就可以找出这个序列的最大（或最小）值，
然后将找出的这个值交换到序列的最后（或最前），这样有序序列元素增加1个，无序序列中元素减少1个，对新的无序序列重复这样的操作，
就实现了序列排序。堆排序中最关键的操作是将序列调整为堆，
整个排序的过程就是通过不断调整使得不符合堆定义的完全二叉树变为符合堆定义的完全二叉树的过程。

堆排序执行过程（大顶堆）：

（1）从无序序列所确定的完全二叉树的第一个非叶子节点开始，从右至左，从下至上，对每个节点进行调整，最终将得到一个大顶堆。
将当前节点（a）的值与其孩子节点进行比较，如果存在大于a值的孩子节点，则从中选出最大的一个与a交换。
当a来到下一层的时候重复上述过程，直到a的孩子节点值都小于a的值为止。
（2）将当前无序序列中第一个元素，在树中是根节点（a）与无序序列中最后一个元素（b）交换。
a进入有序序列，到达最终位置，无序序列中元素减少1个，有序序列中元素增加1个，此时只有节点b可能不满足堆的定义，对其进行调整。

（3）重复过程2，直到无序序列中的元素剩下1个时排序结束。
you can find code in DataStructs/SmallHeap
**/
/**
算法性能：完全二叉树的高度为[log(n+1)]，即对每个节点调整的时间复杂度为O(logn)，
基本操作总次数是两个并列循环中基本操作次数相加，则整个算法时间复杂度为O(logn)*n/2+O(logn)*(n-1)，即O(nlogn)。
额外空间只有一个temp，因此空间复杂度为O(1)。
**/

/**
归并排序

算法思想：其核心就是“两两归并”，
首先将原始序列看成每个只含有单独1个元素的子序列，两两归并，形成若干有序二元组，则第一趟归并排序结束
，再将这个序列看成若干个二元组子序列，继续两两归并，形成若干有序四元组，则第二趟归并排序结束
以此类推，最后只有两个子序列，再进行一次归并，即完成整个归并排序。
**/
template<class T> 
void merge(T A[],int low,int mid,int high)
{
    //low to mid as the left array   mid+1 to high as the right array
    int llen = mid-low+2;
    int rlen = high-mid+1;
    T *left = (T*)new T[llen];
    T *right = (T*)new T[rlen];
    //copy the low to mid to the temp array left
    for (int i=0;i<llen-1;i++)
    {
        left[i] = A[low+i];
    }
    for (int i=0;i<rlen-1;i++)
    {
        right[i] = A[mid+1+i];
    }
    //set the sentinel
    left[llen-1] = INT_MAX;
    right[rlen-1]= INT_MAX;
    //merge the two array and copy to A[low,high];
    int j = 0;
    int k = 0;
    for (int i = low; i < high+1 ;i++)
    {
        if (left[j] < right[k])
        {
            A[i] = left[j];
            j++;
        }
        else
        {
            A[i] = right[k];
            k++;
        }
    }
   delete [] left;
   delete [] right;
}

template<class T> 
void merge_sort(T A[],int low,int high)
{
    int mid = (low+high)/2;
    if (low < high)
    {
        merge_sort(A,low,mid);
        merge_sort(A,mid+1,high);
        merge(A,low,mid,high);
    }
}

