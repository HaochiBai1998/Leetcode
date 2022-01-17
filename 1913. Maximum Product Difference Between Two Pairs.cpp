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
    int maxProductDifference(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        return nums[n-1]*nums[n-2]-nums[0]*nums[1];
    }
};