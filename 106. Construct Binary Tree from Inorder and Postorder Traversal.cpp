//
// Created by bhc on 2022/2/26.
//
#include <vector>
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
    int finder(vector<int>& inorder, int left,int right, int target){
        for(int i=left;i<=right;++i){
            if(inorder[i]==target){
                return i;
            }
        }
        return -1;
    }
    void helper(vector<int>& inorder,int i_left,int i_right,
                vector<int>& postorder,int p_left,int p_right,TreeNode ** node_ptr){
        if(i_right<i_left){
            return ;
        }
        if(i_right-i_left==0){
            *node_ptr=new TreeNode(inorder[i_left]);
            return ;
        }
        * node_ptr = new TreeNode(postorder[p_right]);
        int index=finder(inorder,i_left,i_right,postorder[p_right]);
        int left_length=index-i_left;
        helper(inorder,i_left,index-1,postorder,p_left,p_left+left_length-1,&(*node_ptr)->left);
        helper(inorder,index+1,i_right,postorder,p_left+left_length,p_right-1,&(*node_ptr)->right);
        return;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode * root = nullptr;
        TreeNode ** root_ptr= & root;
        int i_tail=inorder.size()-1;
        int p_tail=postorder.size()-1;
        helper(inorder,0,i_tail,postorder,0,p_tail,root_ptr);
        return root;
    }
};