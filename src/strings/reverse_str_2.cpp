//
// Created by 14771 on 2024/9/23.
//给定一个字符串 s 和一个整数 k，从字符串开头算起, 每计数至 2k 个字符，就反转这 2k 个字符中的前 k 个字符。
//如果剩余字符少于 k 个，则将剩余字符全部反转。
//如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。
//示例:
//输入: s = "abcdefg", k = 2
//输出: "bacdfeg"

#include "../utils/common_ds.h"

class Solution{
public:
    string reverse_str(string str,int k){
        for (int i = 0; i < str.size(); i+=(2*k)) {
            if(i+k<=str.size()){
                reverseS(str,i,i+k-1);
            }
            else{
                reverseS(str,i,str.size()-1);
            }
        }
        return str;
    }

    void reverseS(string& str,int start,int end){
        for (int i = start,j=end; i < j; i++,j--) {
            swap(str[i],str[j]);
        }
    }
};

int main(){
    string str = "abcdefg";
    int k = 2;
    Solution sl;
    string res = sl.reverse_str(str,k);
    cout<<res;
}