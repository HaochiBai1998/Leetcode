
#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
#include<set>
using namespace std;

class Solution {
    vector<int> numbers;
    vector<vector<int>> ans;
    vector<bool> reached;
    vector<int> path;
    int n;
public:
    void dfs(int counter){
        if(counter==n){
            ans.push_back(path);
            return;
        }
        for(int i=0;i<n;++i){
            if(reached[i]==true)
                continue;
            if(i>0&&numbers[i]==numbers[i-1]&&reached[i-1]==false)
                continue;
            path.push_back(numbers[i]);
            reached[i]=true;
            dfs(counter+1);
            reached[i]=false;
            path.pop_back();
        }
        return;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        numbers=nums;
        n=nums.size();
        vector<bool> reached(n,false);
        this->reached=reached;
        dfs(0);
        return ans;
    }
};