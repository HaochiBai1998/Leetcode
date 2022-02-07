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
    //sort
    //哈希存看是否重复
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,bool> hashMap;
        for(int n:nums){
            if(hashMap[n]){
                return true;
            }
            hashMap[n]=true;
        }
        return false;
    }
};