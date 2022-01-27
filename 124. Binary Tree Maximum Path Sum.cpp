
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
    int global_max;
public:
    int helper(TreeNode* node){
        if(node==nullptr){
            return -1000;
        }
        int left_max=helper(node->left);
        int right_max=helper(node->right);
        int num=node->val;
        global_max=max(global_max,max(left_max,max(right_max,left_max+right_max+num)));
        return max(max(left_max,right_max),0)+num;
    }
    int maxPathSum(TreeNode* root) {
        global_max=-1000;
        global_max=max(global_max,helper(root));
        return global_max;
    }
};