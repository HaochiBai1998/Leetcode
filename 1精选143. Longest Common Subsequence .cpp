//
// Created by bhc on 2022/2/17.
//
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size();
        int n2=text2.size();
        int global_max=0;
        vector<vector<int>> dp(n1+1,vector<int>(n2+1));
        for(int i=1;i<=n1;++i){
            for(int j=1;j<=n2;++j){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=max(dp[i-1][j],max(dp[i][j-1],dp[i-1][j-1]+1));
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
                global_max=max(global_max,dp[i][j]);
            }
        }
        return global_max;
    }
};