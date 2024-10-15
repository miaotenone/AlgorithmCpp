//
// Created by 14771 on 2024/9/23.
//编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 char[] 的形式给出。
//不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1)  的额外空间解决这一问题。
//你可以假设数组中的所有字符都是 ASCII 码表中的可打印字符。
//示例 1：
//输入：["h","e","l","l","o"]
//输出：["o","l","l","e","h"]
//示例 2：
//输入：["H","a","n","n","a","h"]
//输出：["h","a","n","n","a","H"]

#include "../utils/common_ds.h"

class Solution{
public:
    void reverse_str(vector<char>& str){
        int size = str.size();
        int left = 0;
        int right = size-1;
        while(left<right){
            char temp = str[left];
            str[left] = str[right];
            str[right] = temp;
            //s[i] ^= s[j];
            //s[j] ^= s[i];
            //s[i] ^= s[j];
            left++;right--;
        }

    }
};



int main(){
    vector<char> s = {'h','e','l','l','o'};
    Solution sl;
    sl.reverse_str(s);
    for(char i:s){cout<<i;}
}