#include <iostream>
using namespace std;

void getMemory(char ** p , int n){
    *p = new char(n);
}
int main(){
    char * str=NULL;
    getMemory(&str,12);
    strcpy(str,"hello!");
    cout<<str;
}