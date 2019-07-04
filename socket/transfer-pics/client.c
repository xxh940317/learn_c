#include <apue.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>

int main(int argc,char const *argv[]){
    
    /* char filename[20]={0}; */
    
    int sock = socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in serv_addr;
    memset(&serv_addr,0,sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(1234);
    
    connect(sock,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
    
    char buff[MAXLINE]={0};
    /* char c; */

    /* while(1){ */
        printf("请输入想要的文件名\n");
        /* scanf("%s",filename); */
        /* while((c=getchar()!='\n'&&c!=EOF)); */
    /*     read(sock,buff,sizeof(buff)); */
    /*     if(strcmp(buff,"OK")==0){ */
    /*         printf("success\n"); */
    /*         break; */
    /*     } */ 
    /*     memset(buff,0,sizeof(buff)); */
    /* } */

    int count;

    int fd = open("123.jpg",O_RDWR|O_CREAT,0666);
    if(fd < 0){
        perror("fd error");
        exit(1);
    }

    while((count = read(sock,buff,sizeof(buff)))>0){
        if(count==0){
            perror("server don't run!\n");
            exit(1);
        }
        write(fd,buff,count);
    }
    /* shutdown(sock,SHUT_WR); */
    read(sock,buff,sizeof(buff));
    close(sock);
    puts("File transfer success!");

    return 0;
    
}
