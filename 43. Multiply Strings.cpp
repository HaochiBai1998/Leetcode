
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
    //optimized solution
    int getSum(vector<int> & nums){
        int sum=0;
        for(auto it=nums.begin();it!=nums.end();++it){
            sum+=*it;
        }
        return sum;
    }
    string multiply(string num1, string num2) {
        int m=num1.size();
        int n=num2.size();
        string ans;
        vector<vector<int>> nums(m+n);
        for(int i=m-1;i>=0;--i){
            for(int j=n-1;j>=0;--j){
                int number=(num1[i]-'0')*(num2[j]-'0');
                nums[(n-1-j)+(m-1-i)].push_back(number%10);
                nums[(n-1-j)+(m-1-i)+1].push_back(number/10);
            }
        }
        int n=nums.size();
        int cout=0;
        for(int i=n-1;i>=0;--i){
            int tmp=getSum(nums[i])+cout;
            ans+=tmp+'0';
            cout=tmp/10;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    //add solution
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
    string multiply(string num1, string num2) {
        int cout=0;
        string ans;
        int m=num1.size();
        int n=num2.size();
        for(int i=0;i<m;++i){
            string tmp;
            cout=0;
            for(int j=n-1;j>=0;--j){
                int number=(num1[i]-'0')*(num2[j]-'0')+cout;
                cout=number/10;
                tmp+=number%10+'0';
            }
            if(cout!=0)
                tmp+=(cout+'0');
            reverse(tmp.begin(),tmp.end());
            for(int j=0;j<m-i-1;++j){
                tmp+='0';
            }
            ans=addStrings(ans,tmp);
        }
        int n=ans.size();
        while(ans[0]!='0'){
            if(n!=1){
                ans.erase(ans.begin());
            }
            --n;
        }
        return ans;
    }
};