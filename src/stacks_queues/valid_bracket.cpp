//
// Created by 14771 on 2024/10/9.
//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
//有效字符串需满足：
//左括号必须用相同类型的右括号闭合。
//左括号必须以正确的顺序闭合。
//注意空字符串可被认为是有效字符串。
//示例 1:
//输入: "()"
//输出: true
//示例 2:
//输入: "()[]{}"
//输出: true
//示例 3:
//输入: "(]"
//输出: false
//示例 4:
//输入: "([)]"
//输出: false
//示例 5:
//输入: "{[]}"
//输出: true
#include "../utils/common_ds.h"

class Solution{
public:
    //方法为：如果不匹配就push，匹配就pop，最终检查stack大小是否为0
    bool is_valid_bracket(string& s){
        stack<char> stack1;
        for (int i = 0; i < s.size(); ++i) {
            if (stack1.empty())
            {
                stack1.push(s[i]);
            }
            else if(stack1.top()=='('&&s[i]==')'){
                stack1.pop();
            }
            else if(stack1.top()=='['&&s[i]==']'){
                stack1.pop();
            }
            else if(stack1.top()=='{'&&s[i]=='}'){
                stack1.pop();
            }
            else{
                stack1.push(s[i]);
            }
        }
        return stack1.size() == 0 ? true: false;
    }
    bool is_valid_bracket_1(string& s){
        if (s.size() % 2 != 0) return false; // 如果s的长度为奇数，一定不符合要求
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') st.push(')');
            else if (s[i] == '{') st.push('}');
            else if (s[i] == '[') st.push(']');
                // 第三种情况：遍历字符串匹配的过程中，栈已经为空了，没有匹配的字符了，说明右括号没有找到对应的左括号 return false
                // 第二种情况：遍历字符串匹配的过程中，发现栈里没有我们要匹配的字符。所以return false
            else if (st.empty() || st.top() != s[i]) return false;
            else st.pop(); // st.top() 与 s[i]相等，栈弹出元素
        }
        // 第一种情况：此时我们已经遍历完了字符串，但是栈不为空，说明有相应的左括号没有右括号来匹配，所以return false，否则就return true
        return st.empty();
    }
};
int main(){
    string s = "()[]{}";
    Solution sl;
    string result = sl.is_valid_bracket(s) == false?"false":"true";
    cout<<result;

    s = "([)]";
    result = sl.is_valid_bracket(s) == false?"false":"true";
    cout<<result;
}
