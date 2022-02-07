//
// Created by bhc on 2022/2/8.
//


#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
#include<set>
#include<queue>

using namespace std;


class Solution {
public:
    //哈希存找过的数，O(N)space
    //摩尔投票
    int majorityElement(vector<int>& nums) {
        int counter=0;
        int maxNum =nums[0];
        for(int n:nums){
            if(n!=maxNum){
                if(counter==0){
                    maxNum=n;
                }
                else{
                    counter--;
                }
            }
            else{
                counter++;
            }
        }
        return maxNum;
    }
};