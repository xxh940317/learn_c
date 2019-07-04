#include <apue.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>

int main(){
    int serv_sock = socket(AF_INET,SOCK_STREAM,0);

    struct sockaddr_in serv_addr;
    memset(&serv_addr,0,sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(1234);
    bind(serv_sock,(struct sockaddr*)&serv_addr,sizeof(serv_addr));

    listen(serv_sock,20);

    struct sockaddr clnt_addr;
    socklen_t clnt_len = sizeof(clnt_addr);

    char buff[MAXLINE]={0};
    char buff_send[MAXLINE]={0};
    while(1){
        int count;
        printf("准备就绪\n");
        int clnt_sock = accept(serv_sock,&clnt_addr,&clnt_len);
        printf("连接成功！\n");
        count = read(clnt_sock,buff,MAXLINE);
        printf("你所要传送的文件是%s\n",buff);

        int fd = open(buff,O_RDONLY);
        if(fd<0){
            perror("文件不存在");
            close(serv_sock);
            close(clnt_sock);
            exit(1);

        }

        int num;
        while((num=read(fd,buff_send,MAXLINE))>0){
            write(clnt_sock,buff_send,num);
        }

        shutdown(clnt_sock,SHUT_RD);
        read(clnt_sock,buff,MAXLINE);
        close(clnt_sock);
        close(fd);
    }
    close(serv_sock);
    return 0;
}
