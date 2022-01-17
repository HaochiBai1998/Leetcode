
#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
#include<math.h>
#include<unordered_set>
using namespace std;

class Solution {
    int n;
    string IP;
    int IPSize;
public: 
    //dfs+ backtracking
    void dfs(vector<string> & ans,string & s,int index){
        if(index>=n||IPSize==4){
            if(index>=n&&IPSize==4)
                ans.push_back(IP);
            return;
        }
        for(int i=1;i<4;++i){
            if(i+index>n){
                continue;
            }
            string str=s.substr(index,i);
            int num=stoi(str);
            if(num<=255&&num>=0){
                string tmp=IP;
                if(to_string(num)!=str){
                    continue;
                }
                IP=IP+(IP==""?"":".")+str;
                ++IPSize;
                dfs(ans,s,index+i);
                IP=tmp;
                --IPSize;
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        n=s.size();
        IPSize=0;
        dfs(ans,s,0);
        return ans;
    }
};