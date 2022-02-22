//
// Created by bhc on 2022/2/21.
//
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    //优化版两次遍历
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> ans(n);
        ans[0]=1;
        for(int i=1;i<n;++i){
            if(ratings[i]>ratings[i-1]){
                ans[i]=ans[i-1]+1;
            }
            else{
                ans[i]=1;
            }
        }
        for(int i=n-2;i>=0;--i){
            if(ratings[i]>ratings[i+1]){
                ans[i]=max(ans[i],ans[i+1]+1);
            }
        }
        int sum=0;
        for(int num:ans){
            sum+=num;
        }
        return sum;
    }
    //优先队列，先给低权限分配
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> ans(n);
        auto cmp= [](pair<int,int> a,pair<int,int> b){
            return a.second>b.second;
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> queue(cmp);
        for(int i=0;i<n;++i){
            queue.push({i,ratings[i]});
        }
        for(int i=0;i<n;++i){
            pair<int,int> p=queue.top();
            queue.pop();
            int minCandy=1;
            if(p.first!=0&&ratings[p.first-1]<p.second){
                minCandy=max(minCandy,ans[p.first-1]+1);
            }
            if(p.first!=n-1&&ratings[p.first+1]<p.second){
                minCandy=max(minCandy,ans[p.first+1]+1);
            }
            ans[p.first]=minCandy;
        }
        int sum=0;
        for(int num:ans){
            sum+=num;
        }
        return sum;
    }
};