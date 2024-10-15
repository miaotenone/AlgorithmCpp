//
// Created by 14771 on 2024/9/6.
//

#include "iostream"
#include "array"
#include "functional"
template<typename T,size_t size>
class Print {
public:
    static void PrintArray(const std::array<T,size> data){
        for(auto i : data){
            std::cout<<i<< ' ';
        }
    }
    //functional pointer
    static void Foreach(const std::array<T,size> data,void(*func)(int val)){
        for(auto i : data){
            func(i);
        }
    }
    static void Foreach1(const std::array<T,size> data,std::function<void(int)>& func){
        for(auto i : data){
            func(i);
        }
    }
};
void PrintVal(int val){
    std::cout<<val<<' ';
}
int main()
{
    //created in stack,so it's fast in the running
    std::array<int,5> array1 = {1,2,3,4,5};
    Print<int,5> print;
    print.PrintArray(array1);
    std::cout<< std::endl;
    print.Foreach(array1,PrintVal);
    std::cout<< std::endl;
    print.Foreach(array1,[](int a){std::cout<<a<<' ';});
    std::cout<< std::endl;
    auto x = PrintVal;
    print.Foreach(array1,x);
}