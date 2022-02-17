//
// Created by bhc on 2022/2/16.
//
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    //dp[i]存到i一次交易最大值，dp2[i]表示从i到最后一次交易最大值
    int maxProfitOne(vector<int>& prices,int head) {
        if(head>=prices.size()){
            return 0;
        }
        int Max=prices[head];
        int Min=prices[head];
        int global_max=INT_MIN;
        for(int i=head;i<prices.size();++i){
            if(prices[i]<Min){
                Min=prices[i];
                Max=Min;
            }
            Max=max(Max,prices[i]);
            global_max=max(global_max,Max-Min);
        }
        return global_max;
    }
    int maxProfit(vector<int>& prices) {
        if(prices.size()==1){
            return 0;
        }
        vector<int> dp(prices.size());
        vector<int> dp2(prices.size());
        int Max=prices[0];
        int Min=prices[0];
        int global_max=INT_MIN;
        for(int i=1;i<prices.size();++i){
            if(prices[i]<Min){
                Min=prices[i];
                Max=Min;
            }
            Max=max(Max,prices[i]);
            global_max=max(global_max,Max-Min);
            dp[i]=global_max;
        }

        Max=prices[prices.size()-1];
        Min=prices[prices.size()-1];
        global_max=INT_MIN;
        for(int i=prices.size()-1;i>=0;--i){
            if(prices[i]>Max){
                Max=prices[i];
                Min=Max;
            }
            Min=min(Min,prices[i]);
            global_max=max(global_max,Max-Min);
            dp2[i]=global_max;
        }
        global_max=INT_MIN;
        for(int i=0;i<prices.size();++i){
            global_max=max(global_max,dp[i]+dp2[i]);
        }
        return global_max;
    }
};