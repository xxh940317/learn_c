#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void print_message(void){
    pthread_detach(pthread_self());
    static int g;
    for(int i=0;i<5;i++){
        printf("%d\n",g++);
    }
    pthread_exit(0);
}

int main()
{
    pthread_t thread1;
    pthread_create(&thread1,NULL,(void *)&print_message,NULL);
    int i;
    for(i=0;i<5;i++)    printf("%lu\n",thread1);
    sleep(3);
    return 0;
}
