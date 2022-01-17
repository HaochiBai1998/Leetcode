#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
using namespace std;

class Solution {
public:
    //math solution
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        if(n==1)
            return 0;
        int diff=nums[1]-nums[0];
        int count=1;
        for(int i=1;i<n-1;i++){
            if(nums[i+1]-nums[i]!=diff){
                if(count>=2){
                    ans+=(count*count-count)/2;
                }
                diff=nums[i+1]-nums[i];
                count=1;
                continue;
            }
            count++;
        }
        if(count>=2){
            ans+=(count*count-count)/2;
        }
        return ans;
    }
    //dp
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        vector<int> dp(n,0);
        for(int i=2;i<n;i++){
            if(nums[i-1]-nums[i-2]==nums[i]-nums[i-1])
                dp[i]=dp[i-1]+1;
            ans+=dp[i];
        }
        return ans;
    }
};