#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
#include<set>
using namespace std;

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        map<int,int> map;
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;++i){
            map[nums[i]]++;
        }      
        auto it=map.end();
        --it;
        while(it!=map.begin()){
            int temp=it->second;
            ans+=temp;
            --it;
            it->second+=temp;
        }
        return ans;
    }
};