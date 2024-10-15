//
// Created by 14771 on 2024/9/18.
//给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。
//
//示例 1：
//
//输入：nums = [-4,-1,0,3,10]
//输出：[0,1,9,16,100]
//解释：平方后，数组变为 [16,1,0,9,100]，排序后，数组变为 [0,1,9,16,100]
//示例 2：
//
//输入：nums = [-7,-3,2,3,11]
//输出：[4,9,9,49,121]

#include "../utils/common_ds.h"
#include "math.h"
class Solution{
public:
    vector<int> square_s_array_v(vector<int>& nums){
        vector<int> re(nums.size(),0);
        for (int i = 0; i < nums.size(); ++i) {
            re[i] = pow(nums[i],2);
        }
        std::sort(re.begin(),re.end());
        return re;
    }
    //ptr2 method----negative integer
    vector<int> square_s_array(vector<int>& nums){
        int left = 0;
        int right = nums.size()-1;
        int index = right;
        vector<int> re(nums.size(),0);
        while(left<=right){
            if(nums[left]*nums[left]<=nums[right]*nums[right]){
                re[index--] = nums[right]*nums[right];
                right--;
            }
            else{
                re[index--] = nums[left]*nums[left];
                left++;
            }
        }
        return re;
    }
};

int main(){
  vector<int> nums = {-4,-1,0,3,10};
  Solution sl;
  vector<int> re = sl.square_s_array(nums);
  cout<<re<<endl;

  nums = {-7,-3,2,3,11};
  re = sl.square_s_array(nums);
  cout<<re<<endl;

}