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
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root){
            if(root->val>val){
                root=root->left;
            }
            else if (root->val<val){
                root=root->right;
            }
            else{
                return root;
            }
        }
        return nullptr;
    }
};