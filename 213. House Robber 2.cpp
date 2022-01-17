#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int,int> sum;
        int index=0;
        int n=nums.size();
        int currNum=nums[0];
        for(int i=0;i<n;i++){
            if(currNum!=nums[i]){
                index++;
                currNum=nums[i];
            }
            sum[index]+=nums[i];
        }
        n=sum.size();
        int maxSum=0;
        int i=n-1;
        for(auto it=sum.rbegin();it>=sum.rend()+3;--it){
            if(it->first-1!=(it-1)->first){
                maxSum+=it->second;
                continue;
            }
            if(it->second>=(it-1)->second){
                maxSum+=it->second;
                --it;
                continue;
            }
            if((it-1)->second>=it->second+(it-2)->second){
                maxSum+=(it-1)->second;
                if((it-1)->first-1==(it-2)->first){
                    --it;
                }
                --it;
            }
        }
        return maxSum;
    }
};

if(sum[i-1]>sum[i]+sum[i-2]){
                maxSum+=sum[i-1];
                i-=3;
            }
            else{
                maxSum+=sum[i];
                i-=2;
            }
int main(){
   int  nums[]={10,8,4,2,1,3,4,8,2,9,10,4,8,5,9,1,5,1,6,8,1,1,6,7,8,9,1,7,6,8,4,5,4,1,5,9,8,6,10,6,4,3,8,4,10,8,8,10,6,4,4,4,9,6,9,10,7,1,5,3,4,4,8,1,1,2,1,4,1,1,4,9,4,7,1,5,1,10,3,5,10,3,10,2,1,10,4,1,1,4,1,2,10,9,7,10,1,2,7,5};
    sort(nums,nums+100);
    for(int i=0;i<50;i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    for(int i=50;i<100;i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    return 0;
}