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
    int minFlips(string s) {
        int count0=0;
        int count1=0;
        int n=s.size();
        char curr='0';
        vector<int> pre0(n+1,0);
        vector<int> pre1(n+1,0);
        for(int i=0;i<n;++i){
            if(s[i]!=curr)
                count0++;
            else
                count1++;
            if(curr=='0')
                curr='1';
            else
                curr='0';
            pre0[i+1]=count0;
            pre1[i+1]=count1;
        }
        count0=0;
        count1=0;
        curr='0';
        for(int i=n-1;i>=0;--i){
            if(s[i]!=curr)
                count0++;
            else
                count1++;
            if(curr=='0')
                curr='1';
            else
                curr='0';
            pre1[i]+=count0;
            pre0[i]+=count1;
        }
        int M=n;
        for(int i=0;i<=n;++i){
            M=min(M,min(pre0[i],pre1[i]));
        }
        return M;
    }
};