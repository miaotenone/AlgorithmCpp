//
// Created by 14771 on 2024/10/13.
//
#include "../utils/common_ds.h"
class Solution{
public:
    vector<int> preorderTraversal(TreeNode* root){
        vector<int> result;
        preorder(root,result);
        return result;
    }
    void preorder(TreeNode* node,vector<int>& result){
        if (node == nullptr){ return;}
        result.push_back(node->val);
        preorder(node->left,result);
        preorder(node->right,result);
    }
    vector<int> inorderTraversal(TreeNode* root){
        vector<int> result;
        inorder(root,result);
        return result;
    }
    void inorder(TreeNode* node,vector<int>& result){
        if (node == nullptr){ return;}
        preorder(node->left,result);
        result.push_back(node->val);
        preorder(node->right,result);
    }
    vector<int> postorderTraversal(TreeNode* root){
        vector<int> result;
        postorder(root,result);
        return result;
    }
    void postorder(TreeNode* node,vector<int>& result){
        if (node == nullptr){ return;}
        preorder(node->left,result);
        preorder(node->right,result);
        result.push_back(node->val);
    }
};

int main(){
    string s = "3,9,20,8,4,15,7";
    TreeNode* head = parse_tree(s);
    Solution sl;
    vector<int> result = sl.preorderTraversal(head);//3 9 8 4 20 15 7
    cout<<result;
    result = sl.inorderTraversal(head);//8 9 4 3 15 20 7
    cout<<result;
    result = sl.postorderTraversal(head);//8 4 9 15 7 20 3
    cout<<result;

}
