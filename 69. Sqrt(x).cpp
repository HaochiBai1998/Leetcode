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
    int mySqrt(int x) {
        long tail=INT_MAX;
        long head=0;
        long mid=(tail+head)/2;
        while(head!=tail){       
            long mid=(tail+head)/2;
            if(mid*mid>x){
                tail=mid-1;
            }
            else if(mid*mid<x){
                head=mid+1;
            }
            else
                return mid;
        }
        return head*head>x?head-1:head;
    }
};