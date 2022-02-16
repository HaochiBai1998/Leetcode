//
// Created by bhc on 2022/2/11.
//


#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
using namespace std;

class Solution {
    vector<int> path;
    vector<int> nums;
    vector<vector<int>> ans;
    int k;
public:
    void dfs(int index,int counter,int rmn){
        if(counter==k||rmn<=0){
            if(rmn==0&&counter==k){
                ans.push_back(path);
            }
            return;
        }
        for(int i=index;i<=9-(k-counter);++i){
            path.push_back(nums[i]);
            dfs(i+1,counter+1,rmn-nums[i]);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        this->k=k;
        nums=vector<int>(9);
        for(int i=0;i<9;++i){
            nums[i]=i+1;
        }
        dfs(0,0,n);
    }
};