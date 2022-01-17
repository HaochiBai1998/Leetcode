#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<bool>dp(n+1,false);
        dp[0]=true;
        for(int i=0;i<n;++i){
            if(dp[i]!=true) continue;
            for(auto it=wordDict.begin();it!=wordDict.end();++it){
                int wordLen=it->size();
                if(s.substr(i).find(*it)!=string::npos&&i+wordLen<=n){
                    dp[i+wordLen-1]=true;
                }
            }            
        }
        return dp[n-1];
    }
};