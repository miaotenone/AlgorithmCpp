//
// Created by 14771 on 2024/9/19.
//题意：给定两个数组，编写一个函数来计算它们的交集。
//输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
//输出：[9,4]

#include "../utils/common_ds.h"

class Solution{
public:
    vector<int> intersection(vector<int>& nums1,vector<int>& nums2){
        unordered_set<int> result_set; // 存放结果，之所以用set是为了给结果集去重
        unordered_set<int> nums_set(nums1.begin(), nums1.end());
        for (int num : nums2) {
            // 发现nums2的元素 在nums_set里又出现过
            if (nums_set.find(num) != nums_set.end()) {
                result_set.insert(num);
            }
        }
        return vector<int>(result_set.begin(), result_set.end());
    }
};

int main(){
    vector<int> nums1 = {4,9,5};
    vector<int> nums2 = {9,4,9,8,4};
    Solution sl;
    vector<int> res = sl.intersection(nums1,nums2);
    cout<<res;
}