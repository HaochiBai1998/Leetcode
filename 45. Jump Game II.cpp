//
// Created by bhc on 2022/2/21.
//
#include<vector>
using namespace std;
class Solution {
public:
    //贪心
    int jump(vector<int>& nums) {
        int n=nums.size();
        int counter=0;
        int end=0;
        int maxReach=0;
        for(int i=0;i<n-1;++i){
            maxReach=max(maxReach,nums[i]+i);
            if(i==end){
                end=maxReach;
                ++counter;
            }
        }
        return counter;
    }
};