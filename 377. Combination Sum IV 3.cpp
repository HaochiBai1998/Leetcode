//
// Created by bhc on 2022/2/15.
//
#include<vector>
using namespace std;
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<long long > dp(target+1);
        dp[0]=1;
        for(int i=1;i<=target;++i){
            long long sum=0;
            for(int j=0;j<nums.size();++j){
                if(i>=nums[j]&&sum+dp[i-nums[j]]<=INT_MAX){
                    sum+=dp[i-nums[j]];
                }
            }
            dp[i]=sum;
        }
        return dp[target];
    }
};