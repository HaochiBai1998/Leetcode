
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
    string reverseWords(string s) {
        int n=s.size();
        int head=0;
        int tail;
        reverse(s.begin(),s.end());
        int i=0;
        while(i<n){
            while(i<n&&s[i]!=' '){
                ++i;
            }
            tail=i;
            reverse(s.begin()+head,s.begin()+tail);
            while(i<n&&s[i]==' '){
                ++i;
            }
            head=i;
        }
        tail=0;
        i=0;
        while(i<n){
            while(i<n&&s[i]==' '){
                ++i;
            }
            while(i<n&&s[i]!=' '){
                s[tail]=s[i];
                ++i;
                ++tail;
            }
            if(i!=n){
                s[tail]=s[i];
                ++tail;
                ++i;
            }
        }
        if(s[tail-1]==' '){
            tail--;
        }
        return s.substr(0,tail);
    }
};