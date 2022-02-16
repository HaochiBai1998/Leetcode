//
// Created by bhc on 2022/2/9.
//


#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
#include<set>
#include<queue>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zeroCounter=0;
        int productExceptZero=1;
        int n=nums.size();
        for(int i=0;i<n;++i){
            if(nums[i]==0){
                zeroCounter++;
            }
            else{
                productExceptZero*=nums[i];
            }
        }
        for(int i=0;i<n;++i){
            if(zeroCounter==0){
                nums[i]=productExceptZero/nums[i];
            }
            else{
                if(nums[i]==0&&zeroCounter==1){
                    nums[i]=productExceptZero;
                    continue;
                }
                nums[i]=0;
            }
        }
        return nums;
    }
};