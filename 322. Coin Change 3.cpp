//
// Created by bhc on 2022/2/15.
//
#include<vector>
using namespace std;


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0){
            return 0;
        }
        vector<int> dp(amount+1);
        int sum=0;
        for(int i=1;i<=amount;++i){
            int M=INT_MAX;
            for(int j=0;j<coins.size();++j){
                if(i>coins[j]){
                    if(dp[i-coins[j]]!=0){
                        M=min(M,dp[i-coins[j]]+1);
                    }
                }
                if(i==coins[j]){
                    M=1;
                    break;
                }
            }
            dp[i]=M==INT_MAX?0:M;
        }
        return dp[amount]==0?-1:dp[amount];
    }
};