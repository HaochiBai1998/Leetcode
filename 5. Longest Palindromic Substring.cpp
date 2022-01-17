#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
#include<set>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<int>dp(n,0);
        dp[0]=1;
        int max=0;
        string ans;
        for(int i=1;i<n;++i){
            int index=i-dp[i-1]-1;
            if(index>=0&&s[index]==s[i]){
                dp[i]=dp[i-1]+2;
            }
            else 
                dp[i]=1;
            if(dp[i]>max){
                ans=s.substr(i-dp[i]+1,dp[i]);
            }
        }
        return ans;
    }
};