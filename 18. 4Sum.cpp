
#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
#include<set>
using namespace std;

class Solution {
    vector<vector<int>> ans;
    int a;
    int b;
    int c;
    int d;
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n-3;++i){
            if((long)nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target)
                return ans;
            if((long)nums[i]+nums[n-1]+nums[n-2]+nums[n-3]<target)
                continue;
            if(i>0&&nums[i]==nums[i-1])
                continue;
            a=nums[i];
            for(int j=n-1;j>=i+3;--j){
                if((long)nums[j]+nums[j-1]+nums[j-2]+nums[j-3]<target)
                    return ans;
                if((long)nums[j]+nums[i]+nums[i+1]+nums[i+2]>target)
                    continue;
                if(j<n-1&&nums[j]==nums[j+1])
                    continue;
                d=nums[j];
                int head=i+1;
                int tail=j-1;
                while(head+1<=tail){
                    b=nums[head];
                    c=nums[tail];
                    if((long)a+b+c+d>target){
                        while(tail!=j-1&&head<=tail-1&&nums[tail]==nums[tail+1])
                            --tail;
                    }
                    else if((long)a+b+c+d<target){
                        while(head!=i+1&&head<=tail-1&&nums[head]==nums[head-1])
                            ++head;
                    }
                    else{
                        vector<int> tmp(4,0);
                        tmp[0]=a;
                        tmp[1]=b;
                        tmp[2]=c;
                        tmp[3]=d;
                        ans.push_back(tmp);
                        --tail;
                        ++head;
                    }
                }
            }
        }
        return ans;
    }
};