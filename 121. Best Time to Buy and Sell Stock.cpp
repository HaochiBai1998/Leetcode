#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int prevMin=10000;
        int n=prices.size();
        for(int i=0;i<n;i++){
            prevMin=min(prevMin,prices[i]);
            ans=max(ans,prices[i]-prevMin);
        }
        return ans;
    }
};