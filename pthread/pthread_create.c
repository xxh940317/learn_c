#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define EXIT_ERROR(m) {\
    perror(m);\
    exit(1);\
}

void *run(void *arg){
    int ret =*(int*)&arg;
    while(1){
       printf("new thread running------;tid=%lu,arg = %d\n",pthread_self(),ret);
       sleep(1);
    }
}

int main()
{
    pthread_t tid;
    pthread_t tid1;
    pthread_t tid2;
    
    int ret = pthread_create(&tid,NULL,run,(void *)1);
    if(ret<0)   EXIT_ERROR("pthread_create fail");

    int ret1 = pthread_create(&tid1,NULL,run,(void*)2);
    if(ret1<0)   EXIT_ERROR("pthread_create fail");

    int ret2 = pthread_create(&tid2,NULL,run,(void *)3);
    if(ret2<0)   EXIT_ERROR("pthread_create fail");

    if((pthread_join(tid,NULL))<0)  EXIT_ERROR("join tid fail");
    if((pthread_join(tid1,NULL))<0)  EXIT_ERROR("join tid1 fail");
    if((pthread_join(tid2,NULL))<0)  EXIT_ERROR("join tid2 fail");
    while(1){
        printf("i am main pthread------tid = %lu\n",pthread_self());
        sleep(1);
    }
    
    
    return 0;
}

