#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=0;
        int minDiff=13000;
        for(int i=0;i<n-2;++i){
            int tail=n-1;
            int head=i+1;
            while(tail>head){
                int tmp=nums[head]+nums[tail]+nums[i];
                int diff=abs(tmp-target);
                if(diff==0)
                    return target;
                if(diff<minDiff){
                    minDiff=diff;
                    ans=tmp;
                }
                if(target>tmp){
                    head++;
                    continue;
                }
                tail--;
            }
        }
        return ans;
    }
};