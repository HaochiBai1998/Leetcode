
#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
#include<set>
using namespace std;


class Solution {
    vector<vector<int>> ans;
    vector<int> nums;
    vector<int> path;
    vector<bool> reached;
    int n;
public:
    void dfs(int count){
        if(count==n){
            ans.push_back(path);
            return;
        }
        for(int i=0;i<n;++i){
            if(reached[i])
                continue;
            path.push_back(nums[i]);
            reached[i]=true;
            dfs(count+1);
            reached[i]=false;
            path.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        n=nums.size();
        vector<bool> reached(n,false);
        this->reached=reached;
        this->nums=nums;
        dfs(0);
        return ans;
    }
};