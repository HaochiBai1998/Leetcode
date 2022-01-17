#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
#include<set>
using namespace std;
class Solution {
    //greedyclass Solution {
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
    //sort solution
    int videoStitching(vector<vector<int>>& clips, int time) {
        int n=clips.size();
        vector<int> maxReached(time,0);
        for(int i=0;i<n;++i){
        maxReached[clips[i][0]]=max(maxReached[clips[i][0]],clips[i][1]);
        }
        int i=0;
        int counter=0;
        while(i<maxReached[i]){
            int M=i;
            for(int j=i+1;j<maxReached[i];++j){
                M=max(M,maxReached[j]);
            }
            counter++;
            if(i>=M)
                return -1;
            if(M>=time)
                break;
            i=M;
        }
        return counter;
    }
};