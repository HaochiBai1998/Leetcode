//
// Created by bhc on 2022/2/22.
//

#include<vector>
using namespace std;
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        sort(points.begin(),points.end(),[](vector<int> & a,vector<int> & b){
            return a[0]<b[0]||(a[0]==b[0]&&a[1]<b[1]);
        });
        int counter=0;
        for(int i=0;i<n;++i){
            int curr_tail=points[i][1];
            while(i<n&&curr_tail>=points[i][0]){
                curr_tail=min(curr_tail,points[i][1]);
                ++i;
            }
            --i;
            ++counter;
        }
        return counter;
    }
};