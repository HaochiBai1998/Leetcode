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
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> ans(m,vector<int>(n,0));
        for(int i=0;;++i){
            int down=m-i;
            int top=i;
            int left=i;
            int right=n-i;
            if(top>=down||right<=left){
                break;
            }
            int m=down-top+1;
            int n=right-left+1;
            int sum=2*m+2*n-4;
            int tmp=k%sum;
            for(int j=down;j>=top+k;--j){
                ans[j][left]=grid[j-k][left];
            }
            for(int j=top;j<=down-k;++j){
                ans[j][right]=grid[j+k][right];
            }
            for(int j=left;j<=right-k;++j){
                ans[top][j]=grid[top][j+k];
            }
            for(int j=right;j>=left+k;--j){
                ans[down][j]=grid[top][j-k];
            }
        }
    }
};