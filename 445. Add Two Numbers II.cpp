
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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 *//**
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
    int n1;
    int n2;
    int findSolution(ListNode * l1,ListNode* l2){
        if(l1==nullptr){
            return 0;
        }
        if(n1>n2){
            --n1;
            int sum=l1->val+findSolution(l1->next,l2);
            l1->val=sum%10;
            return sum/10;
        }
        else{
            int sum=l1->val+l2->val+findSolution(l1->next,l2->next);
            l1->val=sum%10;
            return sum/10;
        }
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * curr=l1;
        n1=0;
        while(curr!=nullptr){
            ++n1;
            curr=curr->next;
        }
        curr=l2;
        n2=0;
        while(curr!=nullptr){
            ++n2;
            curr=curr->next;
        }
        if(n2>n1){
            swap(l1,l2);
            swap(n1,n2);
        }
        
        int cout=findSolution(l1,l2);
        if(cout){
            l1=new ListNode(1,l1);
        }
        return l1;
    }
};