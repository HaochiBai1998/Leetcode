//
// Created by bhc on 2022/2/20.
//
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> ans(n);
        deque<int> queue;
        for(int i=n-1;i>=0;--i){
            while(!queue.empty()&&temperatures[queue.back()]<=temperatures[i]){
                queue.pop_back();
            }
            if(queue.empty()){
                ans[i]=0;
            }
            else{
                ans[i]=queue.back()-i;
            }
            queue.push_back(i);
        }
        return ans;
    }
};