#include <stddef.h>
#include <stdio.h>
struct address{
     char name[50];
     char steet[50];
    int data;
    struct address *next;
};

int main()
{
    printf("address中name偏移等于%ld个字节\n",offsetof(struct address,name));
    printf("address中steet偏移等于%ld个字节\n",offsetof(struct address,steet));
    printf("address中data偏移等于%ld个字节\n",offsetof(struct address,data));
    printf("address中*next偏移等于%ld个字节\n",offsetof(struct address,next));
    return 0;
}

