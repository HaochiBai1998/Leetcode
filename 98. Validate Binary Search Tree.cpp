
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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    //recursion
    bool helper(TreeNode * node, long left,long right){
        if(!node){
            return true;
        }
        if(node->val<=left||node->val>=right){
            return false;
        }
        return helper(node->left,left,node->val)&helper(node->right,node->val,right);
    }
    bool isValidBST(TreeNode* root) {
        return helper(root->left,LONG_MIN,root->val)& helper(root->right,root->val,LONG_MAX);
    }
    //inorder traversal
    bool dfs(TreeNode * node,long & val){
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
};