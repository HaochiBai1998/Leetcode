#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
using namespace std;
class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        vector<int> dp_1(n,0);
        vector<int> dp_2(n,0);
        dp_1[0]=(s[0]=='0'?0:1);
        for(int i=1;i<n;i++){
            if(s[i-1]=='1'||(s[i-1]=='2'&&s[i]<='6')){
                dp_2[i]=dp_1[i-1];
            }
            if(s[i]!='0')
                dp_1[i]=dp_1[i-1]+dp_2[i-1];
        }
        return dp_1[n-1]+dp_2[n-1];
    }
};