//
// Created by bhc on 2022/2/21.
//
#include<vector>
using namespace std;



class Solution {
public:
    bool canJump(vector<int>& nums) {
        int curr=0;
        int n=nums.size();
        int maxReach=0;
        for(int i=0;i<=maxReach;++i){
            maxReach=max(maxReach,i+nums[i]);
            if(maxReach>=n-1){
                return true;
            }
        }
        return false;
    }
};