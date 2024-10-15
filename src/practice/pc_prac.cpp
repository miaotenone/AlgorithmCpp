//
// Created by 14771 on 2024/9/14.
//
#include <iostream>
int main(){

    int  x = 12;
    const int* x1 = &x;
    int* x2 = new int(3);
    x1 = x2;
    //x1 = 3; xxxxxx
    int* const x3 = &x;
    *x3 = 4;



    // const reference
//    int i =42;
//    const int &r = i;
//    std::cout<<i<<' '<<r<<std::endl;
//    i = 23;
//    std::cout<<i<<' '<<r<<std::endl;
}