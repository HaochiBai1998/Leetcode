#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
class Solution {
public:
//DP
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-30000);
        int glo_max=-30000;
        dp[0]=max(dp[0],nums[0]);
        glo_max=max(dp[0],glo_max);
        for(int i=1;i<n;i++){
            dp[i]=max(nums[i],dp[i-1]+nums[i]);
            glo_max=max(dp[i],glo_max);
        }
        return glo_max;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int Max=maxSubArray(nums);
        int n=nums.size();
        vector<int> rightSum(n,-30000);
        rightSum[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            rightSum[i]=rightSum[i+1]+nums[i];
        }
        rightSum[n-1]=rightSum[n-1];
        for(int i=n-2;i>=0;i--){
            rightSum[i]=max(rightSum[i],rightSum[i+1]);
        }
        vector<int> leftSum(n,-30000);
        leftSum[0]=nums[0];
        for(int i=1;i<n-2;i++){
            leftSum[i]=leftSum[i-1]+nums[i];
            Max=max(leftSum[i]+rightSum[i+1],Max);
        }
        return Max;
    }
};
