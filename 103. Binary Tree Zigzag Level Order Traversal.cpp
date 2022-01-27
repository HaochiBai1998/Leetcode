
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
    int level;
    TreeNode * node;
public:
    //bfs solution
    void bfs(TreeNode* root,vector<vector<int>> &ans){
        queue<TreeNode*> nodes;
        nodes.push(root);
        int direction=true;
        int level=0;
        while(!nodes.empty()){
            int n=nodes.size();
            deque<int> nums;
            for(int i=0;i<n;++i){        
                TreeNode * node=nodes.front();
                nodes.pop();
                if(!direction){
                    nums.push_front(node->val);
                }
                else{
                    nums.push_back(node->val);
                }
                if(node->left){
                    nodes.push(node->left);
                } 
                if(node->right){
                    nodes.push(node->right);
                }
            }   
            ans.emplace_back(vector<int>{nums.begin(),nums.end()});
            direction=!direction;
        }        
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==nullptr){
            return ans;
        }
        bfs(root,ans);
        return ans;
    }
    //dfs Solution
    void dfs(int & size,vector<vector<int>> &ans){
        if(size<level){
            ans.emplace_back(vector<int>());
            size++;
        }
        ans[level].emplace_back(node->val);
        TreeNode* tmp=node;
        if(node->left!=nullptr){
            node=node->left;
            level++;
            dfs(size,ans);
            level--;
            node=tmp;
        }
        if(node->right!=nullptr){
            node=node->right;
            level++;
            dfs(size,ans);
            level--;
            node=tmp;
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==nullptr){
            return ans;
        }
        int size=-1;
        node=root;
        level=0;
        dfs(size,ans);
        for(int i=1;i<=size;i=i+2){
            reverse(ans[i].begin(),ans[i].end());
        }
        return ans;
    }
};