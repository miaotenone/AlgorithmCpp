//
// Created by 14771 on 2024/9/23.
//给定一个字符串 s，它包含小写字母和数字字符，请编写一个函数，将字符串中的字母字符保持不变，而将每个数字字符替换为number。
//例如，对于输入字符串 "a1b2c3"，函数应该将其转换为 "anumberbnumbercnumber"。
//对于输入字符串 "a5b"，函数应该将其转换为 "anumberb"
//输入：一个字符串 s,s 仅包含小写字母和数字字符。
//输出：打印一个新的字符串，其中每个数字字符都被替换为了number
//样例输入：a1b2c3
//样例输出：anumberbnumbercnumber
//数据范围：1 <= s.length < 10000。

#include "../utils/common_ds.h"

class Solution{
public:
    string replace_num(string& str){
        string rep_str = "number";
        string res ="";
        for (int i = 0; i < str.size(); ++i) {
            if(str[i]>'0'&&str[i]<'9'){
                for (int j = 0; j < rep_str.size(); ++j) {
                    res.push_back(rep_str[j]);
                }
            } else{
                res.push_back(str[i]);
            }
        }
        return res;
    }
    string replace_num1(string& s){
        int sOldIndex = s.size() - 1;
        int count = 0; // 统计数字的个数
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                count++;
            }
        }
        s.resize(s.size() + count * 5);
        int sNewIndex = s.size() - 1;
        while (sOldIndex >= 0) {
            if (s[sOldIndex] >= '0' && s[sOldIndex] <= '9') {
                s[sNewIndex--] = 'r';
                s[sNewIndex--] = 'e';
                s[sNewIndex--] = 'b';
                s[sNewIndex--] = 'm';
                s[sNewIndex--] = 'u';
                s[sNewIndex--] = 'n';
            } else {
                s[sNewIndex--] = s[sOldIndex];
            }
            sOldIndex--;
        }
    }
};



int main(){
    string s = "a1b2c3";
    Solution sl;
    string res = sl.replace_num(s);
    cout<<res;
}
