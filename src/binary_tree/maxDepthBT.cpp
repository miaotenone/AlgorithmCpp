//
// Created by 14771 on 2024/10/13.
//给定一个二叉树，找出其最大深度。
//二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
//说明: 叶子节点是指没有子节点的节点。
#include "../utils/common_ds.h"

class Solution {
public:
    int maxDepth(TreeNode* root){
        queue<TreeNode*> que;
        int depth = 0;
        if (root != NULL){que.push(root);}
        while (!que.empty()){
            int size = que.size();
            depth++;
            for (int i = 0; i < size; ++i) {
                TreeNode* node = que.front();
                que.pop();
                if (node->left){que.push(node->left);}
                if (node->right){que.push(node->right);}
            }
        }
        return depth;
    }
    //postorder
    int max_depth(TreeNode* node){
        if (node==NULL){return 0;}
        int depth_l = max_depth(node->left);
        int depth_r = max_depth(node->right);
        int depth = max(depth_r,depth_l)+1;
        return depth;
    }
    //preorder
    int maxVal(TreeNode* node,int depth = 1){
        if (node==NULL) return 0;
        if (node->right==NULL&&node->left==NULL){return depth;}
        int l=0,r=0;
        if (node->left){
            depth++;
            l = maxVal(node->left,depth);
            depth--;
        }
        if (node->right){
            depth++;
            r = maxVal(node->right,depth);
            depth--;
        }
        return max(l,r);
    }

};

int main(){
    string s = "3,9,4,null,null,4,8";
    TreeNode* head = parse_tree(s);
    cout<<to_string(head)<<endl<<endl;
    Solution sl;

    int res = sl.maxDepth(head);
    cout<<res<<endl;

    res = sl.max_depth(head);
    cout<<res<<endl;

    res = sl.maxVal(head);
    cout<<res<<endl;
}
