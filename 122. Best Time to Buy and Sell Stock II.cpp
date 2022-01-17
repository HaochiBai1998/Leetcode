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
        if(n==1)
            return 0;
        int minP=prices[0];
        int maxP=prices[1];
        if(maxP<minP){
            minP=maxP;
            maxP=-1;
        }
        int sum=0;
        for(int i=2;i<n;i++){
            if(maxP==-1){
                if(prices[i]>minP)
                    maxP=prices[i];
                else
                    minP=prices[i];
                continue;
            }
            if(prices[i]>maxP)
                maxP=prices[i];
            else{
                sum+=(maxP-minP);
                minP=prices[i];
                maxP=-1;
            }
        }
        if(maxP!=-1){
            sum+=(maxP-minP);
        }
        return sum;
    }
};