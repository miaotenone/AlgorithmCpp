//
// Created by 14771 on 2024/9/18.
//在一个城市区域内，被划分成了n * m个连续的区块，每个区块都拥有不同的权值，代表着其土地价值。目前，有两家开发公司，A 公司和 B 公司，
// 希望购买这个城市区域的土地。现在，需要将这个城市区域的所有区块分配给 A 公司和 B 公司。
//然而，由于城市规划的限制，只允许将区域按横向或纵向划分成两个子区域，而且每个子区域都必须包含一个或多个区块。
//为了确保公平竞争，你需要找到一种分配方式，使得 A 公司和 B 公司各自的子区域内的土地总价值之差最小。
//注意：区块不可再分。
//【输入描述】
//第一行输入两个正整数，代表 n 和 m。
//接下来的 n 行，每行输出 m 个正整数。
//输出描述
//请输出一个整数，代表两个子区域内土地总价值之间的最小差距。
//【输入示例】
//3 3 1 2 3 2 1 3 1 2 3
//【输出示例】
//
//0

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int m,n,temp;
    int sum = 0;
    cin>>m>>n;
    vector<vector<int>> nums(m,vector<int>(n));
    vector<int> sum_r_nums(m);
    vector<int> sum_c_nums(n);

    int min_diff = INT32_MAX;

    for(int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> nums[i][j];
            sum += nums[i][j];
        }
        sum_r_nums[i] = sum;
    }
    for (int j = 0; j < n; ++j) {
        for(int i = 0; i < m; ++i) {
            cin >> nums[i][j];
            sum += nums[i][j];
        }
        sum_c_nums[j] = sum;
    }
    for(int i = 0;i < m-1;i++){
        int sub_diff = sum-sum_r_nums[i];
        if(sub_diff< min_diff){min_diff=sub_diff;}
    }
    for(int i = 1;i < n;i++){
        int sub_diff = sum-sum_c_nums[i];
        if(sub_diff< min_diff){min_diff=sub_diff;}
    }
    cout<<min_diff<<endl;
}