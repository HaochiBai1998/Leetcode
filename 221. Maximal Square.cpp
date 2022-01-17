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
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix.size();
        for(int i=1;i<m;++i){
            for(int j=1;j<n;++j){
                matrix[i][j]=(matrix[i][j]=='1'?min(matrix[i-1][j],min(matrix[i][j-1],matrix[i-1][j-1]))+1:'0');   
            }
        }
        int M=matrix[m-1][n-1];
        return (M-'0')*(M-'0');
    }
};