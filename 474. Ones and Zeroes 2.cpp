//
// Created by bhc on 2022/2/15.
//
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    pair<int,int> getPair(string & str){
        int z=0;
        int o=0;
        for(int j=0;j<str.size();++j){
            if(str[j]=='1'){
                o++;
            }
            else{
                z++;
            }
        }
        return {z,o};
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size=strs.size();
        int global_max=0;
        vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(n+1,vector<int>(size+1,0)));
        for(int i=1;i<=size;++i){
            pair<int,int> counter=getPair(strs[i-1]);
            for(int j=0;j<=m;++j){
                for(int z=0;z<=n;++z){
                    if(j-counter.first>=0&&j-counter.first<=m&&
                       z-counter.second>=0&&z-counter.second<=n){
                        dp[j][z][i]=max(dp[j-counter.first][z-counter.second][i-1]+1,
                                        dp[j][z][i-1]);
                    }
                    else{
                        dp[j][z][i]= dp[j][z][i-1];
                    }
                    global_max=max(global_max,dp[j][z][i]);
                }
            }
        }
        return global_max;
    }
};