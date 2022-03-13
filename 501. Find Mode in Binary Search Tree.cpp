//
// Created by bhc on 2022/3/11.
//
#include<vector>
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
using namespace std;
class Solution {
    int maxCounter;
    int counter;
    vector<int> ans;
public:
    void traverse(TreeNode * node,int & curr){
        if(node==nullptr){
            return;
        }
        traverse(node->left,curr);
        if(curr==node->val){
            counter++;
        }
        else{
            counter=1;
        }
        if(counter==maxCounter){
            ans.push_back(node->val);
        }
        else if(counter>maxCounter){
            ans.clear();
            ans.push_back(node->val);
        }
        maxCounter=max(maxCounter,counter);
        curr=node->val;
        traverse(node->right,curr);
    }
    vector<int> findMode(TreeNode* root) {
        maxCounter=0;
        counter=0;
        int curr=-1;
        traverse(root,curr);
        return ans;
    }
};