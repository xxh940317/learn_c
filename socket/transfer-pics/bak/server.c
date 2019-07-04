#include <apue.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>

int main(int argc,char const *argv[]){
/*     if(argc<2){ */
/*         perror("请输入文件名\n"); */
/*         exit(1); */
/*     } */
    int serv_sock = socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in serv_addr;
    memset(&serv_addr,0,sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(1234);
    bind(serv_sock,(struct sockaddr *)&serv_addr,sizeof(serv_addr));
    
    listen(serv_sock,20);
    
    struct sockaddr_in clnt_addr;
    socklen_t clnt_len = sizeof(clnt_addr);
    int clnt_sock = accept(serv_sock,(struct sockaddr*)&clnt_addr,&clnt_len);
    
    char buff[MAXLINE] = {0};
    char addr[100]={0}; 
    char msg[20]="file error,rewrite!";
    int fd;


    while(1){
        int count = read(clnt_sock,addr,sizeof(addr));
        fd = open(addr,O_RDONLY);
        if(fd < 0){
            write(clnt_sock,msg,20);
            printf("rewrite\n");
            memset(addr,0,sizeof(addr));
        }
        else{
            write(clnt_sock,"OK",3);
            printf("OK\n");
            break;
        }   
    }
    sleep(3);
    int count;
    while((count = read(fd,buff,MAXLINE))>0){
        write(clnt_sock,buff,count);
       }
    shutdown(clnt_sock,SHUT_RD);
    close(fd);
    close(serv_sock);
    close(clnt_sock);

    return 0;

}
