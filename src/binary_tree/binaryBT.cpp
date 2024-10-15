//
// Created by 14771 on 2024/10/15.
//
#include "../utils/common_ds.h"

class Solution{
public:
    //postorder
    bool isBBT(TreeNode* root){
        if (root==NULL) return true;
        int differ = 0;
        differDepthVal(root,differ);
        if (differ>1){return false;}
        return true;
    }
    int differDepthVal(TreeNode* node,int& differ){
        if (node==NULL){return 0;}
        int depthl = differDepthVal(node->left,differ);
        int depthr = differDepthVal(node->right,differ);
        differ = max(abs(depthl-depthr),differ);
        return max(depthr,depthl)+1;
    }
    //official version
    bool is_BBT_OV(TreeNode* root){
        int result = getHeight(root);
        return result==-1 ? false: true;
    }
    int getHeight(TreeNode* node){
        if (node == NULL) {
            return 0;
        }
        int lHeight = getHeight(node->left);
        int rHeight = getHeight(node->right);
        if (lHeight==-1||rHeight==-1){return -1;}
        return abs(rHeight-lHeight)>1?-1:1+max(lHeight,rHeight);
    }
};

int main(){
    string st = "3,9,20,null,null,15,7";
    TreeNode* heads = parse_tree(st);
    cout<<to_string(heads)<<endl<<endl;
    string sf = "1,2,2,3,3,null,null,4,4";
    TreeNode* headf = parse_tree(sf);
    cout<<to_string(headf)<<endl<<endl;

    Solution sl;
    string res = sl.isBBT(heads)?"true":"false";
    cout<<res<<endl;

    res = sl.isBBT(headf)?"true":"false";
    cout<<res<<endl;

    res = sl.is_BBT_OV(heads)?"true":"false";
    cout<<res<<endl;

    res = sl.is_BBT_OV(headf)?"true":"false";
    cout<<res<<endl;
}
