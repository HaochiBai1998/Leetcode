
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
    void dfs(int y,int x,vector<vector<char>>& board){
        if(y>=m||y<0||x>=n||x<0||board[y][x]=='X'||board[y][x]==' '){
            return;
        }
        board[y][x]=' ';
        dfs(y+1,x,board);
        dfs(y-1,x,board);
        dfs(y,x+1,board);
        dfs(y,x-1,board);
    }
    void solve(vector<vector<char>>& board) {
        m=board.size();
        n=board[0].size();
        for(int i=0;i<m;++i){
            dfs(i,0,board);
            dfs(i,n-1,board);
        }
        for(int j=0;j<n;++j){
            dfs(0,j,board);
            dfs(m-1,j,board);
        }
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(board[i][j]==' '){
                    board[i][j]='O';
                }
                else{
                    board[i][j]='X';
                }
            }
        }
    }
};