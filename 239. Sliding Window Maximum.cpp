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
        //双向队列解法 BestSolution
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            deque<int> que;
            vector<int> ans;
            int n=nums.size();
            if(k==1){
                return nums;
            }
            for(int i=0;i<k;++i){
                while(!que.empty()&&nums[que.back()]<nums[i]){
                    que.pop_back();
                }
                que.push_back(i);
            }
            ans.push_back(nums[que.front()]);
            for(int i=k;i<n;++i){
                while(!que.empty()&&nums[que.back()]<nums[i]){
                    que.pop_back();
                }
                que.push_back(i);
                while(que.front()<=i-k){
                    que.pop_front();
                }
                ans.push_back(nums[que.front()]);
            }
            return ans;
        }
        //优先队列解法
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            priority_queue<pair<int,int>> que;
            vector<int> ans;
            if(k==1){
                return nums;
            }
            for(int i=0;i<k;++i){
                que.push({nums[i],i});
            }
            int n=nums.size();
            for(int i=0;i<=n-k;++i){
                auto tmp=que.top();
                while(tmp.second<i){
                    que.pop();
                    tmp=que.top();
                }
                ans.push_back(tmp.first);
                if(i+k==n){
                    break;
                }
                que.push({nums[i+k],i+k});
            }
            return ans;
        }
        //哈希表写法
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            int n=nums.size();
            map<int,int> hashTable;
            if(k==1){
                return nums;
            }
            for(int i=0;i<k;++i){
                hashTable[nums[i]]++;
            }
            vector<int> ans;
            for(int i=0;i<=n-k;++i){
                ans.push_back(hashTable.rbegin()->first);
                if(i==n-k){
                    break;
                }
                int next=nums[i+k];
                hashTable[next]++;
                hashTable[nums[i]]--;
                if(hashTable[nums[i]]==0){
                    hashTable.erase(nums[i]);
                }
            }
            return ans;
        }
    };