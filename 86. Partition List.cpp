
#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode ** index=&head;
        while((*index)!=NULL&&(*index)->val<x){
            index=&(*index)->next;
        }
        if(*index==NULL)
            return head;
        ListNode ** ptr=&(*index)->next;
        while((*ptr)!=NULL){
            if((*ptr)->val<x){
                *index=new ListNode((*ptr)->val,*index);
                index=&(*index)->next;
                *ptr=(*ptr)->next;
            }
            else{    
                ptr=&(*ptr)->next;
            }
            if(*ptr==NULL)
                return head;
        }
        return head;
    }
    ListNode* partition(ListNode* head, int x) {
        ListNode* small = new ListNode(0);
        ListNode* smallHead = small;
        ListNode* large = new ListNode(0);
        ListNode* largeHead = large;
        while (head != nullptr) {
            if (head->val < x) {
                small->next = head;
                small = small->next;
            } else {
                large->next = head;
                large = large->next;
            }
            head = head->next;
        }
        large->next = nullptr;
        small->next = largeHead->next;
        return smallHead->next;
    }
};
