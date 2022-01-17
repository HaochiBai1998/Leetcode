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
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        int isNotOb=1;
        for(int i=0;i<m;++i){
            if(obstacleGrid[i][0]==1)
                isNotOb=0;
            obstacleGrid[i][0]=isNotOb;
        }
        isNotOb=obstacleGrid[0][0];
        for(int i=1;i<n;++i){
            if(obstacleGrid[0][i]==1)
                isNotOb=0;
            obstacleGrid[0][i]=isNotOb;
        }
        for(int i=1;i<m;++i){
            for(int j=1;j<n;++j){
                obstacleGrid[i][j]=obstacleGrid[i][j]==1?0:obstacleGrid[i-1][j]+obstacleGrid[i][j-1];
            }
        }
        return obstacleGrid[m-1][n-1];
    }
};