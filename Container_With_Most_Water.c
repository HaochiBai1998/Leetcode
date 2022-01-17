#include<stdio.h>
#include<stdlib.h>

int min(int a,int b){
    if (a<b)
        return a;
    else
        return b;
}

int calSum(int * a,int *b){
    return (b-a)*min(*a,*b);
}
int * findMax(int *H,int *T){
    int *ptr=H;
    int *max_ptr=H;
    for(;ptr!=T+1;ptr++){
        if(*ptr>*max_ptr)
            max_ptr=ptr;
    }
    return max_ptr;
}

int maxArea(int* height, int heightSize){
    int * Tail=height+heightSize-1;
    if(height==NULL||heightSize==0)
        return 0;
    int max=0;
    int *H;
    int *T;
    //find 1st,2nd max Num in string;
    H=findMax(height,Tail);
    int buf=*H;
    *H=0;
    T=findMax(height,Tail);
    *H=buf;
    if(T<H){
        int * a=T;
        T=H;
        H=a;
    }
    int * ptr_t=T;
    int * ptr_h=H;
    max=calSum(H,T);
    while(H!=height){
        H=findMax(height,H-1);
        if(calSum(H,ptr_t)>max){
	  printf("Left Max index=%ld\n",H-height);
	  ptr_h=H;
	  max=calSum(H,ptr_t);
        }
    }
    while(T!=Tail){
      T=findMax(T+1,Tail);
      if(calSum(ptr_h,T)>max){
	printf("Right Max index=%ld\n",T-height);
	ptr_t=T;
	max=calSum(ptr_h,T);
      }
    }
    printf("\n\nIndex %ld,%ld\n",H-height,T-height);
    return max;
}

int main(){
  int array[10]={8,10,14,0,13,10,9,9,11,11};
  int max=maxArea(array,10);
  printf("%d\n",max);
  return 0;
}
