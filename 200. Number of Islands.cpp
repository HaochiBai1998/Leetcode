
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
    int m;
    int n;
public:
    void dfs(int i,int j,vector<vector<char>> & grid){
        if(i>=m||i<0||j>=n||j<0||grid[i][j]=='0'){
            return;
        }
        grid[i][j]='0';
        dfs(i+1,j,grid);
        dfs(i,j+1,grid);
        dfs(i-1,j,grid);
        dfs(i,j-1,grid);
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        m=grid.size();
        n=grid[0].size();
        int counter=0;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j]=='1'){
                    dfs(i,j,grid);
                    ++counter;
                }
            }
        }
        return counter;
    }
};