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
        vector<int> dp(n,-10000);
        int glo_max=-10000;
        dp[0]=max(dp[0],nums[0]);
        glo_max=max(dp[0],glo_max);
        for(int i=1;i<n;i++){
            dp[i]=max(nums[i],dp[i-1]+nums[i]);
            glo_max=max(dp[i],glo_max);
        }
        return glo_max;
    }
};

//Divide and conquer
int maxSubArray(vector<int>& nums) {
        return maxSubArray(nums, 0, size(nums)-1);
    }
    int maxSubArray(vector<int>& A, int L, int R){
        if(L > R) return INT_MIN;
        int mid = (L + R) / 2, leftSum = 0, rightSum = 0;
        // leftSum = max subarray sum in [L, mid-1] and starting from mid-1
        for(int i = mid-1, curSum = 0; i >= L; i--)
            curSum += A[i],
            leftSum=max(leftSum, curSum);
        // rightSum = max subarray sum in [mid+1, R] and starting from mid+1
        for(int i = mid+1, curSum = 0; i <= R; i++)
            curSum += A[i],
            rightSum = max(rightSum, curSum);        
		// return max of 3 cases 
        return max({ maxSubArray(A, L, mid-1), maxSubArray(A, mid+1, R), leftSum + A[mid] + rightSum });
    }	
};