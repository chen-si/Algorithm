//
// Created by liu on 2020/2/5.
//
#include<iostream>
using namespace std;

int * BinaryAddAB(const int a[],const int b[],int n);

int main(){
    int a[]={1,0,0,0,1,0,1,0,1};
    int b[]={1,1,1,0,0,0,1,0,1};
    int *c;
    c = BinaryAddAB(a,b,9);
    for(int i = 0;i < 10;i++){
        cout<<c[i]<<" ";
    }
    cout<<endl;

    return 0;
}

int * BinaryAddAB(const int a[],const int b[],int n){
    int *c;
    c = new int[n+1];
    int key{0};//key表示进位
    int temp;//temp暂存单位运算结果
    for(int i = n-1;i >= 0;i--){
        temp=a[i]+b[i]+key;
        if (temp == 3 || temp == 2) {
            key = 1;
        }else{
            key = 0;
        }
        switch(temp){
            case 0:
                c[i+1] = 0;
                break;
            case 1:
                c[i+1] = 1;
                break;
            case 2:
                c[i+1] = 0;
                break;
            case 3:
                c[i+1] = 1;
                break;
        }
    }
    //最后一步key中保存了a[0]+b[0]+key的进位
    c[0] = key;

    return c;
}