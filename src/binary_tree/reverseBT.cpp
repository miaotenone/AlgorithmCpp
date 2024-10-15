//
// Created by 14771 on 2024/10/13.
//
#include "../utils/common_ds.h"

class Solution{
public:
    //level order
    TreeNode* reverseBT(TreeNode* root){
        queue<TreeNode*> que;
        if (root!=NULL){que.push(root);}
        while (!que.empty()){
            TreeNode* node = que.front();
            que.pop();
            if (node->left){que.push(node->left);}
            if (node->right){que.push(node->right);}
            TreeNode* temp = node->right;
            node->right = node->left;
            node->left = temp;
        }
        return root;
    }
    //mark NULL ---preorder
    TreeNode* reverseBT_pre(TreeNode* root){
        stack<TreeNode*> st;
        if (root!=NULL){st.push(root);}
        while (!st.empty()){
            TreeNode* node = st.top();
            if (node!=NULL){
                st.pop();
                if (node->right){st.push(node->right);}
                if (node->left){st.push(node->left);}

                st.push(node);
                st.push(NULL);
            }
            else{
                st.pop();
                node = st.top();
                TreeNode* temp = node->right;
                node->right = node->left;
                node->left = temp;
                st.pop();
            }
        }
        return root;
    }
    //postorder---original iterator
    TreeNode* reverseBT_post(TreeNode* root){
        stack<TreeNode*> st;
        if (root!=NULL){st.push(root);}
        while (!st.empty()){
            TreeNode* node = st.top();
            st.pop();
            if (node->right){st.push(node->right);}
            if (node->left){st.push(node->left);}
            TreeNode* temp = node->right;
            node->right = node->left;
            node->left = temp;
        }
        return root;
    }
    //recursion preorder
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return root;
        swap(root->left, root->right);  // 中
        invertTree(root->left);         // 左
        invertTree(root->right);        // 右
        return root;
    }
    TreeNode* reverseBT_recursion_pre(TreeNode* root){
        preorder(root);
        return root;
    }
    void preorder(TreeNode* node){
        if (node== nullptr){ return;}
        TreeNode* temp = node->left;
        node->left = node->right;
        node->right = temp;
        if (node->left){ preorder(node->left);}
        if (node->right){ preorder(node->right);}
    }
    //inorder----recursion
    TreeNode* reverseBT_inorder(TreeNode* root){
        if (root == NULL) return root;
        invertTree(root->left);         // 左
        swap(root->left, root->right);  // 中
        invertTree(root->left);         // 注意 这里依然要遍历左孩子，因为中间节点已经翻转了
        return root;
    }
};

int main(){
    string s = "3,9,20,8,4,15,7";
    TreeNode* head = parse_tree(s);
    cout<<to_string(head)<<endl<<endl;
    Solution sl;

    sl.reverseBT(head);
    string s_bt = to_string(head);
    cout<<s_bt<<endl;

    sl.reverseBT_pre(head);
    s_bt = to_string(head);
    cout<<s_bt<<endl;

    sl.reverseBT_recursion_pre(head);
    s_bt = to_string(head);
    cout<<s_bt<<endl;

    sl.reverseBT_inorder(head);
    s_bt = to_string(head);
    cout<<s_bt<<endl;
}
