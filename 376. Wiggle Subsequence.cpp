//
// Created by bhc on 2022/2/21.
//
#include<vector>
#include<algorithm>
using namespace std;class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n-1;++i){
            nums[i]=nums[i+1]-nums[i];
        }
        int M=0;
        int counter=0;
        int prev=0;
        int i=0;
        while(i<n-1&&nums[i]==0){
            ++i;
        }
        for(int j=i;j<n-1;++j){
            if(j==i||prev*nums[j]<0){
                ++counter;
                prev=nums[j];
            }
        }
        return counter+1;
    }
};