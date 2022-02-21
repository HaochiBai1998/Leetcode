//
// Created by bhc on 2022/2/21.
//
#include<vector>
using namespace std;
class Solution {
public:
    //贪心
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int index1=0;
        int index2=0;
        int n1=g.size();
        int n2=s.size();
        while(index1<n1&&index2<n2){
            if(g[index1]>s[index2]){
                ++index2;
            }
            else{
                ++index1;
                ++index2;
            }
        }
        return index1;
    }
};