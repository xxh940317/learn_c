#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#define EXIT_ERROR(m){\
    perror(m);\
    exit(1);\
}

int main()
{
    printf("Hello world\n");
    return 0;
}

