//
// Created by 14771 on 2024/9/12.
//
#include <iostream>
#include <thread>

static bool is_finished = false;
void DoWork(){
    using namespace std::chrono_literals;
    std::cout<<"id:"<<std::this_thread::get_id()<<std::endl;
    while (!is_finished){
        std::cout<<"working!!!"<<std::endl;
        std::this_thread::sleep_for(1s);
    }
}

int main(){
    std::thread Worker(DoWork);
    std::cin.get();
    Worker.join();
    is_finished = true;
    std::cout<<"finished"<<std::endl;
    std::cout<<"start new thread id:"<<std::this_thread::get_id()<<std::endl;
    std::cin.get();
}
