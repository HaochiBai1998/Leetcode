#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> minCost(n+1,-1);
        stack<int> stack;
        stack.push(0);
        stack.push(1);
        minCost[0]=0;
        minCost[1]=0;
        while(!stack.empty()){
            int num=stack.top();
            stack.pop();
            if(num>n-1)
                continue;                
            int currSum=minCost[num]+cost[num];
            if(num+1<=n){
                if(minCost[num+1]==-1||minCost[num+1]>currSum){
                    minCost[num+1]=currSum;
                    stack.push(num+1);
                }
            }
            if(num+2<=n){
                if(minCost[num+2]==-1||minCost[num+2]>currSum){
                    minCost[num+2]=currSum;
                    stack.push(num+2);
                }
            }
        }
        return minCost[n];
    }
};