
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
    int n;
public:
    void dfs(int prev,int rmn){
        if(rmn==0){
            ans.push_back(path);
            return;
        }
        for(int i=prev+1;i<n-rmn;++i){
            path.push_back(nums[i]);
            dfs(i,rmn-1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        this->nums=nums;
        n=nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<n;++i){
            dfs(-1,i);
            path.clear();
        }
    }
};
