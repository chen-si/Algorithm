//
// Created by liu on 2020/2/10.
//
#include<iostream>
using namespace std;

void BubbleSort(int a[],int n);

int main(){
    int a[11]={5,64,44,41,32,13,25,16,67,85,52};
    BubbleSort(a,11);
    for(auto i:a){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}

void BubbleSort(int a[],int n){
    int temp;
    for(int i = 0;i < n-1;i++){
        for(int j = n-1;j > i;j--){
            if(a[j]<a[j-1]){
                temp = a[j];
                a[j] = a[j-1];
                a[j-1] = temp;
            }
        }
    }
}



