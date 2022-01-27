#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
#include<math.h>
#include<unordered_set>
#include<queue>
#include<list>
using namespace std;

class TicTacToe {
    vector<vector<int>> rows;
    vector<vector<int>> cols;
    vector<vector<int>> diagonal;
    int n;
public:
    TicTacToe(int n) {
        this->n=n;
        rows=vector<vector<int>>(2,vector<int>(n,0));
        cols=vector<vector<int>>(2,vector<int>(n,0));
        diagonal=vector<vector<int>>(2,vector<int>(2,0));
    }
    
    int move(int row, int col, int player) {
        player--;
        rows[player][row]++;
        cols[player][col]++;
        if(rows[player][row]==n|| cols[player][col]==n){
            return player+1;
        }
        if(row==col){
            diagonal[player][0]++;
            if(diagonal[player][0]==n){
                return player+1;
            }
        }
        if(row+col==n-1){
            diagonal[player][1]++;
            if(diagonal[player][1]==n){
                return player+1;
            }
        }
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */