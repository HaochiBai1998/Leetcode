//
// Created by bhc on 2022/2/13.
//
// you can use includes, for example:
// #include <algorithm>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include<vector>
#include<iostream>
using namespace std;

#include<unordered_map>
#include<algorithm>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
int solution(vector<int> &A, int R) {
    // write your code in C++14 (g++ 6.2.0)
    int n=A.size();
    if(R>=n){
        return 0;
    }
    unordered_map<int,int> itemCounter;
    for(int i=R;i<n;++i){
        itemCounter[A[i]]++;
    }
    int curr=itemCounter.size();
    int M=curr;
    for(int i=0;i<n-R;++i){
        if(++itemCounter[A[i]]==1){
            curr++;
        }
        if(--itemCounter[A[i+R]]==0){
            curr--;
        }
        M=max(M,curr);
    }
    return M;
}


int main(){
    int N=7;
    vector<int> A={2, 1, 2, 3, 2, 2};
    solution(A,3);
    return 0;
}
