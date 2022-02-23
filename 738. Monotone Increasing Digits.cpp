//
// Created by bhc on 2022/2/23.
//

#include<string>
using namespace std;
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string str=to_string(n);
        if(n<=9){
            return n;
        }
        int M=-1;
        for(int i=str.size()-1;i>=1;--i){
            if(str[i]<str[i-1]){
                M=i;
                --str[i-1];
            }
        }
        for(int i=M;i<str.size();++i){
            str[i]='9';
        }
        return stoi(str);
    }
};