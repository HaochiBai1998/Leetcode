
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
#include<math.h>
#include<unordered_set>
#include<queue>
using namespace std;
class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        if(!root){
            return root;
        }
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            Node* prev;
            for(int i=0;i<n;++i){
                Node * node=q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
                if(i==0){
                    prev=node;
                    continue;
                }
                prev->next=node;
                prev=node;
                
            }
        }
        return root;
    }
};