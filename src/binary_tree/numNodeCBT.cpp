//
// Created by 14771 on 2024/10/15.
//给出一个完全二叉树，求出该树的节点个数。
// 输入：root = [1,2,3,4,5,6]
//输出：6
#include "../utils/common_ds.h"

class Solution {
public:
    int countNumL(TreeNode* root){
        queue<TreeNode*> que;
        int num = 0;
        if (root!=NULL){que.push(root);}
        while (!que.empty()){
            TreeNode* temp = que.front();
            num++;que.pop();
            if (temp->left){que.push(temp->left);}
            if (temp->right){que.push(temp->right);}
        }
        return num;
    }
    //count num same as counting depth
    int countNumR(TreeNode* node){
        if (node==NULL){return 0;}
        return 1+ countNumR(node->left)+ countNumR(node->right);
    }
    //add the method of full binary tree
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        int leftDepth = 0, rightDepth = 0; // 这里初始为0是有目的的，为了下面求指数方便
        while (left) {  // 求左子树深度
            left = left->left;
            leftDepth++;
        }
        while (right) { // 求右子树深度
            right = right->right;
            rightDepth++;
        }
        if (leftDepth == rightDepth) {
            return (2 << leftDepth) - 1; // 注意(2<<1) 相当于2^2，所以leftDepth初始为0
        }
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};

int main(){
    string s = "3,9,20,null,null,15,7";
    TreeNode* head = parse_tree(s);
    cout<<to_string(head)<<endl<<endl;
    Solution sl;

    cout<<sl.countNumL(head)<<endl;
    cout<<sl.countNumR(head)<<endl;
}