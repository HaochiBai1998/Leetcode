
#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
#include<math.h>
#include<unordered_set>
using namespace std;


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> helper(int begin,int end){
        if (begin > end) {
            return { NULL };
        }
        vector<TreeNode *> ans;
        for(int i=begin;i<=end;i++){
            vector<TreeNode *> left=helper(begin,i-1);
            vector<TreeNode *> right=helper(i+1,end);
            for(auto& it1:left){
                for(auto& it2:right){
                    TreeNode * head= new TreeNode(i);
                    head->left=it1;
                    head->right=it2;
                    ans.push_back(head);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        return helper(1,n);
    }
};