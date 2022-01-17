
#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        int size=m+n;
        int H=0;
        int T=(m+n)/2;
        if(m<n){
            swap(nums1,nums2);
            swap(m,n);
        }
        int left1;
        int left2;
        int right1;
        int right2;
        while(H<=T){
            int index1=(H+T)/2;
            int index2=size/2-index1;
            if(index2<0){
                index1=size/2-index2;
                index1=0;
            }
            if(index2>n){
                index2=n;
                index1=size/2-n;
            }
            left1=(index1>=1?nums1[index1-1]:-1000001);
            left2=(index2>=1?nums2[index2-1]:-1000001);
            right1=(index1<m?nums1[index1]:1000001);
            right2=(index2<n?nums2[index2]:1000001);
            if(left1>right2){
                T=index1-1;
            }
            else if(left2>right1){
                H=index1+1;
            }
            else{
                if(size%2==0){
                    return (double)(max(left1,left2)+min(right1,right2))/2;
                }
                else{
                    return min(right1,right2);
                }
            }
        }
        if(size%2==0){
            return (double)(max(left1,left2)+min(right1,right2))/2;
        }
        else{
            return min(right1,right2);
        }
    }
};