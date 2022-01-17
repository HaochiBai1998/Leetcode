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
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n=dist.size();
        vector<double> times(n,0);
        for(int i=0;i<n;++i){
            times[i]=(double)dist[i]/speed[i];
        }
        sort(times.begin(),times.end());
        for(int i=1;i<n;++i){
            if(times[i]<=i)
                return i;
            
        }
        return n;
    }
};