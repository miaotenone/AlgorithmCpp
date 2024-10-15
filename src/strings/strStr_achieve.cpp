//KMP match
// Created by 14771 on 2024/9/27.
//给定一个haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。
//示例 1:
//输入: haystack = "hello", needle = "ll"
//输出: 2
//示例 2:
//输入: haystack = "aaaaa", needle = "bba"
//输出: -1
//说明:
//当needle是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
//对于本题而言，当needle是空字符串时我们应当返回 0 。这与C语言的strstr()以及 Java的indexOf()定义相符。
#include "../utils/common_ds.h"

class Solution{
public:
/*
    int strStr_f(string& haystack,string& needle){
        if (haystack.size()<needle.size()){
            return -1;
        }
        if(needle.empty()){return 0;}
        for (int i = 0; i < haystack.size(); ++i) {
            if (haystack[i]==needle[0]){
                int x = i+1;
                bool is_match = true;
                for (int j = 1; j < needle.size(); ++j) {
                    if(haystack[x++]!=needle[j]){
                        is_match = false;
                    }
                }
                if (is_match== true){
                    return i;
                }
            }
        }
        return -1;
    }
    int strStr_ptr(string& haystack,string& needle){
        int j = 0;
        for (int i = 0; i < haystack.size(); ++i) {
            if (haystack[i]==needle[j]&&j<needle.size()){
                if (j==needle.size()-1){
                    return i-(needle.size()-1);
                }
                j++;
            }
            else{
                j = 0;
            }
        }
        return -1;
    }
 */
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
    void getNext(int* next,const string& s){
        int j = -1;
        next[0] = j;
        for (int i = 1; i < s.size(); ++i) {
            while (j>=0 && s[i]!=s[j+1]){
                j = next[j];
            }
            if(s[i] == s[j+1]){
                j++;
            }
            next[i] = j;
        }
}
};

int main(){
    string haystack = "aabaabaaf";
    string needle = "aabaaf";
    Solution sl;
    int result = sl.strStr_KMP(haystack,needle);
    cout<<result;

}

