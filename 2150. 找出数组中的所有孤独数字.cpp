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
    vector<int> findLonely(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        unordered_map<int,int> hashTable;
        for(auto & it: nums){
            hashTable[it]++;
        }
        for(auto & it: hashTable){
            if(hashTable[it.first-1]||hashTable[it.first+1]||it.second!=1){
                continue;
            }
            ans.push_back(it.first);
        }
        return ans;
    }
};