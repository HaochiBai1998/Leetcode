//
// Created by bhc on 2022/2/16.
//
#include<algorithm>
#include<unordered_map>
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

class Solution {
    unordered_map<TreeNode *,int> hashtable;
public:
    int rob(TreeNode* root) {
        if(!root){
            return 0;
        }
        if(hashtable.count(root)){
            return hashtable[root];
        }
        int M=rob(root->left)+rob(root->right);
        int M_next=0;
        if(root->left){
            M_next+=rob(root->left->left)+rob(root->left->right);
        }
        if(root->right){
            M_next+=rob(root->right->left)+rob(root->right->right);
        }
        M_next+=root->val;
        hashtable[root]=max(M,M_next);
        return hashtable[root];
    }
};