#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int maxLen=0;
        int n=nums.size();
        int neg=0;
        int subarrayLen=0;
        int index=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                subarrayLen=0;
                neg=0;
                index=-1;
            }
            if(nums[i]<0&&index==-1){
                neg++;
                index=subarrayLen;
            }
            subarrayLen++;
            if(neg%2!=0){
                maxLen=max(maxLen,subarrayLen-index);
            }
            else
                maxLen=max(maxLen,subarrayLen);
        }
        return maxLen;
    }
};