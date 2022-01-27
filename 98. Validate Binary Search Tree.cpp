
#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
#include<math.h>
#include<unordered_set>
#include<queue>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    //inorder traversalbool 
    dfs(TreeNode * node,long & val){
        if(node==nullptr){
            return true;
        }
        bool leftValid=dfs(node->left,val);
        if(val>=node->val){
            return false;
        }
        val=node->val;
        bool rightValid= dfs(node->right,val);
        return leftValid&rightValid;
    }
    bool isValidBST(TreeNode* root) {
        long val=LONG_MIN;
        return dfs(root,val);
    }
    //recursion solution
     bool dfs(long left,long right,TreeNode* node){
        if(node==nullptr){
            return true;
        }
        if(node->val<=left||node->val>=right){
            return false;
        }
        return dfs(left,node->val,node->left)&dfs(node->val,right,node->right);
    }
    bool isValidBST(TreeNode* root) {
        long left=LONG_MIN;
        long right=LONG_MAX;
        return dfs(left,right,root);
    }
};