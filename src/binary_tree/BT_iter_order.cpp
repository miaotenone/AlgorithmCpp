//
// Created by 14771 on 2024/10/13.
//
#include "../utils/common_ds.h"
class Solution{
public:
    vector<int> preorderTraversal(TreeNode* root){
       stack<TreeNode*> st;
       vector<int> re;
        if (root!=NULL){st.push(root);}
        while (!st.empty()){
            TreeNode* temp = st.top();
            st.pop();
            re.push_back(temp->val);
            if (temp->right){st.push(temp->right);}
            if (temp->left){st.push(temp->left);}
        }
        return re;
    }
    vector<int> inorderTraversal(TreeNode* root){
        stack<TreeNode*> st;
        vector<int> re;
        if (root== nullptr){return re;}
        TreeNode* node = root;
        while (!st.empty()||node!= nullptr){
            if (node!= nullptr){
                st.push(node);
                node = node->left;
            }
            else{
                TreeNode* cur = st.top();
                re.push_back(cur->val);
                st.pop();
                node = cur->right;
            }
        }
        return re;
    }
    vector<int> postorderTraversal(TreeNode* root){
        stack<TreeNode*> st;
        vector<int> re;
        if (root!=NULL){st.push(root);}
        while (!st.empty()){
            TreeNode* temp = st.top();
            st.pop();
            re.push_back(temp->val);
            if (temp->left){st.push(temp->left);}
            if (temp->right){st.push(temp->right);}
        }
        reverse(re.begin(),re.end());
        return re;
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
