//
// Created by liu on 2020/2/10.
//
#include<iostream>
using namespace std;

//霍纳规则用来求多项式的值
//a[] 代表多项式对应项的系数 n为数组最后一位的下标
//x为多项式中未知数的值
//求和a[k]x^k k:0-n
int Horner(const int a[],int n,int x);

int main(){
    int a[5] = {1,2,3,4,5};
    int sum;
    sum = Horner(a,4,2);
    cout<<sum<<endl;
}

int Horner(const int a[],int n,int x){
    int y{0};
    for(int i = n;i >= 0; i--){
        y = a[i]+x*y;
    }
    return y;
}
