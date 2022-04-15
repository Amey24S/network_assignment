#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>
#include<netinet/in.h>
#include<stdlib.h>

int main()
{
char buf[200];
int n;
char *serv_ip= "127.0.0.1";  //INADDR_ANY
int sockfd,ret_val;
struct sockaddr_in servaddr;
sockfd = socket(AF_INET,SOCK_STREAM,0);

bzero(&servaddr,sizeof(servaddr));
servaddr.sin_family=AF_INET;
servaddr.sin_port= htons(8000);
inet_pton(AF_INET,serv_ip,&servaddr.sin_addr);

ret_val=connect(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));

printf("client established connection with server\n");
while(1)
{
printf("enter message");
gets(buf);
write(sockfd,buf,strlen(buf));
n=read(sockfd,buf,200);
buf[n]="\0";
printf("rec'd %s from server\n",buf);
}
close(sockfd);




return 0;
}
