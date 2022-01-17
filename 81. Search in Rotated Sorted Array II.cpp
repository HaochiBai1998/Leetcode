
#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
using namespace std;
class Solution {
    int n;
public:
    //binary search solution
    bool BsearchRotate(int H,int T,int target,vector<int>& nums){
        if(H>=T&&nums[H]!=target){
            return false;
        }
        int mid=(H+T)/2;
        if(nums[mid]==target||nums[T]==target||nums[H]==target)
            return true;
        if(nums[mid]>nums[H]&&target<nums[mid]&&target>nums[H]){
            return BsearchRotate(H,mid-1,target,nums);
        }
        else if(nums[mid]<nums[H]&&target>nums[mid]&&target<nums[T]){
            return BsearchRotate(mid+1,T,target,nums);
        }
        else
            return BsearchRotate(H,mid-1,target,nums)||BsearchRotate(mid+1,T,target,nums);
    }
    bool search(vector<int>& nums, int target) {
        n=nums.size();
        return BsearchRotate(0,n-1,target,nums);
    }
};