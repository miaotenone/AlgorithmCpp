//
// Created by 14771 on 2024/10/9.
//给定一个数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
//返回滑动窗口中的最大值。
// 输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
//输出：[3,3,5,5,6,7]

#include "../utils/common_ds.h"

class MonotoneQueue{
private:
    queue<int> queue1;
public:
    int front(){
        return queue1.front();
    }
    void push(int value){
        if (value>front()&&!queue1.empty()){
            while (!queue1.empty()){
                queue1.pop();
            }
        }
        queue1.push(value);
    }
    void pop(int value){
        if (value == front()){
            queue1.pop();
        }
    }
};
class Solution {
public:
    vector<int> find_max(vector<int>& nums,int k){
        MonotoneQueue mq;
        vector<int> result;
        for (int i = 0; i < k; ++i) {
            mq.push(nums[i]);
        }
        result.push_back(mq.front());
        for (int i = k; i < nums.size(); ++i) {
            mq.pop(nums[i]);
            mq.push(nums[i]);
            result.push_back(mq.front());
        }
        return result;
    }
};
int main(){
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    Solution sl;
    cout<<sl.find_max(nums,k);
}
