#include <apue.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

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
        connect(sock,(struct sockaddr *)&sock_addr,sizeof(sock_addr));
        printf("input a string:");
        fgets(buff_send,MAXLINE,stdin);  //会读取回车
        
        /* scanf("%s",buff_send); */


        write(sock,buff_send,strlen(buff_send)+1);
        read(sock,buff_recv,MAXLINE);
        printf("message from server:%s\n",buff_recv);

        memset(buff_send,0,MAXLINE);
        memset(buff_recv,0,MAXLINE);
        
        close(sock);
    }
    return 0;

    
}
