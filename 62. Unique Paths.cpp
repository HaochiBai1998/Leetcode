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
    int uniquePaths(int m, int n) {
        vector<vector<long long>> path(m,vector<long long>(n,0));
        for(int i=0;i<m;++i){
            path[i][0]=1;
        }
        for(int i=1;i<n;++i){
            path[0][i]=1;
        }
        for(int i=1;i<m;++i){
            for(int j=1;j<n;++j){
                path[i][j]=path[i-1][j]+path[i][j-1];
            }
        }
        return path[m-1][n-1];
    }
};