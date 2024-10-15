//
// Created by 14771 on 2024/10/9.
//使用栈实现队列的下列操作：
//push(x) -- 将一个元素放入队列的尾部。
//pop() -- 从队列首部移除元素。
//peek() -- 返回队列首部的元素。
//empty() -- 返回队列是否为空。

#include "../utils/common_ds.h"

class MyQueue {
public:
    MyQueue() {

    }

    void push(int x) {
        stack1.push(x);
        //top_member = x;
    }
//将除了最后一个元素加入队尾，弹出的就是top o(n)
    int pop() {
        stack<int> temp;
        int size = stack1.size()-1;
        while (size--){
            temp.push(stack1.top());
            stack1.pop();
        }
        int result = stack1.top();
        stack1.pop();
        while (!temp.empty()){
            stack1.push(temp.top());
            temp.pop();
        }
        return result;
    }

    int peek() {
        stack<int> temp;
        int size = stack1.size()-1;
        while (size--){
            temp.push(stack1.top());
            stack1.pop();
        }
        int result = stack1.top();
        while (!temp.empty()){
            stack1.push(temp.top());
            temp.pop();
        }
        return result;
    }

    bool empty() {
        return stack1.size()==0? true: false;
    }
private:
    stack<int> stack1;
};



int main(){
    MyQueue queue ;
    queue.push(1);
    queue.push(2);
    queue.peek();  // 返回 1
    queue.pop();   // 返回 1
    queue.empty(); // 返回 false
}