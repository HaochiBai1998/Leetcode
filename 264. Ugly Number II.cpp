#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n,0);
        int twoIndex=0;
        int threeIndex=0;
        int fiveIndex=0;
        dp[0]=1;
        for(int i=1;i<n;i++){
            dp[i]=min(2*dp[twoIndex],min(3*dp[threeIndex],5*dp[fiveIndex]));
            if(dp[i]==2*dp[twoIndex])
                twoIndex++;
            if(dp[i]==2*dp[threeIndex])
                threeIndex++;
            if(dp[i]==2*dp[fiveIndex])
                fiveIndex++;
        }
        return dp[n-1];
    }
};