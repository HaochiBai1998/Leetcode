#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
#include<math.h>
#include<unordered_set>
#include<queue>
using namespace std;


class Solution {
    vector<vector<int>>& statements;
    int n;
public:
    int helper(int index,int bad_counter,vector<int> good_or_bad){
        int tmp=bad_counter;
        vector<int> tmp2=good_or_bad;
        if(index==n||bad_counter==n){
            return n-bad_counter;
        }
        //define index people good
        vector<int> bad;
        vector<int> good;
        for(int i=index;i<n;++i){
            if(statements[i][index]==0){
                bad.push_back(i);
            }
            else if(statements[i][index]==1){
                good.push_back(i);
            }
        }
        // index is good
        for(auto & it: bad){
            if(good_or_bad[it]==1){
                return 0;
            }
            else if(good_or_bad[it]==3){
                bad_counter++;
                good_or_bad[it]=0;
            }
        }
        for(int i=index;i<n;++i){
            if(statements[index][i]!=3){
                if(statements[index][i]!=good_or_bad[i]){
                    return 0;
                }
            }
            else{
                bad_counter+=(!statements[index][i]);
            }
        }
        int counter1=helper(index+1,bad_counter,good_or_bad);
        good_or_bad=tmp2;
        bad_counter=tmp;
        //index is bad;
        for(auto & it: good){
            if(good_or_bad[it]==1){
                return 0;
            }
            else if(good_or_bad[it]==3){
                bad_counter++;
                good_or_bad[it]=0;
            }
        }
        int counter2=helper(index+1,bad_counter,good_or_bad);
        return max(counter1,counter2);
    }
    int maximumGood(vector<vector<int>>& statements) {
        this->statements=statements;
        n=statements.size();
        helper(0,0,vector<int>(n,3));
    }
};