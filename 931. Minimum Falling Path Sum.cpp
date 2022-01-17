#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        if(n==1)
            return matrix[0][0];
        vector<vector<int>> dp(n,vector<int>(n,0));
        dp[0]=matrix[0];
        for(int i=1;i<n;++i){
            dp[i][0]=matrix[i][0]+min(dp[i-1][0],dp[i-1][1]);
            for(int j=1;j<n-1;++j){
                dp[i][j]=matrix[i][j]+min(dp[i-1][j],min(dp[i-1][j-1],dp[i-1][j+1]));
            }
            dp[i][n-1]=matrix[i][n-1]+min(dp[i-1][n-1],dp[i-1][n-2]);
        }
        int M=10000;
        for(int i=0;i<n;++i){
            M=min(M,dp[n-1][i]);
        }
        return M;
    }
};