//
// Created by 14771 on 2024/9/19.
//给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
//你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。
//示例:
//给定 nums = [2, 7, 11, 15], target = 9
//因为 nums[0] + nums[1] = 2 + 7 = 9
//所以返回 [0, 1]

#include "../utils/common_ds.h"

class Solution {
public:
    vector<int> find_target(vector<int>& nums,int target){
        unordered_map<int,int> map;
        for (int i = 0; i < nums.size(); ++i) {
            unordered_map<int,int>::iterator iter = map.find(target-nums[i]);
            if(iter!=map.end()){
                return vector<int>{iter->second,i};
            }
            else{
                map.insert(pair<const int,int>(nums[i],i));
            }
        }
        return {};
    }
};
int main(){
    vector<int> nums = {2,7,11,15};
    int target = 9;
    Solution sl;
    vector<int> res = sl.find_target(nums,target);
    cout<<res<<endl;

    nums = {3,2,4};
    target = 6;
    res = sl.find_target(nums,target);
    cout<<res;
}
