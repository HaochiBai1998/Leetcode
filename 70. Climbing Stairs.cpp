#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int recursion(int n,vector<int> & ways){
        if(n==0)
            return ways[n]=0;
        if(n==1)
            return ways[n]=1;
        if(n==2)
            return ways[n]=2;
        if(ways[n]!=-1)
            return ways[n];
        return ways[n]=recursion(n-1,ways)+recursion(n-2,ways);
    }
    int climbStairs(int n) {
        vector<int> ways(n+1,-1);
        return recursion(n,ways);
    }
};