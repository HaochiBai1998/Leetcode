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

class Solution {
public:
    //快慢指针判断环
    bool hasCycle(ListNode *head) {
        ListNode * quicker=head;
        ListNode * slower=head;
        while(quicker!=nullptr&&slower!=nullptr){
            if(!quicker->next||!quicker->next->next){
                return false;
            }
            quicker=quicker->next->next;
            slower=slower->next;
            if(quicker==slower){
                return true;
            }
        }
        return false;
    }
    //哈希后看是否走过
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*,int> hashMap;
        while(head!=nullptr){
            if(hashMap.count(head)){
                return true;
            }
            hashMap[head]++;
            head=head->next;
        }
        return false;
    }
};