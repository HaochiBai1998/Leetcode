//
// Created by bhc on 2022/2/16.
//

#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

class Solution {
public:
    //dp solution
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int sum=0;
        vector<vector<int>> dp(n+1,vector<int>(3));
        dp[1][0]=0;
        dp[1][1]=0;
        dp[1][2]=-prices[0];
        for(int i=2;i<=n;++i){
            dp[i][0]=max(dp[i-1][2]+prices[i-1],dp[i-1][0]);
            dp[i][1]=max(dp[i-1][0],dp[i-1][1]);
            dp[i][2]=max(dp[i-1][2],dp[i-1][1]-prices[i-1]);
        }
        return max(dp[n][0],max(dp[n][1],dp[n][2]));
    }
    //status transform
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int buy=-3000;
        int sell=0;
        int rest=0;
        for(int i=0;i<n;i++){
            int nextBuy=max(rest-prices[i],buy);
            int nextSell=max(buy+prices[i],sell);
            int nextRest=max(rest,sell);
            buy=nextBuy;
            sell=nextSell;
            rest=nextRest;
        }
        return sell;
    }
};