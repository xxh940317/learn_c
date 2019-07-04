#include <apue.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

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
    /* int clnt_sock = accept(serv_sock,&clnt_addr,&clnt_len); */

    char buff[MAXLINE]={0};

    while(1){
        int clnt_sock = accept(serv_sock,&clnt_addr,&clnt_len);
        int count = read(clnt_sock,buff,MAXLINE);
        write(clnt_sock,buff,count);

    //    shutdown(clnt_sock,SHUT_RD);
        close(clnt_sock);
    }
    close(serv_sock);
    return 0;
}
