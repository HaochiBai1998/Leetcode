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
    //optimized Prefix Sum solution
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> ans(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;++i){
            for(int j=1;j<=n;++j){
                ans[i][j]=mat[i-1][j-1]+ans[i-1][j]+ans[i][j-1]-ans[i-1][j-1];
            }
        }
        vector<vector<int>> ans1(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int leftTopX=max(j-k,0);
                int leftTopY=max(i-k,0);
                int rightDownX=min(j+k+1,n);
                int rightDownY=min(i+k+1,m);
                ans1[i][j]=ans[rightDownY][rightDownX]-ans[rightDownY][leftTopX]
                    -ans[leftTopY][rightDownX]+ans[leftTopY][leftTopX];
            }
        }
        return ans1;
    }
    //brute-force
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> ans(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                for(int z=j-k;z<j+k;++z){
                    if(z<0||z>=n)
                        continue;
                    ans[i][j]+=mat[i][z];
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                for(int z=i-k;z<j+k;++z){
                    if(z<0||z>=m)
                        continue;
                    ans[i][j]+=mat[z][j];
                }
            }
        }
        return ans;
    }
};