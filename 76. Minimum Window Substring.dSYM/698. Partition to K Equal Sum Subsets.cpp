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

using namespace std;
class Solution {
    vector<bool> picked;
public:
    bool dfs(vector<int>& nums, int target){
        for(int i=0;i<nums.size();++i){
            if(!picked())
        }
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        picked=vector<bool>(nums.size(),false);
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;++i){
            sum+=nums[i];
        }
        if(sum%k!=0){
            return false;
        }
        int target=sum/k;
         dfs(nums,target);
    }
};