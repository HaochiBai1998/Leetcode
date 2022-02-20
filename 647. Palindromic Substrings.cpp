//
// Created by bhc on 2022/2/19.
//
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n));
        int ans=0;
        for(int i=1;i<=n;++i){
            for(int j=0;j<=n-i;++j){
                if(i<2||((dp[j+1][j+i-2]||j+1>=j+i-2)&&s[j]==s[j+i-1])){
                    dp[j][j+i-1]=true;
                    ans++;
                }
            }
        }
        return ans;
    }
};