//
// Created by bhc on 2022/2/20.
//
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        deque<int> que;
        int n2=nums2.size();
        unordered_map<int,int> hashtable;
        vector<int> ans(nums1.size());
        for(int i=n2-1;i>=0;--i){
            while(!que.empty()&&nums2[que.back()]<=nums2[i]){
                que.pop_back();
            }
            if(que.empty()){
                hashtable[nums2[i]]=-1;
            }
            else{
                hashtable[nums2[i]]=nums2[que.back()];
            }
            que.push_back(i);
        }
        for(int i=0;i<nums1.size();++i){
            ans[i]=hashtable[nums1[i]];
        }
        return ans;
    }
};