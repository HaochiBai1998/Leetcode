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
    int find(vector<int>& nums,int target){
        int tail=nums.size()-1;
        int head=0;
        while(head<tail){
            int mid=(tail+head)/2;
            if(nums[mid]>target){
                tail=mid-1;
            }
            else if(nums[mid]<target){
                head=mid+1;
            }
            else
                return mid;
        }
        if(nums[head]==target)
            return head;
        else  
            return -1;
    }
    vector<int> recoverArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>lower;
        int H=1;
        int k;
        while(H<=n/2){
            lower=vector<int>();
            vector<int> tmp(nums);
            k=nums[H]-nums[0];
            if(k==0||k%2!=0){
                H++;
                continue;
            }
            while(!tmp.empty()){
                int index=find(tmp,tmp[0]+k);
                auto it=tmp.begin()+index;
                if(index!=-1){
                    tmp.erase(it);
                    lower.push_back(*tmp.begin());
                    tmp.erase(tmp.begin());
                }
                else
                    break;
            }
            if(tmp.empty())
                break;
            H++;
        }
        for(auto it=lower.begin();it!=lower.end();++it){
            *it=*it+k/2;
        }
        return lower;
    }
};
void print(vector<int> nums){
    for(auto it=nums.begin();it!=nums.end();++it){
        cout<<*it<<" ";
    }
    cout<<endl;
}
int main(){
    Solution a;
    vector<int> nums({11,6,3,4,8,7,8,7,9,8,9,10,10,2,1,9});
    vector<int> lower=a.recoverArray(nums);
    print(lower);
    return 0;
}