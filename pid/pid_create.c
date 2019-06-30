#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#define EXIT_ERROR(m){\
    perror(m);\
    exit(1);\
}

int count=0;

int main()
{
    pid_t pid;
    int count2=0;
    count++;
    count2++;
    printf("count=%d,count2=%d\n",count,count2);

    pid = fork();
    count++;
    count2++;
    
    printf("count=%d,count2=%d\n",count,count2);

    printf("pid=%d\n",pid);

    return 0;
}

