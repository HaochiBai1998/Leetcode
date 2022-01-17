
#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
#include<set>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        vector<vector<string>> ans;
        map<string,vector<string>> m;
        for(int i=0;i<n;++i){
            string tmp=strs[i];
            sort(tmp.begin(),tmp.end());
            m[tmp].push_back(strs[i]);
        }
        for(auto it=m.begin();it!=m.end();++it){
            ans.push_back(it->second);
        }
        return ans;
    }
};