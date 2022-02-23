//
// Created by bhc on 2022/2/22.
//
#include<vector>
using namespace std;
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](vector<int> & a, vector<int> & b){
            return a[0]<b[0]||(a[0]==b[0]&&a[1]<b[1]);
        });
        int right=INT_MIN;
        int counter=0;
        for(int i=0;i<intervals.size();++i){
            if(right<=intervals[i][0]){
                right=intervals[i][1];
            }
            else{
                right=min(intervals[i][1],right);
                ++counter;
            }
        }
        return counter;
    }
};