// you can use includes, for example:
#include <algorithm>
#include <math.h>
#include<vector>
#include<iostream>
using namespace std;
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int getComb(vector<int> & num,int index,bool isEqualOne){
    int P=0;
    int n=num.size();
    int result=0;
    for(int i=0;i<n;++i){
        if(index==i){
            continue;
        }
        if(i<index&&!isEqualOne){
            result+=10*pow(10,P);
        }
        else{
            result+=(num[i]+1)*pow(10,P);
        }
        P++;
    }
    return result;
}

int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> num;
    while(N!=0){
        num.push_back(N%10);
        N/=10;
    }
    int n=num.size();
    int sum=0;
    for(int i=0;i<n;++i){
        sum+=getComb(num,i,num[i]==1);
    }
    return sum;
}

int main(){
    cout<<solution(13)<<endl;
}