//
// Created by bhc on 2022/2/23.
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
    //迭代写法
    vector<int> inorderTraversal(TreeNode *root) {
        stack<TreeNode *> s;
        vector<int> ans;
        TreeNode *curr = root;
        while (curr || !s.empty()) {
            if (curr) {
                s.push(curr);
                curr = curr->left;
            } else {
                curr = s.top();
                ans.push_back(curr->val);
                curr = curr->right;
                s.pop();
            }
        }
        return ans;
    }
};