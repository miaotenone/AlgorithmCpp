//
// Created by 14771 on 2024/9/12.
//
#include <chrono>
#include <iostream>
#include <thread>

struct Timer{
    std::chrono::time_point<std::chrono::system_clock> start,end;
    std::chrono::duration<float> duration;
    Timer(){
        start = std::chrono::high_resolution_clock::now();
    }
    ~Timer(){
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        std::cout<<duration.count()*1000<<"ms"<<std::endl;
    }

};

void Function(){
    Timer timer;
    //27.7259ms
//    for (int i = 0; i < 100; ++i) {
//        std::cout<<"working"<<std::endl;
//    }
// 14.7084ms
    for (int i = 0; i < 100; ++i) {
        std::cout<<"working\n";
    }
}

int main(){
    using namespace std::chrono_literals;
    std::thread func(Function);
    func.join();
    std::cin.get();

    auto start = std::chrono::high_resolution_clock::now();
    std::this_thread::sleep_for(1s);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> duration = end - start;
    std::cout<<duration.count()<< std::endl;
};