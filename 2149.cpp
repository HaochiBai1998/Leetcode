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
    int find(int neg_ptr,vector<int>& nums,int n){
        for(int i=neg_ptr;i<n;++i){
            if(nums[i]<0){
                return i;
            }
        }
        return n;
    }
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        int pos_ptr=0;
        int neg_ptr=0;
        neg_ptr=find(0,nums,n);
        for(int i=0;i<n;++i){
            if(i==pos_ptr){
                continue;
            }
            if(nums[i]>0){
                if(nums[pos_ptr]>0){
                    swap(nums[neg_ptr],nums[pos_ptr]);
                    neg_ptr=find(neg_ptr+1,nums,n);
                }
                swap(nums[pos_ptr],nums[i]);
                pos_ptr+=2;
            }
            else{
                while(i>=neg_ptr){
                    
                }
            }
        }
        return nums;
    }
};