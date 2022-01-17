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
    long long wonderfulSubstrings(string word) {
        long long ans=0;
        long long mask=0;
        map<long long,int> counter;
        int n=word.size();
        for(int i=0;i<n;++i){
            int shift=word[i]-'a';
            long long pre_mask=mask^=(1<<shift);
            for(int j=0;j<10;++j){
                
            }
        }
    }
};