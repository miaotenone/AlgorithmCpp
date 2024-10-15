//
// Created by 14771 on 2024/10/15.
//给定一个二叉树，返回所有从根节点到叶子节点的路径。
//说明: 叶子节点是指没有子节点的节点。
#include "../utils/common_ds.h"

class Solution {
public:
    //preorder
    vector<string> findAllPaths(TreeNode* root){
        vector<string> result;
        vector<int> path;
        if (root == nullptr){return result;}
        traversal(root,path,result);
        return result;
    }
    vector<string> findAllPathsHide(TreeNode* root){
        vector<string> result;
        string path = "";
        if (root == nullptr){return result;}
        traversalHide(root,path,result);
        return result;
    }
private:
    //backTracking
    void traversal(TreeNode* node,vector<int>& paths,vector<string>& result){
        paths.push_back(node->val);//central
        if (node->right==NULL&&node->left==NULL){
            string path = "";
            for (int i = 0; i < paths.size()-1; ++i) {
                path += to_string(paths[i]);
                path += "->";
            }
            path += to_string(paths[paths.size()-1]);
            result.push_back(path);
        }
        if (node->left){
            traversal(node->left,paths,result);
            paths.pop_back();
        }
        if (node->right){
            traversal(node->right,paths,result);
            paths.pop_back();
        }

    }
    void traversalHide(TreeNode* node,string path,vector<string>& result){
        path += to_string(node->val);
        if (node->right==NULL&&node->left==NULL){
            result.push_back(path);
        }
        if (node->left){ traversalHide(node->left,path+"->",result);}
        if (node->right){ traversalHide(node->right,path+"->",result);}
    }
};

int main() {
    string st = "3,9,20,null,null,15,7";
    TreeNode *heads = parse_tree(st);
    cout << to_string(heads) << endl << endl;
    Solution sl;

    vector<string> res = sl.findAllPaths(heads);
    for(auto x : res){
        cout<<x<<endl;
    }

    res = sl.findAllPathsHide(heads);
    for(auto x : res){
        cout<<x<<endl;
    }
};