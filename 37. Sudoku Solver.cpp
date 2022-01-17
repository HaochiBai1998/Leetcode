
#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
#include<set>
using namespace std;
class Solution {
    vector<vector<char>> board;
    vector<vector<int>> row;
    vector<vector<int>> col;
    vector<vector<int>> square;
    int counter;
public:
    void Print(){
        for(int i=0;i<9;++i){
            cout<<"[";
            for(int j=0;j<9;++j){
                cout<<board[i][j]<<(j==8?"":",");
            }
            cout<<"]"<<endl;
        }
        cout<<endl<<endl;
    }
    void dfs(){
        if(counter==0){
            return;
        }
        for(int i=0;i<9;++i){
            for(int j=0;j<9;++j){
                int n=i/3*3+j/3;
                if(board[i][j]!='.')    continue;
                for(int num=0;num<9;++num){
                    if(row[num][i]==1||
                       col[num][j]==1||
                       square[num][n]==1){
                        continue;
                    }
                    board[i][j]='0'+num+1;
                    row[num][i]=1;
                    col[num][j]=1;
                    square[num][n]=1;
                    counter--;
                    cout<<counter<<endl<<endl;
                    Print();
                    dfs();
                    if(counter!=0){
                        board[i][j]='.';
                        row[num][i]=0;
                        col[num][j]=0;
                        square[num][n]=0;
                        ++counter;    
                        cout<<counter<<endl<<endl;
                        Print();
                    }
                    else{
                        return;
                    }
                }
                if(board[i][j]=='.'){
                    return;
                }
            }
        }
        return;
    }
    void solveSudoku(vector<vector<char>>& board) {
        this->board=board;
        row=vector<vector<int>>(9,vector<int>(9,0));
        col=vector<vector<int>>(9,vector<int>(9,0));
        square=vector<vector<int>>(9,vector<int>(9,0));
        counter=0;
        for(int i=0;i<9;++i){
            for(int j=0;j<9;++j){
                if(board[i][j]=='.'){
                    counter++;
                    continue;
                }
                int n=i/3*3+j/3;
                int num=board[i][j]-'0'-1;
                row[num][i]=1;
                col[num][j]=1;
                square[num][n]=1;
            }
        }
        dfs();
    }
};
int main(){
    Solution s;
    vector<vector<char>> board={{'5', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    s.solveSudoku(board);
}




// class Solution {
//     vector<vector<char>> board;
//     vector<vector<bool>> row;
//     vector<vector<bool>> col;
//     vector<vector<bool>> square;
//     vector<set<int>> rowSet;
//     vector<set<int>> colSet;
//     vector<set<int>> squareSet;
// public:
//     void getValidSudoku() {
//         for(int i=0;i<9;++i){
//             for(int j=0;j<9;++j){
//                 if(board[i][j]=='.')
//                     continue;
//                 int num=board[i][j]-'0';
//                 int squareN=i/3*3+j/3;
//                 row[num-1][i]=false;
//                 col[num-1][j]=false;
//                 square[num-1][squareN]=false;
//             }
//         }
//     }
//     void solveSudoku(vector<vector<char>>& board) {
//         this->board=board;
//         row=vector(9,vector(9,true));
//         col=vector(9,vector(9,true));
//         square=vector(9,vector(9,true));
//         //set indicates numbers that can be placed in a row/col/square
//         getValidSudoku();
//         rowSet=vector(9,set<int>());
//         colSet=vector(9,set<int>());
//         squareSet=vector(9,set<int>());
//         for(int num=0;num<9;++num){
//             for(int j=0;j<9;++j){
//                 if(row[num][j]==true){
//                     rowSet[j].insert(num);
//                 }
//                 if(col[num][j]==true){
//                     colSet[j].insert(num);
//                 }
//                 if(square[num][j]==true){
//                     squareSet[j].insert(num);
//                 }
//             }
//         }
//         int counter=0;
//         for(int i=0;i<9;++i){
//             for(int j=0;j<9;++j){
//                 if(board[i][j]=='.')
//                     counter++;
//             }
//         }
//         while(counter!=0){
//             //each square
//             for(int i=0;i<9;++i){
//                 int x=3*i%9;
//                 int y=i/3*3;
//                 for(auto it=squareSet[i].begin();it!=squareSet[i].end();++it){
//                     int X;
//                     int Y;
//                     int canPlace=0;
//                     for(int off_x=0;off_x<3;++off_x){
//                         for(int off_y=0;off_y<3;++off_y){
//                             if(board[y+off_y][x+off_x]!='.')
//                                 continue;
//                             if(colSet[off_x+x].find(*it)!=colSet[off_x+x].end()&&
//                             rowSet[off_y+y].find(*it)!=rowSet[off_y+y].end()){
//                                 canPlace++;
//                                 X=off_x+x;
//                                 Y=off_y+y;
//                             }
//                         }
//                     }
//                     if(canPlace==1){
//                         board[Y][X]=*it+1+'0';
//                         colSet[X].erase(*it);
//                         rowSet[Y].erase(*it);
//                         int S=Y/3*3+X/3;
//                         squareSet[S].erase(*it);
//                         counter--;
//                     }
//                 }
//             }
//         }
//         return;
//     }
// };