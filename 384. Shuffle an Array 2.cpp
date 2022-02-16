//
// Created by bhc on 2022/2/9.
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
    vector<int> original_nums;
public:
    Solution(vector<int>& nums) {
        original_nums.resize(nums.size());
        copy(nums.begin(),nums.end(),original_nums.begin());
    }

    vector<int> reset() {
        return original_nums;
    }

    vector<int> shuffle() {
        int n=original_nums.size();
        vector<int> ans(n,0);
        copy(original_nums.begin(),original_nums.end(),ans.begin());
        for(int i=0;i<n;++i){
            int index=rand()%(n-i)+i;
            swap(ans[index],ans[i]);
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */