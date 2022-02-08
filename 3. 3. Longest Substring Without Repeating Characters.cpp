


#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        if(n==0)
            return 0;
        map<char,int> m;
        vector<int> dp(n,-1);
        dp[0]=1;
        int M=1;
        for(int i=1;i<n;++i){
            dp[i]=min(dp[i-1]+1,i-m[s[i]]+1);
            m[s[i]]=i+1;
        }
        return dp[n-1];
    }
};