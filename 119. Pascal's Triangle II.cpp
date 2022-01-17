#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
using namespace std;
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> line={1};
        for(int i=0;i<rowIndex;++i){
            vector<int> tmp;
            tmp.push_back(1);
            for(int j=0;j<i;++j){
                tmp.push_back(line[j]+line[j+1]);
            }
            tmp.push_back(1);
            swap(tmp,line);
        }
        return line;
    }
};