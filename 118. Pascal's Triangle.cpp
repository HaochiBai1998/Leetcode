#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        if(numRows==1)
            return ans;
        for(int i=1;i<numRows;++i){
            vector<int> line;
            line.push_back(1);
            for(int j=0;j<i-1;++j){
                line.push_back(ans[i-1][j]+ans[i-1][j+1]);
            }
            line.push_back(1);
            ans.push_back(line);
        }
        return ans;
    }
};