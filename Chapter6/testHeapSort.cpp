//
// Created by liu on 2020/3/2.
//
#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;

template<typename T>
void Swap(T &a,T &b);

template<typename T>
class Heap{
public:
    //堆的构造函数
    Heap(const T a[],T heap_size,T heap_length)
    :HeapSize(heap_size),HeapLength(heap_length),ShowSize(heap_size){
        A = new T[heap_length];
        for(auto i = 0;i < heap_length;i++){
            if(i < heap_size) {
                A[i] = a[i];
            }else{
                //此处存在问题 为了防止内存泄露设置了初始值
                //但是这样导致只能排序全为正数的数组  建议改成-inf
                //补充 应该区分最大最小堆设置变量
                A[i] = 0;
            }
        }
    }

    //以下三个函数传入的值都为元素在数组的序号 从1开始
    //返回父亲节点
    static inline int Parent(int i){
        return floor(i/2);
    }
    //返回左孩子
    static inline int Left(T i){
        return 2*i;
    }
    //返回右孩子
    static inline int Right(int i){
        return 2*i+1;
    }

    //使位置i的元素满足最大堆的性质
    void MaxHeapify(int i);

    //使位置i的元素满足最小堆的性质
    void MinHeapify(int i);

    //建立最大堆
    void BuildMaxHeap();

    //建立最小堆
    void BuildMinHeap();

    //堆排序
    void HeapSort();

    void Show();

    //接下来是模拟最大优先队列
    //返回优先队列中的最大值
    T inline HeapMaximum(){
        return A[0];
    }

    T HeapExtractMax();

    void HeapIncreaseKey(int i,T key);

    void MaxHeapInsert(T key);


private:
    int HeapSize;
    int HeapLength;
    int ShowSize;
    T *A;
};

//此处i为序号
template<typename T>
void Heap<T>::MaxHeapify(int i) {
    int l = Left(i);
    int r = Right(i);
    int largest{};

    if(l <= HeapSize && A[l-1] > A[i-1]){
        largest = l;
    }else{
        largest = i;
    }
    if(r <= HeapSize && A[r-1] > A[largest-1]){
        largest = r;
    }

    if(largest != i){
        Swap(A[i-1],A[largest-1]);
        MaxHeapify(largest);
    }

}

template<typename T>
void Heap<T>::BuildMaxHeap() {
    //HeapSize = HeapLength;
    for(auto i = int(floor(HeapLength/2));i >= 1; i--){
        //此处i为序号
        MaxHeapify(i);
        //Show();
    }
}

template<typename T>
void Heap<T>::HeapSort() {
    //第一步构建最大堆
    BuildMaxHeap();
    //现在利用最大堆的性质--元素的最大值在第1位置 取出此元素 将剩下的元素的最大值通过MaxHeapify取出到1号位置
    for(auto i = HeapSize; i >= 2; i--){
        Swap(A[0],A[i-1]);
        HeapSize--;
        MaxHeapify(1);
    }
}

template<typename T>
void Heap<T>::Show() {
    for(auto i = 0;i < ShowSize;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

template<typename T>
T Heap<T>::HeapExtractMax() {
    if (HeapSize < 1){
        cerr<<"heap underflow"<<endl;
    }
    T max = A[0];
    A[0] = A[HeapSize-1];
    HeapSize--;
    //重置A[0]为剩下元素的最大值
    MaxHeapify(1);
    return max;
}

template<typename T>
void Heap<T>::HeapIncreaseKey(int i,T key) {
    if(key<A[i-1]){
        cerr<<"new key is smaller than current key!"<<endl;
        return;
    }
    A[i-1] = key;
    while( (i > 1) && (A[Parent(i)-1] < A[i-1]) ){
        Swap(A[i-1],A[Parent(i)-1]);
        i = Parent(i);
    }
}

template<typename T>
void Heap<T>::MaxHeapInsert(T key) {
    HeapSize++;
    if(HeapSize >= HeapLength){
        //扩容操作 可优化 比如初始分配更大的内存空间
        T *temp = new T[2*HeapLength];
        memcpy(temp,A,HeapLength);
        delete [] A;
        A = temp;
    }

    A[HeapSize] = -99999;
    HeapIncreaseKey(HeapSize,key);
}

template<typename T>
void Heap<T>::MinHeapify(int i) {
    int l = Left(i);
    int r = Right(i);
    int smallest{};

    if(l <= HeapSize && A[l-1] < A[i-1]){
        smallest = l;
    }else{
        smallest = i;
    }
    if(r <= HeapSize && A[r-1] < A[smallest-1]){
        smallest = r;
    }

    if(smallest != i){
        Swap(A[i-1],A[smallest-1]);
        MinHeapify(smallest);
    }

}

template<typename T>
void Heap<T>::BuildMinHeap() {
    for(auto i = int(floor(HeapLength/2));i >= 1; i--){
        //此处i为序号
        MinHeapify(i);
    }
}


int main(){
    int a[] = {5,-13,2,-25,7,17,20,8,0,4};
    Heap<int> heap(a,10,15);
    heap.Show();
    heap.HeapSort();
    heap.Show();
}

//交换a,b的值
template<typename T>
void inline Swap(T &a,T &b){
    T temp;
    temp = a;
    a = b;
    b = temp;
}




