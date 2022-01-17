#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
#include<set>
using namespace std;

class Solution {
public:
    //prefix+postfix & mapping solution
    vector<long long> getDistances(vector<int>& arr) {
        map<long long,vector<long long>> counter;
        long long n=arr.size();       
        vector<long long> ans(n,0);
        for(int i=0;i<n;++i){
            counter[arr[i]].push_back(i);
        }
        for(auto itMap=counter.begin();itMap!=counter.end();++itMap){
            long long n=itMap->second.size();
            vector<long long> prefix(n+1,0);
            vector<long long> postfix(n+1,0);
            for(int i=1;i<n;++i){
                prefix[i]=prefix[i-1]+itMap->second[i-1];
            }
            for(int i=n-1;i>=0;--i){
                postfix[i]=postfix[i+1]+itMap->second[i];
            }
            for(int i=0;i<n;++i){
                long long ll=itMap->second[i];
                ans[ll]=ll*i-prefix[i]+postfix[i]-ll*(n-i);
            }
        }
        return ans;
    }
};