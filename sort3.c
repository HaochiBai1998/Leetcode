#include<stdio.h>
#include<stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}
void swap(int *a,int*b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void sort_3(int *a,int *b,int *c){
    if (*a<*b)
        swap(a,b);
    if(*b<*c)
        swap(b,c);
    if(*a<*b)
        swap(a,b);
}

int ** store(int a,int b,int c,int ** array,int *arrSize){
    sort_3(&a,&b,&c);
    for (int i=0;i<*arrSize;i++){
        if(a==array[i][0])
            if (b==array[i][1])
                return array;
    }
    printf("%d %d %d \n",a,b,c);        
    *arrSize=*arrSize+1;
    printf("%d\n",*arrSize);
    array=realloc(array,*arrSize*sizeof(*array));
    array[*arrSize-1]=malloc(3*sizeof(**array));
    array[*arrSize-1][0]=a;
    array[*arrSize-1][1]=b;
    array[*arrSize-1][2]=c;
    printf("%d %d %d\n",
    return array;
}
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    //qsort 
    qsort(nums,numsSize,sizeof(int),cmpfunc);
    //form sum of 2 dimension array and reverse data
    int **a=malloc(numsSize*sizeof(*a));
    for (int i=0;i<numsSize;i++){
        a[i]=malloc(numsSize*sizeof(**a));
    }
    for (int i=0;i<numsSize;i++){
        for (int j=i+1;j<numsSize;j++){
            a[i][j]=-(nums[i]+nums[j]);
        }
    }
    
    //find three sum
    int  ansSize=0;
    int **ans=NULL;
    int index;
    for (int i=0;i<numsSize;i++){
        index=numsSize-1;
        for (int j=i+1;j<numsSize;j++){
            while(a[i][j]<nums[index]){
                index--;
                if(index==i-1)
                    break;
            }
            if(index==-1){
                break;
            }
            else if(a[i][j]==nums[index]&&index!=i&&index!=j){
                ans=store(nums[i],nums[j],nums[index],ans,&ansSize);
	}
        }
    }
    *returnSize=ansSize;
    *returnColumnSizes=malloc(3*sizeof(**returnColumnSizes));  
    return ans;
}

int main(){
  int ** ans;
  int nums[]={-1,0,1,-1,2};
  int numsSize=5;
  int returnSize=0;
  int *returnColumnSizes=NULL;
  ans=threeSum(nums,numsSize,&returnSize,&returnColumnSizes);
  for (int i=0;i<returnSize;i++){
    for (int j=0;j<returnColumnSizes[i];j++){
      printf("%d  ",ans[i][j]);
    }
    printf("\n");
  }
  
  return 0;
}
