
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
    //O(1) space optimized
    Node* connect(Node* root) {
        if(root==nullptr){
            return root;
        }
        Node * head=root;
        while(head->left){
            Node * curr=head;
            while(curr){
                curr->left->next=curr->right;
                if(curr->next!=nullptr){
                    curr->right->next=curr->next->left;
                }
                curr=curr->next;
            }
            head=head->left;
        }
        return root;
    }
    //bfs solution
    void bfs(Node * node){
        queue<Node*> q;
        q.push(node);
        while(!q.empty()){
            Node * prev=nullptr;
            int n=q.size();
            for(int i=0;i<n;++i){
                Node * curr=q.front();
                q.pop();
                if(prev!=nullptr){
                    prev->next=curr;
                }
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
                prev=curr;
            }
            prev->next=nullptr;
        }
    }
    Node* connect(Node* root) {
        if(root==nullptr){
            return root;
        }
        bfs(root);
        return root;
    }
};