//
// Created by 14771 on 2024/10/11.
//
//--------------层序遍历-广度优先搜索------------------------
//
#include "../utils/common_ds.h"

class Solution{
public:
    //给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。
    vector<vector<int>> levelOrder_queue(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> result;
        if (root != NULL) q.push(root);
        while (!q.empty()){
            int size = q.size();
            vector<int> temp;
            for (int i = 0; i < size; ++i) {
                TreeNode* treeNode = q.front();
                temp.push_back(treeNode->val);
                if (treeNode->left){q.push(treeNode->left);}
                if (treeNode->right){q.push(treeNode->right);}
                q.pop();
            }
            result.push_back(temp);
        }
        return result;
    }
    vector<vector<int>> levelOrder_recursion(TreeNode* root) {
        vector<vector<int>> result;
        order(root,result);
        return result;
    }
    void order(TreeNode* node,vector<vector<int>>& result,int depth = 0)
    {
        if (node == nullptr){ return;}
        if (result.size() == depth) result.push_back(vector<int>());
        result[depth].push_back(node->val);

        if (node->left){ order(node->left,result,depth+1);}
        if (node->right){ order(node->right,result,depth+1);}

    }

    //给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
    vector<int> right_view_queue(TreeNode* root){
        vector<int> result;
        queue<TreeNode*> q;
        if (root){q.push(root);}
        while (!q.empty()){
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* temp = q.front();
                q.pop();
                if (i==size-1){result.push_back(temp->val);}
                if (temp->left){q.push(temp->left);}
                if (temp->right){q.push(temp->right);}
            }
        }
        return result;
    }

    //给定一个非空二叉树, 返回一个由每层节点平均值组成的数组。
    vector<int> average_level(TreeNode* root){
        vector<int> res;
        queue<TreeNode*> q;
        if (root!=NULL){q.push(root);}
        while (!q.empty()){
            int size = q.size();
            int sum = 0;
            for (int i = 0; i < size; ++i) {
                TreeNode* temp = q.front();
                q.pop();
                sum += temp->val;
                if (temp->left){q.push(temp->left);}
                if (temp->right){q.push(temp->right);}
            }
            res.push_back(sum/size);
        }
        return res;
    }
};


int main(){
    string s = "3,9,20,null,null,15,7";
    TreeNode* head = parse_tree(s);
    Solution sl;
    vector<vector<int>> re = sl.levelOrder_queue(head);
    for(auto x : re){
        cout<<x<<endl;
    }
    re = sl.levelOrder_recursion(head);
    for(auto x : re){
        cout<<x<<endl;
    }
    vector<int> res = sl.right_view_queue(head);
    cout<<res;

    res = sl.average_level(head);
    cout<<res;

}


