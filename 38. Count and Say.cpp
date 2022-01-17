#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
            return to_string(1);
        string str=countAndSay(n-1);
        string ans;
        int i=0;
        int size=str.size();
        while(i<size){
            const char c=str[i];
            size_t found=str.find_first_not_of(c,i);
            if(found==std::string::npos){
                ans.append(to_string(size-i));
                ans.append(string(1,c));
                return ans;
            }
            ans.append(to_string(found-i));
            ans.append(string(1,c));
            i=found;
        }
        return ans;
    }
};


int main(){
    Solution s;
    cout<<s.countAndSay(2)<<endl;
    cout<<s.countAndSay(3)<<endl;
    cout<<s.countAndSay(4)<<endl;
    cout<<s.countAndSay(5)<<endl;
    cout<<s.countAndSay(6)<<endl;
    cout<<s.countAndSay(7)<<endl;
    cout<<s.countAndSay(8)<<endl;
    cout<<s.countAndSay(9)<<endl;
    return 0;
}