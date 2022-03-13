//
// Created by bhc on 2022/3/11.
//

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode ** curr=&root;
        while(*curr){
            if((*curr)->val>key){
                curr=&(*curr)->left;
            }
            else if ((*curr)->val<key){
                curr=&(*curr)->right;
            }
            else{
                break;
            }
        }
        if(!*curr){
            return root;
        }
        TreeNode ** minMaxNode=curr;
        if((*minMaxNode)->right){
            minMaxNode=&(*minMaxNode)->right;
        }
        else{
            *minMaxNode=(*minMaxNode)->left;
            return root;
        }
        while((*minMaxNode)->left){
            minMaxNode=&(*minMaxNode)->left;
        }
        (*curr)->val=(*minMaxNode)->val;
        *minMaxNode=(*minMaxNode)->right;
        return root;
    }
};