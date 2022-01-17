#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
using namespace std;

class Solution {
public:
    // int trap(vector<int>& height) {
    //     int n=height.size();
    //     vector<int> dp(n+1,0);
    //     vector<int> sum(n+1,0);
    //     int maxV=height[0];
    //     int maxIndex=0;
    //     for(int i=1;i<n;++i){
    //         sum[i]=sum[i-1]+height[i];
    //         if(height[i]>=maxV){
    //             dp[i]=dp[maxIndex]+maxV*(i-maxIndex-1)-(sum[i-1]-sum[maxIndex]);
    //             maxV=height[i];
    //             maxIndex=i;
    //             continue;
    //         }
    //         int FHTIndex=i-1;
    //         while(height[FHTIndex]<height[i])
    //             FHTIndex--;
    //         dp[i]=dp[FHTIndex]+height[i]*(i-FHTIndex-1)-(sum[i-1]-sum[FHTIndex]);
    //     }
    //     for(int i=0;i<n;i++){
    //         cout<<dp[i]<<" ";
    //     }
    //     return dp[n-1];
    // }
    //O(n)
    int trap(vector<int>& height)
    {
        if(height.empty())
            return 0;
        int ans = 0;
        int size = height.size();
        vector<int> left_max(size), right_max(size);
        left_max[0] = height[0];
        for (int i = 1; i < size; i++) {
            left_max[i] = max(height[i], left_max[i - 1]);
        }
        right_max[size - 1] = height[size - 1];
        for (int i = size - 2; i >= 0; i--) {
            right_max[i] = max(height[i], right_max[i + 1]);
        }
        for (int i = 1; i < size - 1; i++) {
            ans += min(left_max[i], right_max[i]) - height[i];
        }
        return ans;
    }
};