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
    //O(1)
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        bool deleteRow=false;
        bool deleteCol=false;
        for(int i=0;i<m;++i){
            if(matrix[i][0]==0){
                deleteCol=true;
            }
        }
        for(int i=0;i<n;++i){
            if(matrix[0][i]==0){
                deleteRow=true;
            }
        }
        for(int i=1;i<m;++i){
            for(int j=1;j<n;++j){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        for(int i=1;i<m;++i){
            for(int j=1;j<n;++j){
                if(matrix[i][0]==0||matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }
        if(deleteCol){
            for(int i=0;i<m;++i){
                matrix[i][0]=0;
            }
        }
        if(deleteRow){
            for(int i=0;i<n;++i){
                matrix[0][i]=0;
            }
        }
    }
    //O(m+n)space
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> row;
        set<int> col;
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(matrix[i][j]==0){
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        for(auto it=row.begin();it!=row.end();++it){
            for(int i=0;i<n;++i){
                matrix[*it][i]=0;
            }
        }        
        for(auto it=col.begin();it!=col.end();++it){
            for(int i=0;i<m;++i){
                matrix[i][*it]=0;
            }
        }
    }
};