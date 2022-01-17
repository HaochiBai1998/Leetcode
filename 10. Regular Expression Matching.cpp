
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
    string s;
    string p;
    int sSize;
    int pSize;
public:
    bool dfs(int s_index,int p_index){
        if(s_index==-1&&p_index==-1){
            return true;
        }
        if(s_index==-1){
            for(int i=s_index;i>=0;--i){
                if(s[i]!='*'){
                    return false;
                }
            }
            return true;
        }
        if(p_index==-1){
            return false;
        }
        if(p[p_index]=='.'||p[p_index]==s[s_index]){
            return dfs(s_index-1,p_index-1);
        }
        else if(p[p_index]=='*'){
            if(p_index==0){
                return false;
            }
            int prev=p[p_index-1];
            if(prev=='*'){
                return dfs(s_index,p_index-1);
            }
            bool ans=dfs(s_index,p_index-1);
            int i=1;
            while(s_index-i>=0&&prev==s[s_index-i]){
                ans=ans|dfs(s_index=i,p_index-2);
                ++i;
            }
            return ans;
        }
        else
            return false;
    }
    bool isMatch(string s, string p) {
        this->s=s;
        sSize=s.size();
        this->p=p;
        pSize=p.size();
        dfs(sSize-1,pSize-1);
    }
};