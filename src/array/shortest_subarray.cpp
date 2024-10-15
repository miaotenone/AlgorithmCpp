//
// Created by 14771 on 2024/9/18.
//给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的 连续 子数组，并返回其长度。如果不存在符合条件的子数组，返回 0。
//
//示例：
//
//输入：s = 7, nums = [2,3,1,2,4,3]
//输出：2
//解释：子数组 [4,3] 是该条件下的长度最小的子数组。
#include "../utils/common_ds.h"

class Solution{
public:
    int short_subarray_f(vector<int>& nums,int val){
        int size = INT32_MAX;
        for(int i = 0;i<nums.size();i++){
            int temp = 0;
            int sub_size = 0;
            for(int j = i;j<nums.size();j++){
                temp += nums[j];
                sub_size++;
                if(temp>=val){
                    if(sub_size < size){
                        size = sub_size;
                    }
                    break;
                }
            }
        }
        if(size==nums.size()+1){return 0;}
        return size;
    }
    //slide window
    //for counting the
    int short_subarray(vector<int>& nums,int val){
        int left = 0;
        int size = INT32_MAX;
        int temp_val = 0;
        for (int i = 0; i < nums.size(); ++i) {
            temp_val+=nums[i];
            while (temp_val>=val){
                int sub_len = i-left+1;
                int size = size>sub_len?size:sub_len;
                temp_val -= nums[left++];
            }
        }
        return size==INT32_MAX?0:size;
    }
};

int main(){
    vector<int> nums = {2,3,1,2,4,3};
    int val = 4;
    Solution sl;
    int res = sl.short_subarray_f(nums,val);
    cout<<res<<endl;
}
