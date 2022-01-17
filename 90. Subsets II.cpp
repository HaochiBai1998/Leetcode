
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
    int n;
public:
    void dfs(vector<vector<int>>& ans,vector<int>& nums,int index,int rmn){
        if(rmn==0){
            ans.push_back(path);
            return;
        }
        if(index==n){
            return;
        }
        for(int i=index;i<n;++i){
            if(i==index||nums[i]!=nums[i-1]){
                path.push_back(nums[i]);
                dfs(ans,nums,i+1,rmn-1);
                path.pop_back();
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        n=nums.size();
        for(int i=0;i<=n;++i){
            dfs(ans,nums,0,i);
        }
        return ans;
    }
};