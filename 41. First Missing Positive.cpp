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
    //原地哈希解法

    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        bool isZeroIndexed=false;
        for(int i=0;i<n;++i){
            if(nums[i]<=0){
                nums[i]=INT_MAX;
            }
        }
        for(int i=0;i<n;++i){
            int num=abs(nums[i]);
            if(num<=n&&num>0){
                nums[num-1]=nums[num-1]>0?-nums[num-1]:nums[num-1];
            }
        }
        for(int i=0;i<n;++i){
            if(nums[i]>0||(nums[i]==0&&!isZeroIndexed)){
                return i+1;
            }
        }
        return n+1;
    }
};