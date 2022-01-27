
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
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        int head=0;
        int tail=n-1;
        while(head<tail){
            int left=head+1;
            int right=tail;
            int ref=nums[head];
            while(right>left){
                while(right>left&&nums[right]<ref){
                    --right;
                }
                while(right>left&&nums[left]>=ref){
                    ++left;
                }
                swap(nums[left],nums[right]);
            }
            if(ref<=nums[right]){
                swap(nums[head],nums[right]);
            }
            else{
                right=head;
            }
            if(right>k-1){
                tail=right-1;
            }
            else if(right<k-1){
                head=right+1;
            }
            else{
                break;
            }
        }
        return nums[k-1];
    }
};