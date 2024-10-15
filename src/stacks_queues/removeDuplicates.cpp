//
// Created by 14771 on 2024/10/9.
//给出由小写字母组成的字符串 S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。
//在 S 上反复执行重复项删除操作，直到无法继续删除。
//在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。
//示例：
//输入："abbaca"
//输出："ca"
//解释：例如，在 "abbaca" 中，我们可以删除 "bb" 由于两字母相邻且相同，这是此时唯一可以执行删除操作的重复项。之后我们得到字符串 "aaca"，其中又只有 "aa" 可以执行重复项删除操作，所以最后的字符串为 "ca"。
#include "../utils/common_ds.h"

class Solution{
public:
    string removeDuplicates(string& s){
        stack<char> st;
        for (int i = 0; i < s.size(); ++i) {
            if (st.empty()||st.top()!=s[i]){st.push(s[i]);
                continue;}
            if (st.top()==s[i]){
                st.pop();
                continue;
            }
        }
        string re = "";
        while (!st.empty()){
            re += st.top();
            st.pop();
        }
        reverse(re);
        return re;

//        char* s1 = new char[st.size()+1];
//        s1[st.size()] = '\0';
//        for (int i = st.size()-1; i >= 0 ; i--) {
//            s1[i] = st.top();
//            st.pop();
//        }
//        return s1;
    }
    void reverse(string& s){
        int left = 0;
        int right = s.size()-1;
        while (left<right){
            s[left] ^= s[right];
            s[right] ^= s[left];
            s[left] ^= s[right];
            left++;right--;
        }
    }
};

int main(){
    string s = "abbaca";
    Solution sl;
    cout<<sl.removeDuplicates(s);
}