#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

class Solution {
public:
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