#include<stdio.h>
#include<stdlib.h>

void printStr(const char * str){
  printf("%s",str);
}
int main(){
  const char * str="abc";
  printStr(str);
  return 0;
}
