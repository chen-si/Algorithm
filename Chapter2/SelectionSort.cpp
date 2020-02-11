//
// Created by liu on 2020/2/9.
//
#include<iostream>

using namespace std;

//a为待排序的数组，n为该数组的长度
//无返回值
void SelectSort(int a[],int n);

int main(){
    int a[11]={5,64,44,41,32,13,25,16,67,85,52};
    SelectSort(a,11);
    for(auto i:a){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}

void SelectSort(int a[],int n){
    int temp,index;
    for(int i=0;i < n-1;i++){
        index = i;
        for(int j = i+1;j < n;j++){
            //找到a[j]~a[n]中的最小值的index
            if(a[j]<a[index])
                index = j;
        }
        //交换a[i]和a[index]
        temp = a[i];
        a[i]=a[index];
        a[index]=temp;
    }
}