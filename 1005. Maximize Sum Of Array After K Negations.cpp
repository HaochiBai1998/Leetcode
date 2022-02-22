//
// Created by bhc on 2022/2/21.
//

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        auto cmp = [](int a,int b){return a>b;};
        priority_queue<int,vector<int>,decltype(cmp)> queue(cmp);
        int sum=0;
        for(int num:nums){
            queue.push(num);
            sum+=num;
        }
        for(int i=0;i<k;++i){
            int num=queue.top();
            queue.pop();
            queue.push(-num);
            sum-=2*num;
        }
        return sum;
    }
};