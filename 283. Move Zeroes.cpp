//
// Created by bhc on 2022/2/9.
//

#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int curr=0;
        for(int i=0;i<n;++i){
            if(nums[i]!=0){
                nums[curr]=nums[i];
                ++curr;
            }
        }
        for(int i=curr;i<n;++i){
            nums[i]=0;
        }
    }
};