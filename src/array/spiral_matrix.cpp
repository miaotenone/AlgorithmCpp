//
// Created by 14771 on 2024/9/18.
//给定一个正整数 n，生成一个包含 1 到 n^2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。
//
//示例:
//
//输入: 3 输出: [ [ 1, 2, 3 ], [ 8, 9, 4 ], [ 7, 6, 5 ] ]

#include "../utils/common_ds.h"

class Soluton{
public:
    vector<vector<int>> spiral_martirx(int n){
        vector<vector<int>> nums(n,vector(n,0));
        int pos = 0;
        int len = n;
        int judge = n % 2;
        int floor = (n%2!=0) ? (n-1)/2 : n/2;
        int num = 1;
        while(floor){
            floor--;
            for(int i = pos;i < len-1;i++){
                nums[pos][i] = num++;
            }
            for(int i = pos;i < len-1;i++)
            {
                nums[i][len-1] = num++;
            }
            for(int i = len-1;i > pos;i--)
            {
                nums[len-1][i] = num++;
            }
            for(int i = len-1;i > pos;i--)
            {
                nums[i][pos] = num++;
            }
            pos++;
            len--;
        }
        if(judge!=0){nums[pos][pos] = num;}
        return nums;
    }
};

int main(){
    Soluton sl;
    vector<vector<int>> nums  = sl.spiral_martirx(3);
    cout<<'[';
    for(auto i:nums){
        cout<<i;
    }
    cout<<']'<<endl;

    nums  = sl.spiral_martirx(4);
    cout<<'[';
    for(auto i:nums){
        cout<<i;
    }
    cout<<']';
}
