
#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
#include<set>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int twoIndex=n-1;
        int index=0;
        while(index<twoIndex){
            while(twoIndex>index&&nums[twoIndex]==2)
                --twoIndex;
            while(twoIndex>index&&nums[index]!=2)
                ++index;
            if(index<twoIndex){
                swap(nums[index],nums[twoIndex]);
            }
        }
        int oneIndex=twoIndex;
        index=0;
        while(index<oneIndex){
            while(oneIndex>index&&nums[oneIndex]==1)
                --oneIndex;
            while(oneIndex>index&&nums[index]!=1)
                ++index;
            if(index<oneIndex){
                swap(nums[index],nums[oneIndex]);
            }
        }
        return;
    }
};