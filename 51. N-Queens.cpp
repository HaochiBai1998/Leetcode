
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
    vector<string> board;
    int n;
    vector<bool> usedCols;
    vector<bool> leftDiagnal;
    vector<bool> rightDiagnal;
public:
    //
    //dfs + backtrack solution
    void dfs(vector<vector<string>>& ans,int row){
        if(row==n){
            ans.push_back(board);
            return;
        }
        for(int i=0;i<n;++i){
            if(usedCols[i]==true||
            leftDiagnal[i-row+n]==true||
            rightDiagnal[i+row+n]==true){
                continue;
            }
            board[row][i]='Q';
            usedCols[i]=true;
            leftDiagnal[i-row+n]=true;
            rightDiagnal[i+row+n]=true;
            dfs(ans,row+1);
            usedCols[i]=false;
            leftDiagnal[i-row+n]=false;
            rightDiagnal[i+row+n]=false;
            board[row][i]='.';
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        this->n=n;
        string oneLine;
        for(int i=0;i<n;++i){
            oneLine+=".";
        }
        vector<vector<string>> ans;
        usedCols=vector<bool>(n,false);
        leftDiagnal=vector<bool>(2*n,false);
        rightDiagnal=vector<bool>(2*n,false);
        board=vector<string>(n,oneLine);
        dfs(ans,0);
        return ans;
    }
};