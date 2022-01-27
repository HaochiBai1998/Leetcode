
#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
#include<math.h>
#include<unordered_set>
#include<queue>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int global_max=0;
        vector<vector<vector<int>>> dp(2,vector<vector<int>>(m,vector<int>(n,0)));
        dp[0][0][0]=dp[1][0][0]=matrix[0][0]-'0';
        for(int i=1;i<m;++i){
            dp[0][i][0]=dp[0][i][0]==0?0:dp[0][i][0]+dp[0][i-1][0];
        }
        for(int i=1;i<n;++i){
            dp[0][0][i]=dp[0][0][i]==0?0:dp[0][0][i]+dp[0][0][i-1];
        }
        for(int i=1;i<m;++i){
            for(int j=1;j<n;++j){
                dp[0][i][j]=dp[0][i][j]==0?0:min(dp[0][i-1][j],min(dp[0][i][j-1],dp[0][i-1][j-1]))+1;
                dp[1][i][j]=dp[1][i][j]==0?0:min(dp[1][i-1][j],min(dp[1][i][j-1],dp[1][i-1][j-1]))+1;
                global_max=max(dp[0][i][j]* dp[1][i][j],global_max);
            }
        }
        return global_max;
    }
    // optimized forceBrute
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> row_max(m,vector<int>(n,0));
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(matrix[i][j]!='0'){
                    row_max[i][j]=matrix[i][j]-'0'+(j<1?0:row_max[i][j-1]);
                }
            }
        }
        int global_max=0;
        for(int i=m-1;i>=0;--i){
            for(int j=n-1;j>=0;--j){
                if(matrix[i][j]=='0'){
                    continue;
                }
                int local_max=0;
                int min_x=row_max[i][j];
                int curr_y=i;
                int y=1;
                while(min_x*y!=0){
                    if(min_x*y>local_max){
                        local_max=min_x*y;
                    }
                    if(curr_y==0){
                        break;
                    }
                    --curr_y;
                    ++y;
                    min_x=min(min_x,row_max[curr_y][j]);
                }
                if(local_max>global_max){
                    global_max=local_max;
                }
            }
        }
        return global_max;
    }
};