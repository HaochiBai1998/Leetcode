#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
using namespace std;

class Solution {
public:
    bool isEqual(string & s, int length,int head,string & target){
        for(int i=0;i<length;++i){
            if(s[head+i]!=target[i]){
                return false;
            }
        }
        return true;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1);
        dp[0]=true;
        for(int i=1;i<=s.size();++i){
            for(string word:wordDict){
                if(dp[i-1]&&i+word.size()<=s.size()+1&&isEqual(s,word.size(),i-1,word)){
                    dp[i+word.size()-1]=true;
                }
            }
        }
        return dp[s.size()];
    }
};