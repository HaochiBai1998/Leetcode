//
// Created by bhc on 2022/2/9.
//


#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
#include<set>
#include<queue>
#include<unordered_map>
using namespace std;

class Solution {
    unordered_map<int,int> mem;
public:
    int dfs(long n){
        if(n==1){
            return 0;
        }
        if(mem.count(n)){
            return mem[n];
        }
        if(n%2){
            mem[n]=min(dfs(n+1),dfs(n-1))+1;
        }
        else{
            mem[n]=dfs(n/2)+1;
        }
        return mem[n];
    }
    int integerReplacement(int n) {
        return dfs((long)n);
    }
};