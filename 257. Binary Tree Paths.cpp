//
// Created by bhc on 2022/2/24.
//

#include<vector>
#include<string>
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
    vector<int> path;
    vector<string> ans;
public:
    void printPath(vector<int> & path){
        string str="";
        for(int i=0;i<path.size();++i){
            if(i!=0){
                str+="->";
            }
            str+=to_string(path[i]);
        }
        ans.push_back(str);
    }
    void dfs(TreeNode * node){
        if(!node->left&&!node->right){
            path.push_back(node->val);
            printPath(path);
            path.pop_back();
            return;
        }
        if(node->left){
            path.push_back(node->val);
            dfs(node->left);
            path.pop_back();
        }
        if(node->right){
            path.push_back(node->val);
            dfs(node->right);
            path.pop_back();
        }
        return ;

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root);
        return ans;
    }
};