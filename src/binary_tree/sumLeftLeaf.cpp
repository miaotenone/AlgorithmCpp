//
// Created by 14771 on 2024/10/15.
//计算给定二叉树的所有左叶子之和。
//左叶子的明确定义：节点A的左孩子不为空，且左孩子的左右孩子都为空（说明是叶子节点），那么A节点的左孩子为左叶子节点
#include "../utils/common_ds.h"

class Solution {
public:
    int sumLeftLeaf(TreeNode* root){

    }
};

int main(){
    string st = "3,9,20,null,null,15,7";
    TreeNode *heads = parse_tree(st);
    cout << to_string(heads) << endl << endl;
    Solution sl;

    cout<<sl.sumLeftLeaf(heads)<<endl;
}