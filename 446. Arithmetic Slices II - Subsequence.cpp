//
// Created by bhc on 2022/2/10.
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
    //key index: value diff
    int ans;
    unordered_map<long,unordered_map<long,bool>> hashForDiff;
    unordered_map<long,vector<int>> hashForIndexList;
    long n;
    long diff;
    vector<int> nums;
public:
    int helper(int counter){
        return (counter-1)*(counter-2)/2;
    }
    void findAList(long index,int counter,int diff){
        if(hashForDiff[index][diff]){
            return;
        }
        if(index>=n||diff+nums[index]>INT_MAX||diff+nums[index]<INT_MIN||
                hashForIndexList[nums[index]+diff].size()==0){
            if(counter>2) {
                ans += helper(counter);
            }
            return;
        }
        vector<int> list=hashForIndexList[nums[index]+diff];
        hashForDiff[index][diff]=true;
        for(int n:list){
            if(n<=index){
                continue;
            }
            findAList(n,counter+1,diff);
        }
    }
    int numberOfArithmeticSlices(vector<int>& nums) {
        ans=0;
        n=nums.size();
        for(int i=0;i<n;++i){
            hashForIndexList[i].push_back(i);
        }
        diff=0;
        this->nums=nums;
        for(int i=0;i<n-2;++i){
            for(int j=i+1;j<n-1;++j){
                findAList(j,2,nums[j]-nums[i]);
            }
        }
        return ans;
    }
};