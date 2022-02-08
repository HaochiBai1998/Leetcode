//
// Created by bhc on 2022/2/8.
//

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
#include<unordered_map>
#include<assert.h>
using namespace std;

class Solution {
public:
    //滑动窗口解法
    bool isValid(unordered_map<char, int> & counterS,unordered_map<char, int> &counterT){
        for(auto &it: counterT){
            if(counterS[it.first]<it.second){
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        int sSize=s.size();
        int tSize=t.size();
        if(sSize<tSize){
            return "";
        }
        int left=0;
        int right=tSize-1;
        unordered_map<char, int> counterS;
        unordered_map<char, int> counterT;
        for(char c:t){
            counterT[c]++;
        }
        for(int i=left;i<=right;++i){
            if(counterT.count(s[i])){
                counterS[s[i]]++;
            }
        }
        string ans;
        int minWindowSize=sSize+1;
        while(right<sSize){
            int windowSize=right-left+1;
            if(isValid(counterS,counterT)){
                if(minWindowSize>windowSize){
                    ans=s.substr(left,windowSize);
                    minWindowSize=windowSize;
                }
                if(counterT.count(s[left])){
                    counterS[s[left]]--;
                }
                left++;
            }
            else{
                right++;
                if(right!=sSize&&counterT.count(s[right])){
                    counterS[s[right]]++;
                }
            }
        }
        return ans;
    }
};


int main(){
    Solution s;
    string str="cfabeca";
    string str2="ace";
    str="aa";
    str2="a";
    cout<<s.minWindow(str,str2)<<endl;
    return EXIT_SUCCESS;
}