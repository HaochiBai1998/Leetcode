#include<queue>
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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> que;
        if(!root){
            return 0;
        }
        que.push(root);
        TreeNode* leftMost=nullptr;
        while(!que.empty()){
            int n=que.size();
            for(int i=0;i<n;++i){
                TreeNode * curr=que.front();
                que.pop();
                if(i==0){
                    leftMost=curr;
                }
                if(curr->left){
                    que.push(curr->left);
                }
                if(curr->right){
                    que.push(curr->right);
                }
            }
        }
        return leftMost->val;
    }
};