//
// Created by bhc on 2022/2/11.
//



#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
using namespace std;


class Solution {
    string path;
    vector<string> ans;
    string digits;
    vector<string> ref;
    int n;
public:
    void dfs(int index){
        if(index==n){
            ans.push_back(path);
            return;
        }
        string str=ref[digits[index]-'2'];
        string original_path=path;
        for(char c:str){
            path+=c;
            dfs(index+1);
            path=original_path;
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0){
            return ans;
        }
        ref={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        this->digits=digits;
        n=digits.size();
        dfs(0);
        return ans;
    }
};