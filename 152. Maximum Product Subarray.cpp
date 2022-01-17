#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();  
        int maxProduct=0;
        int currProduct=0;
        int buffer=0;
        for(int i=0;i<n;i++){
            currProduct==0?currProduct+=nums[i]:currProduct*=nums[i];
            if(currProduct<0&&nums[i]>0){
                buffer==0?buffer+=nums[i]:buffer*=nums[i];
            }
            else if(currProduct<0&&nums[i]<0){
                buffer=0;
            }
            maxProduct=max(maxProduct,currProduct);
            maxProduct=max(maxProduct,buffer);
        }
        return maxProduct;
    }
};