#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>

class Solution {
public:
int maxProfit(vector<int>& prices) {
    int sum =0;
    int Min =prices[0];
    int Max= prices[0];
    for(int i=1;i<prices.size();++i){
        if(prices[i]<Max){
            sum+= (Max-Min);
            Min=prices[i];
            Max=Min;
        }
        Max=max(Max,prices[i]);
    }
    sum+=(Max-Min);
    return sum;
}
};