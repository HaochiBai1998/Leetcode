
#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row=vector(9,vector(9,true));
        vector<vector<bool>> col=vector(9,vector(9,true));
        vector<vector<bool>> square=vector(9,vector(9,true));
        for(int i=0;i<9;++i){
            for(int j=0;j<9;++j){
                if(board[i][j]=='.')
                    continue;
                int num=board[i][j]-'0';
                if(col[num-1][i]==false){
                    return false;
                }
                else{
                    col[num-1][i]=false;
                } 
                if(row[num-1][j]==false){
                    return false;
                }
                else{
                    row[num-1][j]=false;
                }
                int squareN=(i/3)*3+j/3;
                if(square[num-1][squareN]==false){
                    return false;
                }
                else{
                    square[num-1][squareN]=false;
                }
            }
        }
        return true;
    }
};