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
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int> ans;
        for(int j=0;j<s.size();++j){
            int count=0;
            int col=startPos[1];
            int row=startPos[0];
            for(int i=j;i<s.size();i++){
                switch(s[i]){
                    case 'L':
                    if(col-1>=0){
                        count++;
                        col--;
                    }
                    break;
                    case 'R':
                    if(col+1<n){
                        count++;
                        col++;
                    }
                    break;
                    case 'D':
                    if(row-1>=0){
                        count++;
                        row--;
                    }
                    break;
                    case 'U':
                    if(row+1>=0){
                        count++;
                        row--;
                    }
                    break;
                    default:break;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};