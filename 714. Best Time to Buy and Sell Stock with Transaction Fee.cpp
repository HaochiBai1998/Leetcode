#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int buy=-prices[0];
        int rest=0;
        int n=prices.size();
        for(int i=1;i<n;i++){
            int newBuy=max(buy,rest-prices[i]);
            int newRest=max(buy+prices[i]-fee,rest);
            buy=newBuy;
            rest=newRest;
        }
        return rest;
    }
};