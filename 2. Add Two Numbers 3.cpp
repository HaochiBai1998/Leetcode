//
// Created by bhc on 2022/2/11.
//

 struct ListNode {
      int val;
      ListNode *next;
     ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1){
            return l2;
        }
        int cout=0;
        ListNode * head=l1;
        ListNode * curr=l1;
        ListNode * tail;
        ListNode * newHead;
        while(curr){
            curr->val=curr->val+(l2?l2->val:0);
            if(!curr->next){
                curr->next=l2?l2->next:nullptr;
                break;
            }
            curr=curr->next;
            l2=l2?l2->next:nullptr;
        }
        curr=head;
        while(curr){
            int tmp=(curr->val+cout)>=10;
            curr->val=(curr->val+cout)%10;
            cout=tmp;
            if(curr->next){
                curr=curr->next;
            }
            else{
                if(cout==1){
                    curr->next=new ListNode(1);
                }
                break;
            }
        }
        return head;
    }
};