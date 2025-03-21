//
// Created by 14771 on 2024/9/19.
//编写一个算法来判断一个数 n 是不是快乐数。
//「快乐数」定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
// 如果 可以变为  1，那么这个数就是快乐数。
//如果 n 是快乐数就返回 True ；不是，则返回 False 。
//示例：
//输入：19
//输出：true
//解释：
//1^2 + 9^2 = 82
//8^2 + 2^2 = 68
//6^2 + 8^2 = 100
//1^2 + 0^2 + 0^2 = 1
#include "../utils/common_ds.h"
#include "math.h"

class Solution{
public:
    bool is_happy_num(int num){
        unordered_set<int> result;
        result.insert(num);
        int cal,x,temp;
        temp = num;
        while (1){
            cal = 0;
            do{
                x = temp%10;
                cal+=pow(x,2);
                temp = temp/10;
            } while (temp!=0);
            temp = cal;
            if(cal==1){ return true;}
            if(result.find(cal)!=result.end()){
                return false;
            } else{result.insert(cal);}
        }
    }
};

int main(){
    int num = 19;
    Solution sl;
    cout<<(sl.is_happy_num(num)==true?"true":"false");
}
