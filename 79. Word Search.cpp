

#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
using namespace std;

class Solution {
    //backtrack+dfs solution
    vector<vector<bool>> reached;
    string word;
    vector<vector<char>> board;
    int size;
    int m;
    int n;
    bool dfs(int index,int y,int x){
        if(word[index]!=board[y][x]){
            return false;
        }
        if(index==size-1){
            return true;
        }
        reached[y][x]=true;
        int off_y[4]={0,1,0,-1};
        int off_x[4]={1,0,-1,0};
        for(int i=0;i<4;++i){
            int next_y=y+off_y[i];
            int next_x=x+off_x[i];
            if(next_y>=0&&next_y<m&&
            next_x>=0&&next_x<n){
                if(reached[next_y][next_x]==true)
                    continue;
                if(!dfs(index+1,next_y,next_x)){
                    continue;
                }
                else
                    return true;
            }
        }
        reached[y][x]=false;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        size=word.size();
        this->word=word;
        this->board=board;
        m=board.size();
        n=board[0].size();
        reached=vector<vector<bool>>(m,vector<bool>(n,false));
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(word[0]==board[i][j]){
                    if(dfs(0,i,j)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};