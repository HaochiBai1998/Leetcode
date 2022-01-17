
 
#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
#include<set>
using namespace std;

void qsort(vector<int>& nums,int head,int tail){
    if(tail==head)
        return;
    if(tail+1==head){
        if(nums[head]>nums[tail]){
            swap(nums[head],nums[tail]);
            return;
        }
    }
    int ref=nums[head];
    int H=head;
    int T=tail;
    ++head;
    while(head<tail){
        while(head<tail&&nums[head]<ref)
            ++head;
        while(tail>head&&nums[tail]>=ref)
            --tail;
        if(head<tail)
            swap(nums[head],nums[tail]);
    }
    swap(nums[head-1],nums[H]);
    qsort(nums,H,head-2);
    qsort(nums,head,T);
}