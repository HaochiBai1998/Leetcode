
#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
#include<math.h>
#include<unordered_set>
using namespace std;

class Solution {
public:
    //gray equation i^(i>>1)
    vector<int> grayCode(int n) {
        vector<int> ans;
        for(int i=0;i<pow(2,n);++i){
            ans.push_back(i^(i>>1));
        }
        return ans;
	}
    //dfs
	vector<int> ans;
	vector<int> grayCode(int n) {
		unordered_set<int> remb;
		ans.push_back(0);
		remb.insert(0);
		backtrack(ans, remb, n);
		return ans;
	}
	bool backtrack(vector<int>& res, unordered_set<int>& remb, int n){
		if (res.size() == (int)pow(2, n))
			return true;

		for (int i = 0; i < n + 1; i++){
			int output = res.back() ^ (1 << i);		
			if (remb.count(output))
				continue;
			else{
				res.push_back(output);
				remb.insert(output);
				if (backtrack(res, remb, n))
					return true;
				res.pop_back();
				remb.erase(output);
			}
		}
		return false;
	}
};