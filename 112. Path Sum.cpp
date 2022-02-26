//
// Created by bhc on 2022/2/26.
//

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
    bool dfs(TreeNode* node, int targetSum){
        int remain = targetSum-node->val;
        if(!node->left&&!node->right){
            if(remain==0){
                return true;
            }
            else{
                return false;
            }
        }
        bool result=false;
        if(node->left){
            result =result | dfs(node->left,remain);
        }
        if (node->right){
            result =result | dfs(node->right,remain);
        }
        return result ;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root){
            return false;
        }
        return dfs(root,targetSum);
    }
};