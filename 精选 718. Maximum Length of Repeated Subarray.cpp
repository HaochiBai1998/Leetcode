
//
// Created by bhc on 2022/2/17.
//
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    //dp solution
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1));
        if(nums1[n1-1]==nums2[n2-1]){
            dp[n1-1][n2-1]=1;
        }
        int global_max=0;
        for(int i=n1-1;i>=0;--i){
            for(int j=n2-1;j>=0;--j){
                if(nums1[i]==nums2[j]){
                    dp[i][j]=dp[i+1][j+1]+1;
                    global_max=max(global_max,dp[i][j]);
                }
            }
        }
        return global_max;
    }
    //滑动窗口
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        int global_max=0;
        //shift n1;
        for(int i=-n2+1;i<n1+n2-1;++i){
            int start=max(i,0);
            int end=min(i+n2-1,n1-1);
            int M=0;
            int curr_M=0;
            for(int j=start;j<=end;++j){
                if(nums1[j]==nums2[j-i]){
                    ++curr_M;
                }
                else{
                    curr_M=0;
                }
                M=max(M,curr_M);
            }
            global_max=max(global_max,M);
        }
        return global_max;
    }
};