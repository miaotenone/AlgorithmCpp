//
// Created by 14771 on 2024/10/9.
//使用队列实现栈的下列操作：
//push(x) -- 元素 x 入栈
//pop() -- 移除栈顶元素
//top() -- 获取栈顶元素
//empty() -- 返回栈是否为空

#include "../utils/common_ds.h"

class MyStack {
public:
    MyStack() {

    }

    void push(int x) {
        queue1.push(x);
        //top_member = x;
    }
//将除了最后一个元素加入队尾，弹出的就是top o(n)
    int pop() {
        int size = queue1.size()-1;
        if (size<0){return INT32_MAX;}
        while (size--){
            queue1.push(queue1.front());
            queue1.pop();
        }
        int result = queue1.front();
        queue1.pop();
        return result;
    }

    int top() {
        int size = queue1.size()-1;
        if (size<0){return INT32_MAX;}
        while (size--){
            queue1.push(queue1.front());
            queue1.pop();
        }
        int result = queue1.front();
        queue1.push(queue1.front());
        queue1.pop();

        return result;
//        if (!empty()){return top_member;}
//        else{return -1;}
    }

    bool empty() {
        return queue1.size()==0? true: false;
    }
private:
    queue<int> queue1;
    //int top_member;
};

int main(){
    MyStack myStack;
    myStack.push(1);
    myStack.push(2);
    myStack.top(); // 返回 2
    myStack.pop(); // 返回 2
    myStack.empty(); // 返回 False
}
