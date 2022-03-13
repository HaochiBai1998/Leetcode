//
// Created by bhc on 2022/2/28.
//
#include<math.h>
#include<algorithm>
#include<limits.h>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
    int minDiff;
public:
    void helper(TreeNode * node,int & curr){
        if(!node){
            return;
        }
        helper(node->left,curr);
        if(curr!=-1){
            minDiff=min(minDiff,node->val-curr);
        }
        curr=node->val;
        helper(node->right,curr);
    }
    int getMinimumDifference(TreeNode* root) {
        minDiff=INT_MAX;
        int curr=-1;
        helper(root,curr);
        return minDiff;
    }
};