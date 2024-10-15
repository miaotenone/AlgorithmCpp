//
// Created by 14771 on 2024/10/13.
//给定一个二叉树，检查它是否是镜像对称的。
#include "../utils/common_ds.h"

class Solution {
public:
    //recursion
    bool symmetricalBT(TreeNode* root){
        if (root==NULL){return true;}
        return compare(root->left,root->right);
    }
    bool compare(TreeNode* left,TreeNode* right){
        if (right!=NULL && left==NULL){ return false;}
        if( right == NULL && left != NULL){ return false;}
        if( right != NULL&&left!=NULL&&right->val!=left->val){ return false;}
        if (right==NULL&&left==NULL){ return true;}

        bool outside = compare(left->left,right->right);
        bool inside = compare(left->right,right->left);

        return outside && inside;
    }

    //traversal--queue/stack(level/pre/in/post--similar)
    bool symmetricalBT_q(TreeNode* root){
        queue<TreeNode*> que;
        if (root==NULL){return true;}
        que.push(root->left);
        que.push(root->right);
        while (!que.empty()){
            TreeNode* right = que.front();
            que.pop();
            TreeNode* left = que.front();
            que.pop();

            if (right!=NULL&& left==NULL){return false;}
            if(right ==NULL && left != NULL){return false;}
            if(right!=NULL&&left!=NULL&&right->val!=left->val){return false;}
            if (right==NULL&&left==NULL){ continue;}

            que.push(right->right);
            que.push(left->left);
            que.push(right->left);
            que.push(left->right);
        }
        return true;
    }
    bool symmetricalBT_s(TreeNode* root){
        stack<TreeNode*> st;
        if (root==NULL){return true;}
        st.push(root->left);
        st.push(root->right);
        while (!st.empty()){
            TreeNode* right = st.top();
            st.pop();
            TreeNode* left = st.top();
            st.pop();

            if(right!=NULL&& left==NULL){return false;}
            if(right ==NULL && left != NULL){return false;}
            if(right!=NULL&&left!=NULL&&right->val!=left->val){return false;}
            if(right==NULL&&left==NULL){ continue;}

            st.push(right->left);
            st.push(left->right);
            st.push(right->right);
            st.push(left->left);
        }
        return true;
    }
};


int main(){
    string s = "3,9,9,8,4,4,8";
    TreeNode* head = parse_tree(s);
    cout<<to_string(head)<<endl<<endl;
    Solution sl;

    string res = sl.symmetricalBT_q(head)== true?"true":"false";
    cout<<res<<endl;

    res = sl.symmetricalBT_s(head)== true?"true":"false";
    cout<<res<<endl;

    res = sl.symmetricalBT(head)== true?"true":"false";
    cout<<res<<endl;
}