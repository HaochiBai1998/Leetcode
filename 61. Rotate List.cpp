
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
    //circle solution
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL){
            return head;
        }
        ListNode * tail=head;
        int n=1;
        while(tail->next!=NULL){
            ++n;
            tail=tail->next;
        }
        k%=n;
        if(n==1||k==0)
            return head;
        tail->next=head;
        ListNode ** p=&head;
        for(int i=0;i<n-k-1;++i){
            p=&((*p)->next);
        }
        ListNode* tmp=(*p)->next;
        (*p)->next=NULL;
        return tmp;
    }
    //find cut place and directly connect
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL){
            return head;
        }
        ListNode * tail=head;
        int n=1;
        while(tail->next!=NULL){
            ++n;
            tail=tail->next;
        }
        k%=n;
        if(k==0)
            return head;
        ListNode ** p=&head;
        for(int i=0;i<n-k-1;++i){
            p=&((*p)->next);
        }
        tail->next=head;
        ListNode * buf=(*p)->next;
        (*p)->next=NULL;
        head=buf;
        return head;
    }