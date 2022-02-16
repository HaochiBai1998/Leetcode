
#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
#include<math.h>
#include<unordered_set>
#include<queue>
#include<unordered_map>
using namespace std;
class Solution {
    string s;
    vector<string> path;
    vector<vector<string>> ans;
    unordered_map<int,unordered_map<int,bool>> hashTable;
    int n;
public:
    //深搜+回溯+哈希记录回文
    bool isPalindrome(int head,int tail){
        while(head<tail){
            if(s[head]!=s[tail]){
                return false;
            }
            head++;
            tail--;
        }
        hashTable[head][tail]=true;
        return true;
    }
    void dfs(int index){
        if(index==n){
            ans.push_back(path);
            return;
        }
        for(int i=index;i<n;++i){
            if(hashTable[index][i]||isPalindrome(index,i)){
                path.push_back(s.substr(index,i-index+1));
                dfs(i+1);
                path.pop_back();
            }
        }
        return;
    }
    vector<vector<string>> partition(string s) {
        n=s.size();
        this->s=s;
        dfs(0);
        return ans;
    }
};