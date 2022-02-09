//
// Created by bhc on 2022/2/9.
//

#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        while(b!=0){
            unsigned int cout=((unsigned int)a&b)<<1;
            a=a^b;
            b=cout;
        }
        return a;
    }
};