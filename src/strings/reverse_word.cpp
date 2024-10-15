//
// Created by 14771 on 2024/9/23.
//给定一个字符串，逐个翻转字符串中的每个单词。
//示例 1：
//输入: "the sky is blue"
//输出:"blue is sky the"
//示例 2：
//输入: " hello world! "
//输出:"world! hello"
//解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
//示例 3：
//输入: "a good  example"
//输出:"example good a"
//解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
#include "../utils/common_ds.h"

class Solution{
public:
    void reverse_word(string& s){
        remove_e(s);
        reverse_s(s,0,s.size()-1);
        int slow = 0;
        for (int i = 0; i <= s.size(); ++i) {
            if (s[i]==' '||i==s.size()){
                reverse_s(s,slow,i-1);
                slow = i+1;
            }
        }

//        for(int i = 0; i<s.size();i++){
//            if(s[i]==' '){
//                reverse_s(s,slow,i-1);
//                slow = i+1;
//                continue;
//            }
//            if (i==s.size()-1){
//                reverse_s(s,slow,i);
//            }
//        }
    }

    void remove_e(string& s){
        int slow_index = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i]!=' '){
                if(slow_index>0){s[slow_index++] = ' ';}
                while (i<s.size()&&s[i]!=' '){
                    s[slow_index++] = s[i++];
                }
            }
        }
        s.resize(slow_index);
    }

    void remove_e1(string& s){
        int slow_index = 0;
        int fast_index = 0;
        while(fast_index<s.size() && s[fast_index]==' '){ fast_index++;}
        for (; fast_index < s.size(); fast_index++) {
            if(fast_index>0&&s[fast_index] == s[fast_index-1]&&s[fast_index]==' '){ continue;}
            s[slow_index++] = s[fast_index];
        }
        s.resize(slow_index);
    }

    void reverse_s(string& s,int start,int end){
        for(int i = start,j=end;i<j;i++,j--){
            swap(s[i],s[j]);
        }
    }
};

int main(){
    string s = "   the sky is   blue   ";
    Solution sl;
    sl.reverse_word(s);
    cout<<s;
}