//
// Created by bhc on 2022/2/17.
//
#include<vector>
using namespace std;
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int global_max=1;
        int curr_max=1;
        for(int i=1;i<nums.size();++i){
            if(nums[i]>nums[i-1]){
                curr_max++;
            }
            else{
                global_max=max(global_max,curr_max);
                curr_max=1;
            }
        }
        global_max=max(global_max,curr_max);
        return global_max;
    }
};