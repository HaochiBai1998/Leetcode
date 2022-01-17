
#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
#include<math.h>
#include<unordered_set>
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
    // 穿针引线 solution
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right){
            return head;
        }
        ListNode ** L;
        ListNode ** R;
        ListNode ** ptr=&head;
        int n=left;
        while(left!=1){
            ptr=&(*ptr)->next;
            --left;
            --right;
        }
        L=ptr;
        ListNode * tail=*L;
        ListNode * next=(*ptr)->next;
        while(right!=1){
            ListNode * prev=*ptr;
            (*ptr)=next;
            next=(*ptr)->next;
            (*ptr)->next=prev;
            tail->next=next;
            tail->next=next;
            --right;
        }
        R=ptr;
        return head;
    }
    //建reverse list
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right){
            return head;
        }
        ListNode ** L;
        ListNode ** R;
        ListNode ** ptr=&head;
        ListNode * reversed=nullptr;
        int n=left;
        while(left!=1){
            ptr=&(*ptr)->next;
            --left;
            --right;
        }
        L=ptr;
        ListNode * tail;
        while(right!=0){
            reversed=new ListNode((*ptr)->val,reversed);
            if(reversed->next==nullptr){
                tail=reversed;
            }
            ptr=&(*ptr)->next;
            --right;
        }
        R=ptr;
        *L=reversed;
        tail->next=*R;
        return n==1?reversed:head;
    }
};