//
// Created by 14771 on 2024/9/19.
//给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
//示例 1: 输入: s = "anagram", t = "nagaram" 输出: true
//示例 2: 输入: s = "rat", t = "car" 输出: false
//说明: 你可以假设字符串只包含小写字母。

#include "../utils/common_ds.h"

class Solution{
public:
    bool is_anagram(string s,string t){
        int* record = new int[26]{0};
        for(int i = 0;i<s.size();i++){
            record[s[i]-'a']++;
        }
        for (int i = 0; i < t.size(); ++i) {
            record[t[i]-'a']--;
        }
        for (int i = 0; i < 26; ++i) {
            if(record[i]!=0){return false;}
        }
        return true;
    }
};

int main(){
    const char* s = "anagram";
    const char* t = "nagaram";
    Solution sl;
    cout<<(sl.is_anagram(s,t)==true?"true":"false");
}
