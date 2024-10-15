//
// Created by 14771 on 2024/9/20.
//给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。
//注意： 答案中不可以包含重复的三元组。
//示例：
//给定数组 nums = [-1, 0, 1, 2, -1, -4]，
//满足要求的三元组集合为： [ [-1, 0, 1], [-1, -1, 2] ]
#include "../utils/common_ds.h"

class Solution{
public:
    vector<vector<int>> find_group_3_hash(vector<int>& nums){
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i]>=0){ break;}
            if (i>0&&nums[i]==nums[i-1]){ continue;}
            unordered_set<int> set;
            for (int j = i+1; j < nums.size(); ++j) {
                if (j > i + 2
                    && nums[j] == nums[j-1]
                    && nums[j-1] == nums[j-2]) { // 三元组元素b去重
                    continue;
                }
                int target = 0 - (nums[i]+nums[j]);
                unordered_set<int>::iterator iter = set.find(target);
                if(iter!=set.end()){
                    result.push_back(vector<int>{nums[i],nums[j],target});
                    set.erase(target);
                }
                else{
                    set.insert(nums[j]);
                }
            }
        }
        return result;
    }
    vector<vector<int>> find_group_3_ptr2(vector<int>& nums){
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i]>=0){ break;}
            if (i>0&&nums[i]==nums[i-1]){ continue;}
            int left = i+1;
            int right = nums.size()-1;
            int target = 0-nums[i];
            while (left<right){
                if(nums[left]+nums[right]==target){
                    result.push_back({nums[i],nums[left],nums[right]});
                    while (right > left && nums[right] == nums[right - 1]) right--;
                    while (right > left && nums[left] == nums[left + 1]) left++;
                    right--;
                    left++;
                }
                else if (nums[left]+nums[right]>target){
                    right--;
                }
                else{
                    left++;
                }

            }
        }
        return result;
    }
};

int main(){
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    Solution sl;
    auto res = sl.find_group_3_ptr2(nums);
    for(auto i:res){
        cout<<i<<endl;
    }
}