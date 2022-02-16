
#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
using namespace std;

class Solution {
    int k;
    int n;
    vector<vector<int>> ans;
    vector<int> path;
public:
    void dfs(int index,int counter){
        if(counter==k){
            ans.push_back(path);
            return;
        }
        for(int i=index;i<=n-(k-counter);++i){
            path.push_back(i+1);
            dfs(i+1,counter+1);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        this->n=n;
        this->k=k;
        vector<int> nums(n);
        for(int i=0;i<n;++i){
            nums[i]=i+1;
        }
        dfs(0,0);
        return ans;
    }
};