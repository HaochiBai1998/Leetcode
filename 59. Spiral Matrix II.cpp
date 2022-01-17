
#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
using namespace std;

class Solution {
public:
    enum{
        RIGHT,
        DOWN,
        LEFT,
        UP
    };
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n,-1));
        int move=RIGHT;
        vector<int> x_move={1,0,-1,0};
        vector<int> y_move={0,1,0,-1};
        ans[0][0]=1;
        int x=0;
        int y=0;
        int counter=2;
        while(true){
            int pre_x=x+x_move[move];
            int pre_y=y+y_move[move];
            if(pre_x<n&&pre_x>=0&&pre_y<n&&pre_y>=0&&ans[pre_y][pre_x]==-1){
                ans[pre_y][pre_x]=counter;
                ++counter;
                x=pre_x;
                y=pre_y;
            }
            else if((x-1<0||ans[y][x-1]!=-1)&&
                    (x+1>=n||ans[y][x+1]!=-1)&&
                    (y-1<0||ans[y-1][x]!=-1)&&
                    (y+1>=n||ans[y+1][x]!=-1)){
                break;
            }
            else
                move=(move+1)%4;
        }
        return ans;
    }
};