//
// Created by 14771 on 2024/9/20.
//给定四个包含整数的数组列表 A , B , C , D ,计算有多少个元组 (i, j, k, l) ，使得 A[i] + B[j] + C[k] + D[l] = 0。
//为了使问题简单化，所有的 A, B, C, D 具有相同的长度 N，且 0 ≤ N ≤ 500 。所有整数的范围在 -2^28 到 2^28 - 1 之间，最终结果不会超过 2^31 - 1 。
//例如:
//输入:
//A = [ 1, 2]
//B = [-2,-1]
//C = [-1, 2]
//D = [ 0, 2]
//输出:
//2
#include "../utils/common_ds.h"

class Solution{
public:
    int sum_num4_2(vector<int> num1,vector<int> num2,vector<int> num3,vector<int> num4){
        int count = 0;
        unordered_map<int,int> u_map;
        for(int a:num1){
            for(int b:num2){
                u_map[a+b]++;
            }
        }
        for(int c:num3){
            for(int d:num4){
                if(u_map.find(0-c-d)!=u_map.end()){
                    count += u_map[0-c-d];
                }
            }
        }
        return count;
    }
};

int main(){
    vector<int> num1 = {1,2};
    vector<int> num2 = {-2,-1};
    vector<int> num3 = {-1,2};
    vector<int> num4 = {0,2};
    Solution sl;
    int res = sl.sum_num4_2(num1,num2,num3,num4);
    cout<<res;
}