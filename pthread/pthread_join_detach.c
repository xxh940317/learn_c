#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>


void *run(void *arg)
{
    pthread_detach(pthread_self());
    printf("%s\n",(char *)&arg);
}

int main()
{
    pthread_t tid;
    if(pthread_create(&tid,NULL,run, "pthread runng!")!=0){
        perror("create error");
        exit(1);
    }
    int ret = 0;
    sleep(1);
    if(pthread_join(tid,NULL)==0){
        printf("wait success\n");
        ret = 0;
    }else{
        printf("wait failed\n");
        return 1;
    }
    return ret;
}

