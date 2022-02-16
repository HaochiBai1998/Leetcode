
#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
using namespace std;


class Solution {
    vector<int> path;
    vector<vector<int>> ans;
    int n;
public:
    void dfs(int index,vector<int>& nums){
        ans.push_back(path);
        if(index==n){
            return;
        }
        for(int i=index;i<n;++i){
            path.push_back(nums[i]);
            dfs(i+1,nums);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        n=nums.size();
        dfs(0,nums);
        return ans;
    }
};
};
