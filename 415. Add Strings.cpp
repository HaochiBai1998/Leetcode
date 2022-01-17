
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
    string addStrings(string num1, string num2) {
        int m=num1.size();
        int n=num2.size();
        if(n>m){
            swap(num1,num2);
            swap(m,n);
        }
        string rnt;
        int cout=0;
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        for(int i=0;i<m;++i){
            int tmp=i<n?(num1[i]-'0')+(num2[i]-'0')+cout:(num1[i]-'0')+cout;
            rnt+=tmp%10+'0';
            cout=tmp/10;
        }
        if(cout==1)
            rnt+='1';
        reverse(rnt.begin(),rnt.end());
        return rnt;
    }
};