
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
    TreeNode* curr;
    int M;
    int ans;
public:
    void dfs(TreeNode * node){
        if(node->val>=M){
            ++ans;
        }
        int tmp=M;
        M=max(M,node->val);
        if(node->left!=NULL){
            dfs(node->left);
        }
        if(node->right!=NULL){ 
            dfs(node->right);
        }
        M=tmp;
        return;
    }
    int goodNodes(TreeNode* root) {
        ans=0;
        M=-10000;
        dfs(root);
        return ans;
    }
};