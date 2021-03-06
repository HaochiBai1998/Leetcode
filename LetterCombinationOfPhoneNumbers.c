#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//char ** iteration (char **)

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct  _strs_t{
  char ** strs;
  int strsSize;
};

typedef struct _strs_t strs_t;

int charToInt(char a){
  return a-'2';
}

void swap(char * H, char * T){
  char temp=*H;
  *H=*T;
  *T=temp;
  return;
}

void reverseStr(char * str){
  if(strlen(str)==1)
    return;
  char * H=str;
  char * T=str+strlen(str)-1;
  while(H-T<0){
    swap(H,T);
    H++;
    T--;
  }
  return;
}

char ** reverse(char ** strs,int strsSize){
  for (int i=0;i<strsSize;i++){
    reverseStr(strs[i]);
  }
  return strs;
}

const char * charToRecord(char c,char record[][5]){
  return record[charToInt(c)];
}

strs_t * strsCat(strs_t *strArr, const char * str,int index, strs_t *strs){
  int strLen=strlen(str);
  for(int i=0;i<strs->strsSize;i++){
    char *str1=strs->strs[i];
    str1=realloc(str1,(strlen(str1)+2)*sizeof(char));//*
    str1[strlen(str1)]=str[index];
    str1[strlen(str1)+1]='\0';
  }
  int strArrNewSize=strArr->strsSize+strs->strsSize;
  strArr->strs=realloc(strArr->strs,strArrNewSize*sizeof(*strArr->strs));
  for (int i=0;i<strs->strsSize;i++){
    strArr->strs[i+strArr->strsSize]=strs->strs[i];
  }
  strArr->strsSize=strArrNewSize;
  return strArr;
}
strs_t * recordComb(const char * digits,int digitsLen,char record[][5]){
  const char *str=charToRecord(*digits,record);
  int strLen=strlen(str);
  strs_t * strArr=NULL;
  strArr=malloc(sizeof(*strArr));//*
  strArr->strs=NULL;
  strArr->strsSize=0;
  if(digitsLen==1){
    strArr->strs=malloc(strLen*sizeof(*strArr->strs));//*
    (strArr->strsSize)+=strLen;
    for (int i=0;i<strLen;i++){
      strArr->strs[i]=malloc(2*sizeof(char));//*
      strArr->strs[i][0]=str[i];
      strArr->strs[i][1]='\0';
    }
    return strArr;
  }
  for (int i=0;i<strLen;i++){
    strs_t * strRnt=recordComb(digits+1,digitsLen-1,record);
    strArr=strsCat(strArr,str,i,strRnt);
  }
  return strArr;
}

char ** letterCombinations(const char * digits, int* returnSize){
  char record[][5]={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
  if(digits==NULL||*digits=='\0')
    return NULL;
  *returnSize=1;
  int digitsLen=strlen(digits);
  strs_t * strs=recordComb(digits,digitsLen,record);
  *returnSize=strs->strsSize;
  return strs->strs;
}

int main(){
  char * digits="23";
  int returnSize=0;
  char ** strs=letterCombinations(digits,&returnSize);
  strs=reverse(strs,returnSize);
  for (int i=0;i<returnSize; i++){
    printf("%s\n",strs[i]);
  }
  return 0;
}
