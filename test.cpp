//评测题目: 无lol

#include<vector>
#include<iostream>
using namespace std;

int mysearch(vector<int> & nums,int head,int tail,int target,int status){
    int mid=(tail+head)/2;
    if(mid==tail||mid==head){
        if(nums[tail]==target||nums[head]==target)
            return mid;
        else
            return -1;
    }
    int ans;
    //status=0表示非递增
    if(status==0){
        //右边非递增
        if(nums[mid]>nums[tail]){
            if(target<nums[tail]||target>nums[mid])
                ans=mysearch(nums,mid,tail,target,0);
            else if(target>nums[tail]&&target<nums[mid])
                ans=mysearch(nums,head,mid,target,1);
            else
                return mid;
        }
        //左边非递增
        else{
            if(target<nums[mid]||target>nums[tail])
                ans=mysearch(nums,head,mid,target,0);
            else if(target>nums[mid]&&target<nums[tail])
                ans=mysearch(nums,mid,tail,target,1);
            else
                return mid;
        }
    }
    else{
        if(nums[mid]<target)
            ans=mysearch(nums,mid,tail,target,1);
        else if(nums[mid]>target)
            ans=mysearch(nums,head,mid,target,1);
        else
            return mid;
    }
    return ans;
}
int search(vector<int>& nums, int target) {
    int index_head=0;
    int index_tail=nums.size()-1;
    if(nums[index_head]==target)
        return index_head;
    if(nums[index_tail]==target)
        return index_tail;
    return mysearch(nums,index_head,index_tail,target,0);
}
int main(){
    vector<int> nums={4,5,6,1,2,3,7,8,9};
    cout<<search(nums,6)<<" "<<search(nums,7);
    return 0;
}