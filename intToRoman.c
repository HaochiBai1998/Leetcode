#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char * strcat_t(char * str, const char *str2,int *strSize){
    *strSize+=strlen(str2);
    str=realloc(str,*strSize*sizeof(*str));
    if(*str=='\0'){
        strcpy(str,str2);
        return str;
    }
    strcat(str,str2);
    return str;
}

char * pair(int num,char * str,int *strSize){
    switch(num){
        case 1000:
           strcat_t(str,"M",strSize);
            return str;
        case 900:
           strcat_t(str,"CM",strSize);
            return str;   
        case 500:
           strcat_t(str,"D",strSize);
            return str;         
        case 400:
           strcat_t(str,"CD",strSize);
            return str;         
        case 100:
           strcat_t(str,"C",strSize); 
            return str;        
        case 90:
           strcat_t(str,"XC",strSize); 
            return str;        
        case 50:
           strcat_t(str,"L",strSize);
            return str;         
        case 40:
           strcat_t(str,"XL",strSize);
            return str;         
        case 10:
           strcat_t(str,"X",strSize);
            return str;         
        case 9:
           strcat_t(str,"IX",strSize);
            return str;         
        case 5:
           strcat_t(str,"V",strSize);
            return str; 
        case 4:
           strcat_t(str,"IV",strSize);
            return str; 
        default:
           strcat_t(str,"I",strSize);
            return str; 
    }
}
char * intToRoman(int num){
    int counts[13]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
    char *str=malloc(sizeof(char));
    *str='\0';
    int index=0;
    int strSize=1;
    while (num!=0){
        while(num-counts[index]>=0){
            pair(counts[index],str,&strSize);
            num=num-counts[index];
        }
        index++;
        if(index==13)
            break;
    }
    return str;
}

int main(){
  char * str=intToRoman(1944);
  printf("%s\n",str);
  return 0;

}
