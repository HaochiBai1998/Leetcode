//
// Created by bhc on 2022/2/8.
//


#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
#include<set>
#include<queue>

using namespace std;

class Solution {
public:
    //queue，当有重复，把队列前面所有重复数字踢掉
    int firstUniqChar(string s) {
        unordered_map<char, int> position;
        queue<pair<char, int>> q;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (!position.count(s[i])) {
                position[s[i]] = i;
                q.emplace(s[i], i);
            }
            else {
                position[s[i]] = -1;
                while (!q.empty() && position[q.front().first] == -1) {
                    q.pop();
                }
            }
        }
        return q.empty() ? -1 : q.front().second;
    }
    //哈希获得索引，第二次遍礼哈希表
    class Solution {
    public:
        int firstUniqChar(string s) {
            unordered_map<char, int> hashTable;
            for(int i=0;i<s.size();++i){
                if(!hashTable.count(s[i])){
                    hashTable[s[i]]=i;
                }
                else{
                    hashTable[s[i]]=-1;
                }
            }
            int M=INT_MAX;
            for(auto &it: hashTable){
                if(it.second==-1){
                    continue;
                }
                M=min(M,it.second);
            }
            return M==INT_MAX?-1:M;
        }
    };
    //哈希获得每个数字counter
    int firstUniqChar(string s) {
        unordered_map<char, int> hashTable;
        for(char c: s){
            hashTable[c]++;
        }
        for(int i=0;i<s.size();++i){
            if(hashTable[s[i]]<=1){
                return i;
            }
        }
        return -1;
    }
};