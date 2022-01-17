#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
#include<set>
using namespace std;


class Solution {
    vector<int> candidates;
    vector<int> comb;
    vector<vector<int>> ans;
    int n;
public:
    void dfs(int index,int rest){
        if(rest==0){
            ans.push_back(comb);
            return;
        }
        int first=index;
        for(;index>=0&&(index+1)*candidates[index]>=rest;--index){
            if(candidates[index]>rest) continue;
            if(index==n-1||index==first||candidates[index+1]!=candidates[index]){
                comb.push_back(candidates[index]);
                dfs(index-1,rest-candidates[index]);
                comb.pop_back();
            }
        }
    };
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        this->candidates=candidates;
        this->n=candidates.size();
        dfs(n-1,target);
        return this->ans;
    }
};