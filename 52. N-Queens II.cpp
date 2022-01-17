

#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
#include<math.h> 
#include<unordered_set>
#include<set>
using namespace std;

class Solution {
    int n;
    vector<bool> usedCols;
    vector<bool> leftDiagnal;
    vector<bool> rightDiagnal;
    int ans;
public:
    //
    //dfs + backtrack solution
    void dfs(int row){
        if(row==n){
            ans++;
            return;
        }
        for(int i=0;i<n;++i){
            if(usedCols[i]==true||
            leftDiagnal[i-row+n]==true||
            rightDiagnal[i+row+n]==true){
                continue;
            }
            usedCols[i]=true;
            leftDiagnal[i-row+n]=true;
            rightDiagnal[i+row+n]=true;
            dfs(row+1);
            usedCols[i]=false;
            leftDiagnal[i-row+n]=false;
            rightDiagnal[i+row+n]=false;
        }
        return;
    }
    int totalNQueens(int n) {
        this->n=n;
        usedCols=vector<bool>(n,false);
        leftDiagnal=vector<bool>(2*n,false);
        rightDiagnal=vector<bool>(2*n,false);
        ans=0;
        dfs(0);
        return ans;
    }
};