
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
    vector<vector<string>> mem;
public:
    isPalindrome(string& s, int left,int right);
    vector<vector<string>> partition(string s) {
        int n=s.size();
        mem=vector<vector<string>>(n);
        
    }
};