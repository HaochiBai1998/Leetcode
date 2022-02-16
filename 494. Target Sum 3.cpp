//
// Created by bhc on 2022/2/15.
//
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;++i){
            sum+=abs(nums[i]);
        }
        if(sum<abs(target)){
            return 0;
        }
        target=abs(target);
        vector<vector<int>> dp(2*sum+1,vector<int>(n+1));
        dp[target+sum][0]=1;
        for(int i=1;i<=nums.size();++i){
            for(int j=2*sum;j>=0;--j){
                if(j+nums[i-1]>=0&&j+nums[i-1]<=2*sum){
                    dp[j][i]+=dp[j+nums[i-1]][i-1];
                }
                if(j-nums[i-1]>=0&&j-nums[i-1]<=2*sum){
                    dp[j][i]+=dp[j-nums[i-1]][i-1];
                }
            }
        }
        return dp[sum][n];
    }
};