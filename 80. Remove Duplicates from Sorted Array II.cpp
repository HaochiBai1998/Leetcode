
#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
using namespace std;

class Solution {
public:
    //index solution
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int index=1;
        int counter=1;
        for(int i=1;i<n;++i){
            if(nums[i]==nums[i-1]){
                if(counter>=2){
                    continue;
                }
                counter++;
            }
            else{
                counter=1;
            }
            nums[index]=nums[i];
            index++;
        }
        return index;
    }
};