#include <apue.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>

int main(){

    struct sockaddr_in sock_addr;
    memset(&sock_addr,0,sizeof(sock_addr));
    sock_addr.sin_family = AF_INET;
    sock_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    sock_addr.sin_port = htons(1234);
    
    char buff_send[MAXLINE];
    char buff_recv[MAXLINE];
    while(1){
        

        int sock = socket(AF_INET,SOCK_STREAM,0);
        int ret=connect(sock,(struct sockaddr *)&sock_addr,sizeof(sock_addr));
        
        if(ret<0){
            perror("connect error");
            exit(1);
        }

        printf("input a string:");
        /* fgets(buff_send,MAXLINE,stdin);  //会读取回车 */
        
        scanf("%s",buff_send);
        write(sock,buff_send,strlen(buff_send)+1);
        int fd =open(buff_send,O_RDWR|O_CREAT,0666);
        if(fd<0){
            perror("create fail");
            exit(1);
        }
        int count,sum=0;
        while((count=read(sock,buff_recv,MAXLINE))>0){
            write(fd,buff_recv,count);
            sum++;
        }
        /* read(sock,buff_recv,MAXLINE); */
        if(sum == 0){
            printf("传输失败，服务端无此文件\n");
        }
        else
            printf("OK\n");

        memset(buff_send,0,MAXLINE);
        memset(buff_recv,0,MAXLINE);
        
        close(sock);
    }
    return 0;
}
