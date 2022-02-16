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
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> hashTable;
        vector<int> ans;
        for(int n:nums1){
            hashTable[n]++;
        }
        for(int n:nums2){
            if(hashTable[n]>0){
                ans.push_back(n);
                hashTable[n]--;
            }
        }
        return ans;
    }
};