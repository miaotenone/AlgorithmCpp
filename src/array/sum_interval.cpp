//
// Created by 14771 on 2024/9/18.
//给定一个整数数组 Array，请计算该数组在每个指定区间内元素的总和。
//第一行输入为整数数组 Array 的长度 n，接下来 n 行，每行一个整数，表示数组的元素。随后的输入为需要计算总和的区间，直至文件结束。
//输出描述
//输出每个指定区间内元素的总和。
//-------前缀和-----查询次数大的情况

#include "../utils/common_ds.h"

int main(){
    int n,l,r;
    cin>>n;
    vector<int> nums(n);
    vector<int> sum_nums(n);
    int temp = 0;
    for(int i=0;i<n;++i){
        cin>>nums[i];
        temp += nums[i];
        sum_nums[i] = temp;
    }
    while(cin>>l>>r){
        int sum = 0;
        if(l==0){sum = sum_nums[r];}
        else{sum = sum_nums[r]-sum_nums[l-1];}
        cout<<sum<<endl;
    }


//    int n = cin.get();
//    vector<int> nums(n,0);
//    for (int i = 0; i < n; ++i) {
//        nums[i] = cin.get();
//    }
//    int left;
//    int right;
//    while(cin>>left>>right){
//        int sum = 0;
//        for(int i = left;i<=right;i++){
//            sum += nums[i];
//        }
//        cout<<sum<<endl;
//    }

}