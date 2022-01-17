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
    //sort+merge solution
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        vector<int> curr=intervals[0];
        int n=intervals.size();
        for(int i=1;i<n;++i){
            if(curr[1]>=intervals[i][0]){
                curr[1]=max(intervals[i][1],curr[1]);
            }
            else{
                ans.push_back(curr);
                curr=intervals[i];
            }
        }
        ans.push_back(curr);
        return ans;
    }
};
