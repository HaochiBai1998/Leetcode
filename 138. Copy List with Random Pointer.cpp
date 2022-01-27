
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
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
    unordered_map<Node*,Node*> hashTable;
public:
    Node* helper(Node * head,Node * newList){
        if(head==nullptr){
            return nullptr;
        }
        if(!hashTable.count(head)){
            newList=new Node(head->val);
            hashTable[head]=newList;
            newList->next= helper(head->next,newList->next);
            newList->random= helper(head->random,newList->random);
        }
        return hashTable[head];
    }
    Node* copyRandomList(Node* head) {
        return helper(head,nullptr);
    }
};