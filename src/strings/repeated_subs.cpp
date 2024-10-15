//
// Created by 14771 on 2024/9/27.
//给定一个非空的字符串，判断它是重复多次构成。给定的字符串只含有小写英文字母，并且长度不超过10000。
//示例 1:
//* 输入: "abab"
//* 输出: True
//* 解释: 可由子字符串 "ab" 重复两次构成。
//示例 2:
//* 输入: "aba"
//* 输出: False
//示例 3:
//* 输入: "abcabcabcabc"
//* 输出: True
//* 解释: 可由子字符串 "abc" 重复四次构成。 (或者子字符串 "abcabc" 重复两次构成。)
#include "../utils/common_ds.h"

class Solution{
public:
    bool repeated_subs1(string& s){
        if (s.size()==0){return false;}
        string s1 = s + s;
        s1.erase(s1.begin()); s1.erase(s1.end() - 1);
        return strStr_KMP(s1,s)==-1? false: true;
    }
    bool repeated_subs2(string& s){
        if (s.size()==0){return false;}
        string s1 = s + s;
        s1.erase(s1.begin()); s1.erase(s1.end() - 1);
        return s1.find(s)==std::string::npos? false: true;
    }
    bool repeated_subs(string& s){
        if (s.size()==0){return false;}
        int next[s.size()];
        getNext(next, s);
        int len = s.size();
        if (next[len - 1] != -1 && len % (len - (next[len - 1] + 1)) == 0) {
            return true;
        }
        return false;
    }
    int strStr_KMP(string& haystack,string& needle){
        if (needle.size() == 0){return 0;}
        vector<int> next(needle.size());
        getNext(&next[0],needle);

        for (int i = 0, j = -1; i < haystack.size(); ++i) {
            while (j >= 0 && haystack[i]!=needle[j+1]){
                j = next[j];
            }
            if (haystack[i]==needle[j+1]){
                j++;
            }
            if (j==(needle.size()-1)){return i-needle.size()+1;}
        }
        return -1;
    }
    void getNext(int* next,const string& s) {
        int j = -1;
        next[0] = j;
        for (int i = 1; i < s.size(); ++i) {
            while (j >= 0 && s[i] != s[j + 1]) {
                j = next[j];
            }
            if (s[i] == s[j + 1]) {
                j++;
            }
            next[i] = j;
        }
    }
};

int main(){
    string s = "ababababacbab";
    Solution sl;
    bool is_repeated = sl.repeated_subs(s);
    cout<<(is_repeated==true?"true":"false");
}