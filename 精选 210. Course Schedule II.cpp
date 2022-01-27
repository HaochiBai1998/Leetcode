
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
public:

    //topo sort+ bfs * best Solution
   
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        vector<vector<int>> table(numCourses);
        vector<int> counter(numCourses,0);
        int n=prerequisites.size();
        for(auto & it:prerequisites){
            table[it[1]].push_back(it[0]);
            counter[it[0]]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;++i){
            if(counter[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int size=q.size();
            for(int j=0;j<size;++j){
                int num=q.front();
                q.pop();
                ans.push_back(num);
                for(int & it:table[num]){
                    if(--counter[it]==0){
                        q.push(it);
                    }
                }
            }
        }
        if(ans.size()==numCourses){
            return ans;
        }
        else{
            return vector<int>();
        }
    }
    //count+cache prerequisites
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        int num=numCourses;
        vector<bool> haveTaken(numCourses,false);
        vector<vector<int>> table(numCourses);
        vector<int> counter(numCourses,0);
        for(auto & it:prerequisites){
            counter[it[0]]++;
            table[it[1]].push_back(it[0]);
        }
        
        while(ans.size()!=numCourses){
            int tmp=num;
            for(int i=0;i<numCourses;++i){
                if(haveTaken[i]==true){
                    continue;
                }
                if(counter[i]==0&&haveTaken[i]==false){
                    ans.push_back(i);
                    haveTaken[i]=true;
                    num--;
                    for(auto &it: table[i]){
                        counter[it]--;
                    }
                }
            }
            if(tmp==num){
                return vector<int>();
            }
        }
        return ans;
    }
};