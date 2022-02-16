
#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
#include<math.h> 
#include<unordered_set>

using namespace std;
class Solution {
    vector<int> path;
    vector<vector<int>> ans;
    int n;
public:
    void dfs(int index,vector<int> & nums){
        ans.push_back(path);
        if(index==n){
            return;
        }
        for(int i=index;i<n;++i){
            if(i!=index&&nums[i]==nums[i-1]){
                continue;
            }
            path.push_back(nums[i]);
            dfs(i+1,nums);
            path.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        n=nums.size();
        dfs(0,nums);
        return ans;
    }
};