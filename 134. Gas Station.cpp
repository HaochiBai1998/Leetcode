//
// Created by bhc on 2022/2/21.
//
#include<vector>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for(int i=0;i<gas.size();++i){
            gas[i]-=cost[i];
        }
        int minSum=INT_MAX;
        int minSumIndex=-1;
        int sum=0;
        for(int i=0;i<gas.size();++i){
            sum+=gas[i];
            if(sum<minSum){
                minSumIndex=i;
                minSum=sum;
            }
        }
        sum=0;
        for(int i=minSumIndex+1;i<=minSumIndex+gas.size();++i){
            sum+=gas[i%gas.size()];
            if(sum<0){
                return -1;
            }
        }
        return (minSumIndex+1)%gas.size();
    }
};