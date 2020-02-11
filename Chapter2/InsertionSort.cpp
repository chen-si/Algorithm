//
// Created by liu on 2020/2/5.
//
#include<iostream>

void InsertSort(int *A,int n);
void InsertSortDesc(int A[],int n);

int main(){
    int a[12]={12,45,625,45,688,23,41,5,1,6,45,6};
    int *b = a;
    int c[12]={12,45,625,45,688,23,41,5,1,6,45,6};
    InsertSort(b,12);
    for(int i = 0;i < 12; i++){
        std::cout<<b[i]<<" ";
    }
    std::cout<<std::endl;
    InsertSortDesc(c,12);
    for(int i : c){
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
}

void InsertSort(int A[],int n){
    int key{0};
    int i;
    for(int j = 1;j < n;j++){
        key = A[j];
        //Insert A[j] to the sorted sequence A[0,...,j-1];
        i = j - 1;
        while(i >= 0&&A[i]>key){
            A[i+1]=A[i];
            i=i-1;
        }
        A[i+1]=key;
    }
}

void InsertSortDesc(int A[],int n){
    int key{0};
    int i;
    for(int j = 1;j < n;j++){
        key = A[j];
        //Insert A[j] to the sorted sequence A[0,...,j-1];
        i = j - 1;
        while(i >= 0&&A[i]<key){
            A[i+1]=A[i];
            i=i-1;
        }
        A[i+1]=key;
    }
}

