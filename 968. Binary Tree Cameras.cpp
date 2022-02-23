//
// Created by bhc on 2022/2/23.
//
#include<unordered_map>
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
    unordered_map<TreeNode * ,TreeNode*> hashTable;
    unordered_map<TreeNode * ,bool> monitered;
    int counter;
public:
    //贪心解法，从底往上，没有孩子或孩子都被监控的节点其父节点或自己必须被监控
    void moniter(TreeNode * node){
        monitered[node]=true;
        monitered[hashTable[node]]=true;
        if(node->left){
            monitered[node->left]=true;
        }
        if(node->right){
            monitered[node->right]=true;
        }
        return ;
    }
    int getMoniterInfo(TreeNode * node){
        if(!node){
            return 0;
        }
        int counter=getMoniterInfo(node->left)+getMoniterInfo(node->right);
        if((!node->left||monitered[node->left])&&
           (!node->right||monitered[node->right])&&!monitered.count(node)){
            if(hashTable.count(node)){
                moniter(hashTable[node]);
            }
            else{
                moniter(node);
            }
            counter++;
        }
        return counter;
    }
    void getParentInfo(TreeNode * node){
        if(!node){
            return;
        }
        if(node->left){
            hashTable[node->left]=node;
            getParentInfo(node->left);
        }
        if(node->right){
            hashTable[node->right]=node;
            getParentInfo(node->right);
        }
    }
    int minCameraCover(TreeNode* root) {
        counter=0;
        getParentInfo(root);
        return getMoniterInfo(root);
    }
};