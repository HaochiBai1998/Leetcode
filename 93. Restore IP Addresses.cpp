
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
    string ip;
    vector<string> ans;
    string s;
public:
    bool isValidIP(int head,int tail){
        int ipSize=tail-head+1;
        if(ipSize>3){
            return false;
        }
        if(ipSize!=1&&s[head]=='0'){
            return false;
        }
        int num=stoi(s.substr(head,ipSize));
        if(num>255||num<0){
            return false;
        }
        return true;
    }
    void dfs(int index,int counter){
        int rmn=n-index;
        if(counter==4||index==n){
            if(counter==4&&index==n){
                ans.push_back(ip);
            }
        }
        if(rmn>(4-counter)*3){
            return;
        }

        string original_ip=ip;
        for(int i=index;i<index+3;++i){
            if(i>=n){
                break;
            }
            if(isValidIP(index,i)){
                ip+=(!ip.size()?"":".")+s.substr(index,i-index+1);
                dfs(i+1,counter+1);
                ip=original_ip;
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        this->s=s;
        n=s.size();
        dfs(0,0);
        return ans;
    }
};