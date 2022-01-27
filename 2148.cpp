#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
#include<math.h>
#include<unordered_set>
#include<queue>
using namespace std;
class Solution {
public:
    int countElements(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int prev_max=nums[n-1];
        int prev_min=nums[0];
        int i=0;
        while(nums[i]==prev_min){
            i++;
        }
        int j=n-1;
        while(nums[j]==prev_max){
            --j;
        }
        return j>i?j-i+1:0;
    }
};