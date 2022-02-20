//
// Created by bhc on 2022/2/20.
//
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    //单调栈
    int largestRectangleArea(vector<int>& heights) {
        deque<pair<int,int>> queue;
        int n=heights.size();
        int M=0;
        for(int i=n-1;i>=0;--i){
            int counter=0;
            while(!queue.empty()&&queue.back().first>heights[i]){
                M=max(M,heights[i]*(queue.back().second+1));
                counter=max(counter,queue.back().second+1);
                queue.pop_back();
            }
            if(queue.empty()||queue.back().first!=heights[i]){
                queue.push_back({heights[i],max(counter,1)});
                M=max(M,heights[i]*(queue.back().second));
            }
            else{
                if(queue.back().first==heights[i]){
                    queue.back().second=max(queue.back().second+1,counter);
                }
            }
            for(auto & it:queue){
                if(it.first!=heights[i]){
                    it.second++;
                }
                M=max(M,it.second*it.first);
            }
        }
        return M;
    }
    //dp 解法(超时)
    int largestRectangleArea(vector<int>& heights) {
        int M=0;
        int n=heights.size();
        int global_max=0;
        for(int i=0;i<n;++i){
            M=max(M,heights[i]);
        }
        vector<int> dp(M+1);
        for(int i=1;i<=n;++i){
            for(int j=1;j<=heights[i-1];++j){
                dp[j]=dp[j]+j;
                global_max=max(global_max,dp[j]);
            }
        }
        return global_max;
    }
};