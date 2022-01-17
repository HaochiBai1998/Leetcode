#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int n=nums.size();
        if(n==0){
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        int low=0;
        int high=n-1;
        int head=-1;
        int tail=-1;
        while(high>=low){
            int mid=(high-low)/2;
            if(nums[mid]>target){
                high=mid-1;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            else{
                head=mid;
                low=mid-1;
            }
        }
        low=head;
        high=n-1;
        while(high>=low){
            int mid=(high-low)/2;
            if(nums[mid]>target){
                high=mid-1;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            else{
                tail=mid;
                high=mid+1;
            }
        }
    }
};
