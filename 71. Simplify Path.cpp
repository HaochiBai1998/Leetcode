
#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
using namespace std;

class Solution {
public:
    enum{
        START,
        END
    };
    string simplifyPath(string path) {
        stack<string> s;
        int status=START;
        int left=0;
        int right=0;
        string tmp;
        for(char c:path){
            if(c=='/'&&status==START){
                continue;
            }
            else if(c=='/'&&status==END){
                if(tmp!="."&&tmp!="") s.push(tmp);
                status=START;
                tmp.clear();
            }
            else{
                status=END;
                tmp+=c;
            }
        }
        if(tmp!="."&&tmp!="")   s.push(tmp);
        string ans;
        int counter=0;
        while(!s.empty()){
            string tmp=s.top();
            s.pop();
            if(tmp==".."){
                counter++;
            }   
            else{
                if(counter==0)
                    ans='/'+tmp+ans;
                else
                    counter--;
            }
        }
        if(ans=="")
            ans="/";
        return ans;
    }
};
class Solution {
public:
    string simplifyPath(string path) {
        auto split = [](const string& s, char delim) -> vector<string> {
            vector<string> ans;
            string cur;
            for (char ch: s) {
                if (ch == delim) {
                    ans.push_back(move(cur));
                    cur.clear();
                }
                else {
                    cur += ch;
                }
            }
            ans.push_back(move(cur));
            return ans;
        };

        vector<string> names = split(path, '/');
        vector<string> stack;
        for (string& name: names) {
            if (name == "..") {
                if (!stack.empty()) {
                    stack.pop_back();
                }
            }
            else if (!name.empty() && name != ".") {
                stack.push_back(move(name));
            }
        }
        string ans;
        if (stack.empty()) {
            ans = "/";
        }
        else {
            for (string& name: stack) {
                ans += "/" + move(name);
            }
        }
        return ans;
    }
};