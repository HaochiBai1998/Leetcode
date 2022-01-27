
#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
#include<math.h>
#include<unordered_set>
#include<queue>
using namespace std;

class Solution {
public:
    unordered_map<string,int> dead;
    string target;
    int openLock(vector<string>& deadends, string target) {
        this->target=target;
        queue<pair<string,int>> q;
        q.push({"0000",0});
        while(!q.empty()){
            pair<string,int> element=q.front();
            string str=element.first;
            int counter=element.second;
            if(dead[str]!=0){
                continue;
            }
            if(str==target){
                return counter;
            }
            q.pop();
            for(int i=0;i<4;++i){
                string curr_str=str;
                char next_c=str[i]+1;
                char prev_c=str[i]-1;
                if(next_c<='9'){
                    curr_str[i]=next_c;
                    q.push({curr_str,counter+1});
                    dead[curr_str]++;
                }
                if(prev_c!='0'){
                    if(prev_c<'0'){
                        prev_c+=10;
                    }
                    curr_str[i]=prev_c;
                    q.push({curr_str,counter+1});
                    dead[curr_str]++;
                }
            }
        }
        return -1;
    }
};