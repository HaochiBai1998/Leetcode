//
// Created by bhc on 2022/2/8.
//

#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
#include<set>
#include<queue>

using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long numer=numerator;
        long denom=denominator;
        bool isPositive=numer*denom>=0;
        numer=abs(numer);
        denom=abs(denom);
        long num=numer/denom;
        long rmn=numer%denom;
        unordered_map<long,long> hashTable;
        bool isUnlimited=false;
        vector<long> nums;
        long start=-1;
        while(rmn!=0){
            if(hashTable.count(rmn)){
                isUnlimited=true;
                start=hashTable[rmn];
                break;
            }
            hashTable[rmn]=nums.size();
            rmn*=10;
            long tmp=rmn/denom;
            nums.push_back(tmp);
            rmn%=denom;
        }
        string ans=(isPositive?"":"-")+to_string(num);
        if(nums.size()!=0){
            ans+=".";
            for(int i=0;i<nums.size();++i){
                if(i==start&&isUnlimited){
                    ans+="(";
                }
                ans+=to_string(abs(nums[i]));
            }
            if(isUnlimited){
                ans+=")";
            }
        }
        return ans;
    }
};