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
    //another solution: find the depth of tree, dfs (node node->right node->left)
    //bfs 
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode *> q;
        vector<int> ans;
        if(!root){
            return ans;
        }
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;++i){
                TreeNode * node=q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
                if(i==n-1){
                    ans.push_back(node->val);
                }
            }
        }
        return ans;
    }
};