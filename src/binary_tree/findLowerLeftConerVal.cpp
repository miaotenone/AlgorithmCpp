//
// Created by 14771 on 2024/10/15.
//
#include "../utils/common_ds.h"

class Solution {
public:
    int sumLeftLeaf(TreeNode* root){

    }
};

int main(){
    string st = "3,9,20,null,null,15,7";
    TreeNode *heads = parse_tree(st);
    cout << to_string(heads) << endl << endl;
    Solution sl;

    cout<<sl.sumLeftLeaf(heads)<<endl;
}
