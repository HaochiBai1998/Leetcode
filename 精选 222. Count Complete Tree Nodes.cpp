//
// Created by bhc on 2022/2/24.
//
#include<stack>
#include<algorithm>
#include<math.h>
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
    //二分搜索查看是否存在节点
    int getDepth(TreeNode * node){
        if(!node){
            return 0;
        }
        return max(getDepth(node->left),getDepth(node->right))+1;
    }
    bool exist(int index,TreeNode * node){
        stack<int> s;
        while(index!=1){
            if(index%2){
                s.push(1);
            }
            else{
                s.push(0);
            }
            index/=2;
        }
        if(node==nullptr){
            return false;
        }
        int n=s.size();
        for(int i=0;i<n;++i){
            int direction=s.top();
            s.pop();
            if(direction){
                node=node->right;
            }
            else{
                node=node->left;
            }
            if(node==nullptr){
                return false;
            }
        }
        return true;
    }
    int countNodes(TreeNode* root) {
        if(!root){
            return 0;
        }
        int depth = getDepth(root);
        int tail=pow(2,depth)-1;
        int head=pow(2,depth-1);
        int M=head;
        while(head<=tail){
            int mid=(tail+head)/2;
            if(exist(mid,root)){
                M=max(M,mid);
                head=mid+1;
            }
            else{
                tail=mid-1;
            }
        }
        return M;
    }
};