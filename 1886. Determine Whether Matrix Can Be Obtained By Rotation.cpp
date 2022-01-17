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
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n=mat.size();
        bool noRotate=true;
        bool oneRotate=true;
        bool twoRotate=true;
        bool threeRotate=true;
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(target[i][j]!=mat[j][n-1-i])
                    oneRotate=false;
                if(target[i][j]!=mat[i][j])
                    noRotate=false;
                if(target[i][j]!=mat[n-1-i][n-1-j])
                    twoRotate=false;
                if(target[i][j]!=mat[n-1-j][i])
                    threeRotate=false;
                if(!(oneRotate||twoRotate||threeRotate||noRotate))
                    return false;
            }
        }
        return true;
    }
};