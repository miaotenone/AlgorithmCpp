//
// Created by 14771 on 2024/9/20.
//题意：给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
//注意：
//答案中不可以包含重复的四元组。
//示例： 给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。 满足要求的四元组集合为： [ [-1, 0, 0, 1], [-2, -1, 1, 2], [-2, 0, 0, 2] ]
#include "../utils/common_ds.h"

class Solution{
public:
    vector<vector<int>> find_group_3_ptr2(vector<int>& nums,int val){
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i]>=0){ break;}
            if (i>0&&nums[i]==nums[i-1]){ continue;}

            for (int j = i+1; j < nums.size(); ++j) {
                if(nums[i]+nums[j]>=val&&nums[i]+nums[j]>=0){ break;}
                if(j>i+1 && nums[j]==nums[j-1]){ continue;};

                int target = val-nums[i]-nums[j];
                int left = j+1;
                int right = nums.size()-1;
                while (left<right){
                    if (nums[left]+nums[right]>target){right--;}
                    else if(nums[left]+nums[right]<target){left++;}
                    else{
                        result.push_back({nums[i],nums[j],nums[left],nums[right]});
                        while (left<right&&nums[right]==nums[right-1]){right--;}
                        while (left<right&&nums[left]==nums[left+1]){left++;}
                        left++;
                        right--;
                    }
                }
            }
        }
        return result;
    }
};

int main(){
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    Solution sl;
    auto res = sl.find_group_3_ptr2(nums,target);
    for(auto i:res){
        cout<<i<<endl;
    }
}