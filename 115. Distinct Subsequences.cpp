//
// Created by bhc on 2022/2/19.
//
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    int numDistinct(string s, string t) {
        int n1=s.size();
        int n2=t.size();
        if(n2>n1){
            return 0;
        }
        vector<vector<long>> dp(n2+1,vector<long>(n1+1));
        int counter=0;
        for(int i=1;i<=n1;++i){
            dp[0][i]=1;
        }
        for(int i=1;i<=n2;++i){
            if(i!=1&&s[i-1]==s[i-2]){
                counter++;
            }
            else{
                counter=0;
            }
            for(int j=1;j<=n1;++j){
                if(t[i-1]!=s[j-1]){
                    dp[i][j]=dp[i][j-1];
                }
                else{
                    if(i!=1&&t[i-1]==t[i-2]){
                        dp[i][j]=dp[i-1][j-1]+dp[i][j-1];
                        if(dp[i][j]>INT_MAX){
                            dp[i][j]=INT_MAX;
                        }
                    }
                    else{
                        dp[i][j]=dp[i-1][j]+dp[i][j-1];
                        if(dp[i][j]>INT_MAX){
                            dp[i][j]=INT_MAX;
                        }
                    }
                }
            }
        }
        return dp[n2][n1];
    }
};