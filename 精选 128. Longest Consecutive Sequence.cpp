
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
    int longestConsecutive(vector<int>& nums){
        unordered_map<int,bool> hashTable;
        for(int n: nums){
            hashTable[n]=true;
        }
        int longest=0;
        int n=hashTable.size();
        for(int i=0;i<nums.size();++i){
            int counter=0;
            if(!hashTable[nums[i]]){
                continue;
            }
            if(hashTable[nums[i]-1]){
                continue;
            }
            int j=0;
            while(hashTable[nums[i]+j]){
                hashTable[nums[i]+j]=false;
                j++;
            }
            longest=max(longest,j);
        }
        return longest;
    }
};