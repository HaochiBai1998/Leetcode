#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
class Solution {
public:
    int SumUp(vector<int> & array){
        int ans=0;
        for(int i=0;i<array.size();i++){
            ans+=array[i];
        }
        return ans;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > ans;
        stack<vector<int> > q;
        sort(candidates.begin(),candidates.end());
        for(int i=0;i<candidates.size();i++){
            q.push(vector<int>(1,candidates[i]));
        }
        while(!q.empty()){
            vector<int> buf=q.top();
            q.pop();
            int sum=SumUp(buf);
            if(sum==target){
                ans.push_back(buf);
            }
            for(int j=0;j<candidates.size();j++){
                if(candidates[j]>buf[buf.size()-1]||sum+candidates[j]>target){
                    continue;
                }
                buf.push_back(candidates[j]);
                if(sum+candidates[j]<target){
                    q.push(buf);
                }
                else{
                    ans.push_back(buf);     
                }
                buf.pop_back();
            }
        }
        return ans;
    }
};