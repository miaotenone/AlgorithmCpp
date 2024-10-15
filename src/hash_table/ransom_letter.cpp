//
// Created by 14771 on 2024/9/20.
//给定一个赎金信 (ransom) 字符串和一个杂志(magazine)字符串，判断第一个字符串 ransom 能不能由第二个字符串 magazines 里面的字符构成。如果可以构成，返回 true ；否则返回 false。
//(题目说明：为了不暴露赎金信字迹，要从杂志上搜索各个需要的字母，组成单词来表达意思。杂志字符串中的每个字符只能在赎金信字符串中使用一次。)
//注意：
//你可以假设两个字符串均只含有小写字母。
//canConstruct("a", "b") -> false
//canConstruct("aa", "ab") -> false
//canConstruct("aa", "aab") -> true
#include "../utils/common_ds.h"

class Solution{
public:
    bool is_composed(string r,string m){
        int* record = new int[26]{0};
        if (m.size()<r.size()){return false;}
        for (int i = 0; i < m.size(); ++i) {
            record[m[i]-'a']++;
        }
        for (int i = 0; i < r.size(); ++i) {
            record[r[i]-'a']--;
        }
        for (int i = 0; i < 26; ++i) {
            if (record[i]<0){
                return false;
            }
        }
        return true;
    }
    bool is_composed_m(string r,string m){
        unordered_map<char,int> map1{0};
        for (int i = 0; i < m.size(); ++i) {
            map1[m[i]]++;
        }
        for (int i = 0; i < r.size(); ++i) {
            map1[r[i]]--;
        }
        for (auto i = map1.begin();i!=map1.end();i++) {
            if (i->second<0){
                return false;
            }
        }
        return true;
    }
};

int main(){
    string r = "aa";
    string m = "aab";
    Solution sl;
    string res = sl.is_composed_m(r,m) ? "true" : "false";
    cout<<res;
}