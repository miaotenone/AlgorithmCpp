//
// Created by 14771 on 2024/10/13.
//给定一个二叉树，找出其最小深度。
//最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
//说明: 叶子节点是指没有子节点的节点。
//示例:
//给定二叉树 [3,9,20,null,null,15,7],
#include "../utils/common_ds.h"

class Solution {
public:
    int minDepth(TreeNode* root){
        queue<TreeNode*> que;
        int depth = 0;
        if (root != NULL){que.push(root);}
        while (!que.empty()){
            int size = que.size();
            depth++;
            for (int i = 0; i < size; ++i) {
                TreeNode* node = que.front();
                que.pop();
                if (node->left== NULL&& node->right==NULL){ return depth;}
                if (node->left){que.push(node->left);}
                if (node->right){que.push(node->right);}
            }
        }
        return depth;
    }
    int minVal(TreeNode* node){
        if (node==NULL){return 0;}
        int depth_l = minVal(node->left);
        int depth_r = minVal(node->right);
        int min_depth = min(depth_l,depth_r)+1;
        return min_depth;
    }
};

int main(){
    string s = "3,9,20,null,null,15,7";
    TreeNode* head = parse_tree(s);
    cout<<to_string(head)<<endl<<endl;
    Solution sl;

    int res = sl.minVal(head);
    cout<<res<<endl;

    s = "3,9,9,8,4,4,8";
    head = parse_tree(s);
    cout<<to_string(head)<<endl<<endl;

    res = sl.minVal(head);
    cout<<res<<endl;
}