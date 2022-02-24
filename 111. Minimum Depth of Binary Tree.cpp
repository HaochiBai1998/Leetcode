//
// Created by bhc on 2022/2/24.
//
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
    //层序遍历

    int minDepth(TreeNode* root) {
        queue<TreeNode *> q;
        if(!root){
            return 0;
        }
        q.push(root);
        int counter=1;
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;++i){
                TreeNode * node =q.front();
                q.pop();
                if(!node->left&&!node->right){
                    return counter;
                }
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            ++counter;
        }
        return 0;
    }
};