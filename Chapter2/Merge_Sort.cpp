//
// Created by liu on 2020/2/9.
//
#include<iostream>
#include<cmath>
using namespace std;

const int inf = INT32_MAX;

//pqr 分别是数组的下标 p<=q<r
//a[p...q]和a[q+1,r]是有序的
void Merge(int a[],int p,int q,int r);
void MergeSort(int a[],int p,int r);

int main(){
    int a[11]={5,64,12,41,32,13,99,16,67,86,52};
    MergeSort(a,0,10);
    for(auto i:a){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}

void Merge(int a[],int p,int q,int r){
    //计算两个数组的长度
    int n1 = q-p+1;
    int n2 = r-q;

    //创建两个数组存放子数组
    int *L,*R;
    L = new int[n1+1];
    R = new int[n2+1];

    //对数组进行复制
    for(int i = 0;i < n1;i++){
        L[i] = a[p + i];
    }
    for(int i = 0;i < n2;i++){
        R[i] = a[q + i + 1];
    }
    //末尾默认inf(数组的额外位置)
    L[n1]=inf;
    R[n2]=inf;

    //抽卡式比较插入
    int i=0,j=0;
    for(int k = p;k <= r; k++){
        if(L[i]<=R[j]){
            a[k] = L[i];
            i++;
        }else{
            a[k] = R[j];
            j++;
        }
    }
}

void MergeSort(int a[],int p,int r){
    if(p < r){
        int q;
        q = floor((p+r)/2);
        MergeSort(a,p,q);
        MergeSort(a,q+1,r);
        Merge(a,p,q,r);
    }
}
