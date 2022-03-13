//
// Created by bhc on 2022/3/13.
//
#include<vector>

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
    TreeNode * root;
public:
    void helper(vector<int> & nums,int left, int right, TreeNode ** node_ptr){
        if(left>right){
            return;
        }
        int mid = (left+right)/2;
        * node_ptr = new TreeNode(nums[mid]);
        helper(nums,left,mid-1,&(*node_ptr)->left);
        helper(nums,mid+1,right,&(*node_ptr)->right);
    }
    TreeNode * sortedArrayToBST(vector<int>& nums) {
        root=nullptr;
        TreeNode ** node_ptr=&root;
        helper(nums,0,nums.size()-1,node_ptr);
        return root;
    }
};