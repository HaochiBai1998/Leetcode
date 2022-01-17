#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
#include<set>
using namespace std;
enum{
    RIGHT,
    DOWN,
    LEFT,
    UP
};
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int move=RIGHT;
        int x_move[]={1,0,-1,0};
        int y_move[]={0,1,0,-1};
        int x=0;
        int y=0;
        int m=matrix.size();
        int n=matrix[0].size();
        while(true){
            if(matrix[y][x]!=-101)
                ans.push_back(matrix[y][x]);
            matrix[y][x]=-101;
            int pre_x=x+x_move[move];
            int pre_y=y+y_move[move];
            if(pre_x<n&&pre_x>=0&&pre_y<m&&pre_y>=0&&matrix[pre_y][pre_x]!=-101){
                x=pre_x;
                y=pre_y;
            }
            else{
                if((x-1<0||matrix[y][x-1]==-101)&&
                    (x+1>=n||matrix[y][x+1]==-101)&&
                    (y-1<0||matrix[y-1][x]==-101)&&
                    (y+1>=m||matrix[y+1][x]==-101))
                        break;
                move=(move+1)%4;
            }
        }
        return ans;
    }
};