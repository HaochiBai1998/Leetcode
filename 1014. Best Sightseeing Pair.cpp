#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;


class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size();
        int ans=0;
        int M=values[0]-1;
        int M2=values[1];
        ans=M+M2;
        if(M2>M)
            swap(M,M2);
        for(int i=2;i<n;i++){
            M--;
            M2--;
            if(values[i]>=M){
                M2=M;
                M=values[i];
            }
            else if(values[i]>M2){
                M2=values[i];
            }
            ans=max(ans,M+M2);
        }
        return ans;
    }
};