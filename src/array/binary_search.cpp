//
//reference:0704---.md
//给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。
//输入: nums = [-1,0,3,5,9,12], target = 9
//输出: 4
//解释: 9 出现在 nums 中并且下标为 4
// Created by 14771 on 2024/9/18.
//
#include "../utils/common_ds.h"

class Solution{
public:
    //[left,right]
    int binary_search(vector<int>& nums, int target){
        int left = 0;
        int right = nums.size()-1;
        int re = -1;
        while (left<=right){
            int middle = left+(right-left)/2;
            if(target==nums[middle]){ re = middle; break;}
            else if(target>nums[middle]){
                left = middle+1;
            }
            else{
                right = middle-1;
            }
        }
        return re;
    }
    //[left,right)
    int search(vector<int> nums,int target){
        int left = 0;
        int right = nums.size();
        int re = -1;
        while(left<right){
            int middle =left+((right-left)>>1);
            if(target>nums[middle]){
                left = middle+1;
            }
            else if(target<nums[middle]){
                right = middle;
            }
            else{
                re = middle;
                break;
            }
        }
        return re;
    }
};

int main(){
    vector<int> num = {-1,0,3,5,9,12};
    int target = 9;
    Solution sl;
    int re = sl.binary_search(num,target);
    cout<<re<<endl;
    re = sl.search(num,target);
    cout<<re<<endl;
}
