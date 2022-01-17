#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        if(n==1)
            return triangle[0][0];
        vector<int> line(triangle[0]);
        for(int i=1;i<n;++i){
            for(int j=i-1;j>=0;--j){
                line[j]=triangle[i][j]+min(line[j-1],line[j]);
            }
            line.push_back(triangle[i][i]+line[i-1]);                 
            line[0]+=triangle[i][0];
        }
        int M=2000000;
        for(int i=0;i<n;++i){
            M=min(M,line[i]);
        }
        return M;
    }
};