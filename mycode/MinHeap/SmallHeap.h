#pragma once
#include <iostream>
template<class T>
class MinHeap
{
private:
    //申请堆空间
    T *_minHeap = nullptr;
    int _index,_maxSize;
public:
    MinHeap(int maxSize) {
        _maxSize = maxSize;
        _minHeap = new T[_maxSize];
        _index = -1;
    }
    MinHeap(MinHeap &h) {
        _index = h._index;
        _maxSize = h._maxSize;
        _minHeap = new T[_maxSize];
        for (int i = 0;i<_maxSize; i++) {
            *_minHeap[i] = *h._minHeap[i];
        }
    }
    ~MinHeap() {
        delete[] _minHeap;
    }
    //获取整个最小堆的头部指针
    T * getMinHeap() {
        return _minHeap;
    }
    //判断堆是不是空的
    bool isEmpty() {
        return _index == -1;
    }
    int size(){
        return _index+1;
    }
    bool add(T x) {
        if (isFull()) {
            return false;
        }
        _index++;
        _minHeap[_index] = x;
        return true;
    }
    void deleteMin(){
        if(_index==-1){
            std::cout<<"current MinHeap is empty"<<std::endl;
            return;
        }
        _minHeap[0]=_minHeap[_index];
        _index--;
        adjustDown(0);
    }

    bool isFull() {
        return _index == _maxSize;
    }
    //堆进行向下调整
    void adjustDown(int index);
    //队进行向上调整
    void adjustUp(int index);
    //建堆运算
    void createMinHeap(){
        if (isEmpty()) {
            return;
        }
        for (int i = (_index-1)/2;i >-1;i--) {//直接从倒数第二层 逐层向下调整
           adjustDown(i);
        }
    }
    void HeapSort(){
        createMinHeap();
        T *sort_heap = new T[_index];
        int index= _index;
        for(int i= _index, j=0; i!=-1; i--,j++){
            sort_heap[j]=_minHeap[0];
            deleteMin();
        }
        delete[] _minHeap;
        _minHeap=sort_heap;
        _index=index;
    }

};



template<class T>
void MinHeap<T>::adjustDown(int index) {
    if (isEmpty()) {
        return;
    }
    while (index<_index)
    {
        T temp = _minHeap[index];//将当前索引的位置的值保存下来
        int oneC = 2 * index + 1;//获取到两个孩子的位置
        int twoC = 2 * index + 2;
        if (oneC == _index) {//若第一个孩子是整个堆最后一个位置 执行交换操作并结束执行
            if(temp > _minHeap[oneC]){
                _minHeap[index] = _minHeap[oneC];
                _minHeap[oneC] = temp;
                return;
            }
                
        }
        if (twoC >_index) {//如果第二个孩子的索引位置越界 结束执行
            return;
        }
        if (_minHeap[oneC] <= _minHeap[twoC]) {//正常情况的数据交互执行
            if (temp > _minHeap[oneC]) {
                _minHeap[index] = _minHeap[oneC];
                _minHeap[oneC] = temp;
                index = oneC;
            }
            else {//如果该处索引值已经是比两个孩子小 则结束循环
                index = _index;
            }
        }
        else 
        {
            if (temp > _minHeap[twoC]) {
                _minHeap[index] = _minHeap[twoC];
                _minHeap[twoC] = temp;
                index = twoC;
            }
            else 
            {
                index = _index;
            }
        }
    }
}
template<class T>
void MinHeap<T>::adjustUp(int index) {
    if (index > _index) {//大于堆的最大值直接return
        return;
    }
    while (index>-1)
    {
        T temp = _minHeap[index];
        int father = (index - 1) / 2;
        if (father >= 0) {//若果索引没有出界就执行想要的操作
            if (temp < _minHeap[father]) {
                _minHeap[index] = _minHeap[father];
                _minHeap[father] = temp;
                index=father;
            }
            else {//若果已经是比父亲大 则直接结束循环
                index = -1;
            }
        }
        else//出界就结束循环
        {
            index = -1;
        }
    }
}

