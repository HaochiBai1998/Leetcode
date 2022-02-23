//
// Created by bhc on 2022/2/22.
//
#include<vector>
using namespace std;
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fiveCounter=0;
        int tenCounter=0;
        for(int i=0;i<bills.size();++i){
            if(bills[i]==5){
                ++fiveCounter;
            }
            else if(bills[i]==10){
                if(--fiveCounter<0){
                    return false;
                }
                tenCounter++;
            }
            else{
                if(tenCounter){
                    --tenCounter;
                    if(--fiveCounter<0){
                        return false;
                    }
                }
                else{
                    fiveCounter-=3;
                    if(fiveCounter<0){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};