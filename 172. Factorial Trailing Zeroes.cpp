
#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int ans=0;
        while(n/5!=0)   ans+=n/=5;
        return ans;
    }
};