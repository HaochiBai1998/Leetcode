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
    bool isValid(string s) {
        stack<char> q;
        for(int i=0;i<s.size();++i){
            if(s[i]==']'){
                if(q.empty()||q.top()!='[')
                    return false;
                else
                    q.pop();
            }
            else if(s[i]=='}'){
                if(q.empty()||q.top()!='{')
                    return false;
                else
                    q.pop();
            }
            else if(s[i]==')'){
                if(q.empty()||q.top()!='(')
                    return false;
                else
                    q.pop();
            }
            else
                q.push(s[i]);
        }
        if(q.empty())
            return true;
        else
            return false;
    }
};