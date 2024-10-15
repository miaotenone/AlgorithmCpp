//
// Created by 14771 on 2024/10/13.
// NULL Mark
#include "../utils/common_ds.h"
class Solution{
public:
    vector<int> preorderTraversal(TreeNode* root){
        stack<TreeNode*> st;
        vector<int> re;
        if (root!=NULL){st.push(root);}
        while (!st.empty()){
            TreeNode* temp = st.top();
            if(temp!=NULL){
                st.pop();
                if (temp->right){st.push(temp->right);}
                if (temp->left){st.push(temp->left);}

                st.push(temp);
                st.push(NULL);
            }
            else{
                st.pop();
                temp = st.top();
                st.pop();
                re.push_back(temp->val);
            }
        }
        return re;
    }
    vector<int> inorderTraversal(TreeNode* root){
        stack<TreeNode*> st;
        vector<int> re;
        if (root!=NULL){st.push(root);}
        while (!st.empty()){
            TreeNode* temp = st.top();
            if(temp!=NULL){
                st.pop();
                if (temp->right){st.push(temp->right);}
                st.push(temp);
                st.push(NULL);
                if (temp->left){st.push(temp->left);}
            }
            else{
                st.pop();
                temp = st.top();
                st.pop();
                re.push_back(temp->val);
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
            if(temp!=NULL){
                st.pop();
                st.push(temp);
                st.push(NULL);
                if (temp->right){st.push(temp->right);}
                if (temp->left){st.push(temp->left);}
            }
            else{
                st.pop();
                temp = st.top();
                st.pop();
                re.push_back(temp->val);
            }
        }
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
