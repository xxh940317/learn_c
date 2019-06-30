#include <stdio.h>

void f(){
    char ch;
    if((ch= getchar())!='\n')
        f();
    if(ch!= '\n')
        printf("%c",ch);
}

int main()
{
    printf("请输入字符");
    f();
    printf("\n");
    
    return 0;
}

