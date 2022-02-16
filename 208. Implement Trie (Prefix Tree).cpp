//
// Created by bhc on 2022/2/9.
//

#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
#include<set>
#include<queue>
#include<unordered_map>
using namespace std;

class TreeNode{
public:
    string val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(string val,TreeNode* left,TreeNode* right):val(val),left(left),right(right){}
    TreeNode(string val):val(val),left(nullptr),right(nullptr){}
};

class Trie {
    TreeNode * root;
public:
    Trie():root(nullptr) {}
    void insert(string word) {
        TreeNode** ptr=&root;
        while(*ptr!= nullptr){
            if((*ptr)->val>word){
                ptr=&(*ptr)->left;
            }
            else{
                ptr=&(*ptr)->right;
            }
        }
        *ptr=new TreeNode(word);
    }

    bool search(string word) {
        TreeNode * curr =root;
        while(!curr){
            if(curr->val>word){
                curr=curr->left;
            }
            else if (curr->val<word){
                curr=curr->right;
            }
            else{
                return true;
            }
        }
        return false;
    }
    bool startsWith(string prefix) {

    }
};