//
// Created by bhc on 2022/2/8.
//

#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
#include<set>
#include<queue>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    //跳跃指针
    ListNode* oddEvenList(ListNode* head) {
        if(!head||!head->next){
            return head;
        }
        ListNode * curr=head;
        ListNode * even_head=head->next;
        ListNode * odd_head=head;
        while(curr&&curr->next){
            ListNode * node = curr->next;
            curr->next=curr->next->next;
            if(node->next){
                node->next=node->next->next;
            }
            else{
                break;
            }
            curr=curr->next;
        }
        if(curr->next){
            curr=curr->next;
        }
        curr->next=even_head;
        return head;
    }
};