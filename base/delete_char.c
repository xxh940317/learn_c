#include <stdio.h>
#include <malloc.h>

char *fun(char *s,char ch){
    char *w=(char*)malloc(20*sizeof(char));
    char *p=w;
    while(*s!='\0'){
        if(*s!=ch)  *w++=*s;
        s++;
    }
    *w='\0';
    return p;
}

int main()
{
    char a[20]="absdadaaafa";
    char ch = 'a';
    puts(fun(a,ch));
    return 0;
}

