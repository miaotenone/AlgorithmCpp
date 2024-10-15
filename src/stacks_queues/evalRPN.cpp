//
// Created by 14771 on 2024/10/9.
//根据 逆波兰表示法，求表达式的值。
//有效的运算符包括 + ,  - ,  * ,  / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。
//整数除法只保留整数部分。 给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。
//示例 1：
//输入: ["2", "1", "+", "3", "*"]
//输出: 9
//解释: 该算式转化为常见的中缀算术表达式为：((2 + 1) * 3) = 9
//示例 2：
//输入: ["4", "13", "5", "/", "+"]
//输出: 6
//解释: 该算式转化为常见的中缀算术表达式为：(4 + (13 / 5)) = 6
//示例 3：
//输入: ["10", "6", "9", "3", "+", "-11", " * ", "/", " * ", "17", "+", "5", "+"]
//输出: 22
#include "../utils/common_ds.h"

class Solution{
public:
    int evalRPN(vector<string>& tokens){
        stack<int> st;
        for (int i = 0; i < tokens.size(); ++i) {
            if (tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/")
            {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                if (tokens[i]=="+"){st.push(a+b);}
                if (tokens[i]=="-"){st.push(a-b);}
                if (tokens[i]=="*"){st.push(a*b);}
                if (tokens[i]=="/"){st.push(a/b);}
            }
            else{
                st.push(std::stoi(tokens[i]));
            }
        }
        return st.top();

    }
};
int main(){
    Solution sl;
    vector<string> tokens = {"2", "1", "+", "3", "*"};
    cout<<sl.evalRPN(tokens);
}