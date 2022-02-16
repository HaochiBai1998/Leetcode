//
// Created by bhc on 2022/2/11.
//


#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
#include<math.h>
#include<unordered_map>

using namespace std;
class Solution {
    vector<vector<int>> ans;
    vector<int> path;
    int n;
public:
    void dfs(int index,vector<int> & nums,int counter){
        if(counter>=2){
            ans.push_back(path);
        }
        if(index==n){
            return ;
        }
        unordered_map<int,bool> hashtable;
        for(int i=index;i<n;++i){
            if(hashtable.count(nums[i])){
                continue;
            }
            hashtable[nums[i]]=true;
            if(path.size()==0||path.back()<=nums[i]){
                path.push_back(nums[i]);
                dfs(i+1,nums,counter+1);
                path.pop_back();
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        n=nums.size();
        dfs(0,nums,0);
        return ans;
    }
};