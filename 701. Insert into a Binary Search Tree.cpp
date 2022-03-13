//
// Created by bhc on 2022/3/11.
//

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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            return root=new TreeNode (val);
        }
        TreeNode ** node_ptr=&root;
        while(*node_ptr!=nullptr){
            if((*node_ptr)->val>val){
                node_ptr=&(*node_ptr)->left;
            }
            else if((*node_ptr)->val<val){
                node_ptr=&(*node_ptr)->right;
            }
            else{
                return root;
            }
        }
        *node_ptr=new TreeNode(val);
        return root;
    }
};