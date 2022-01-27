
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
public:
    //z search
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int i=0;
        int j=n-1;
        while(i<m&&j>=0){
            if(matrix[i][j]==target){
                return true;
            }
            else if(matrix[i][j]>target){
                j--;
            }
            else{
                i++;
            }
        }
        return false;
    }
    //binary search each satisfied line;
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int i=0;
        for(;i<m;++i){
            if(matrix[i][0]<=target&&matrix[i][n-1]>=target){
                int head=0;
                int tail=n-1;
                while(head<=tail){
                    int mid=(head+tail)/2;
                    if(matrix[i][mid]>target){
                        tail=mid-1;
                    }
                    else if(matrix[i][mid]<target){
                        head=mid+1;
                    }
                    else{
                        return true;
                    }
                }
            }
        }
        if(i==m){
            return false;
        }
        return false;
    }
};