
#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
using namespace std;
class Solution {
public:
    //binary search solution
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int size=m*n;
        int T=size-1;
        int H=0;
        while(H<T){
            int mid=(H+T)/2;
            int X=mid%n;
            int Y=mid/n;
            if(matrix[Y][X]<target){
                H=mid+1;
            }
            else if(matrix[Y][X]>target){
                T=mid-1;
            }
            else
                return true;
        }
        int X=H%n;
        int Y=H/n;
        if(matrix[Y][X]==target)
            return true;
        return false;
    }
};