
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
    //iterate solution Pass
    double myPow(double x, int n) {
        if(n==0)   
            return 1;
        double ref=x;
        double ans=1;
        bool inverse=false;
        long num=n;
        if(num<0){
            inverse=true;
            num=-(long)n;
        }
        while(num>1){
            if(num%2==1){
                ans*=ref;
            }
            ref*=ref;
            num/=2;
        }
        return inverse?1/ans/ref:ans*ref;
    }
    //recursive solution: Time out
    double my_pow(double x,int n){
        if(n==0){
            return 1;
        }
        if(n==1){
            return x;
        }
        if(n%2==1){
            return my_pow(x,n/2)*my_pow(x,n/2)*x;
        }
        return my_pow(x,n/2)*my_pow(x,n/2);
    }
    double myPow(double x, int n) {
        return n<0?1/my_pow(x,-n):my_pow(x,n);
    }
};