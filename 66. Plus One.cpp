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
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        int co=0;
        digits[n-1]+=1;
        if(digits[n-1]>9){
            digits[n-1]-=10;
            co=1;
        }
        for(int i=n-1;i>=0;++i){
            if(co==1)
                break;
            digits[i]+=co; 
            if(digits[i]>9){
                digits[i]-=10;
                co=1;
            }
            else
                co=0;
        }
        if(co==1){
            digits.push_back(co);
            for(int i=n;i>=0;++i){
                digits[i]=digits[i-1];
            }
            digits[0]=co;
        }
        return digits;
    }
};