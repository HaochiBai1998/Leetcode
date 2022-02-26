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
    int sum;
public:
    void helper(TreeNode* node, int status ){
        if(!node){
            return;
        }
        if(!node->left&&!node->right&& status==-1){
            sum+=node->val;
        }
        helper(node->left,-1);
        helper(node->right,1);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        sum=0;
        helper(root,0);
        return sum;
    }
};