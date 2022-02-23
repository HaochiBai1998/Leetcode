//
// Created by bhc on 2022/2/22.
//
#include<vector>
using namespace std;
class Solution {
public:
    //矮个看得到所有高个，所以从最矮的排
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n=people.size();
        sort(people.begin(),people.end(),[](vector<int>& a,vector<int> & b){
            return a[0]<b[0]||(a[0]==b[0]&&a[1]>b[1]);
        });
        vector<vector<int>> ans(n);
        for(vector<int> &p:people){
            int counter=0;
            for(int i=0;i<ans.size();++i){
                if(!ans[i].empty()){
                    counter++;
                    continue;
                }
                if(i-counter==p[1]){
                    ans[i]=p;
                    break;
                }
            }
        }
        return ans;
    }
};