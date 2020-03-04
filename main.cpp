#include<iostream>

void test(int *&a){
    int b = 10;
    a = &b;
}

//void test2(int &*a){
//    int b = 10;
//    a = &b;
//}

int main(){
    int c = 1;
    int *a = &c;

    test(a);

    std::cout<<*a<<std::endl;
}
