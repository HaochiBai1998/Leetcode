//
// Created by bhc on 2022/2/26.
//
#include<vector>
#include<stack>
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

    //单调栈O(n) 解法！！
    TreeNode* constructMaximumBinaryTree(std::vector<int>& nums) {
        stack<TreeNode*> nodes;
        TreeNode* currNode = nullptr;
        for(int num:nums){
            currNode = new TreeNode (num);
            TreeNode * tmp=nullptr;
            while(!nodes.empty()&&nodes.top()->val<currNode->val){
                TreeNode * top=nodes.top();
                nodes.pop();
                if(!tmp){
                    tmp=top;
                }
                else{
                    top->right=tmp;
                    tmp=top;
                }
            }
            currNode->left=tmp;
            nodes.push(currNode);
        }
        TreeNode * root=nodes.top();
        nodes.pop();
        while(!nodes.empty()){
            TreeNode * node =nodes.top();
            nodes.pop();
            node->right=root;
            root=node;
        }
        return root;
    }
    //O(nlogn)分治解法
    int findMax(vector<int> & nums,int left,int right){
        int M_index=-1;
        int M = INT_MIN;
        for(int i=left;i<=right;++i){
            if(nums[i]>M){
                M_index=i;
                M=nums[i];
            }
        }
        return M_index;
    }
    void helper(vector<int> & nums,int left,int right, TreeNode ** node_ptr){
        if(left>right){
            return;
        }
        if(left==right){
            * node_ptr= new TreeNode ( nums[left]);
            return ;
        }
        int index=findMax(nums,left,right);
        * node_ptr = new TreeNode (nums[index]);
        helper(nums,left,index-1,&(*node_ptr)->left);
        helper(nums,index+1,right,&(*node_ptr)->right);
        return;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode * root=nullptr;
        TreeNode ** root_ptr=&root;
        int n=nums.size();
        helper(nums,0,n-1,root_ptr);
        return root;
    }
};