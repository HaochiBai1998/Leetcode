
#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
using namespace std;


class Solution {
    vector<vector<int>> ans;
    vector<int>path;
    int n;
    int k;
public:
    void dfs(int prev,int rmn){
        if(rmn==0){
            ans.push_back(path);
            return;
        }
        for(int i=prev+1;i<=n-rmn+1;++i){
            path.push_back(i);
            dfs(i,rmn-1);
            path.pop_back();
        }
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        this->n=n;
        this->k=k;
        dfs(0,k);
        return ans;
    }
};