#include <stdio.h>
#include <pthread.h>
#include <sys/syscall.h>
int main()
{
    pid_t tid;
    tid = syscall(SYS_gettid);

    printf("tid = %d\n",tid);
    return 0;
}

