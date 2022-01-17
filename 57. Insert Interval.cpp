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
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int left=newInterval[0];
        int right=newInterval[1];
        int n=intervals.size();
        for(int i=0;i<n;++i){
            if(intervals[i][1]<newInterval[0]||intervals[i][0]>newInterval[1]){
                ans.push_back(intervals[i]);
            }
            else{
                right=max(right,max(newInterval[1],intervals[i][1]));
                left=min(left,min(newInterval[0],intervals[i][0]));
            }
        }
        ans.push_back({left,right});
        sort(ans.begin(),ans.end());
        return ans;
    }
};