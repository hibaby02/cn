#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>
int main()
{
int sockfd,newsockfd;
int clilen;
struct sockaddr_in cli_addr,serv_addr;
int i;
char buf[50],f='0';
sockfd=socket(AF_INET,SOCK_STREAM,0);
serv_addr.sin_family=AF_INET;
serv_addr.sin_addr.s_addr=inet_addr("127.0.0.1");

serv_addr.sin_port=5567;
bind(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
listen(sockfd,1);
clilen=sizeof(cli_addr);
newsockfd=accept(sockfd,(struct sockaddr*)&cli_addr,&clilen);

while(1)
{
sleep(1);
for(i=0;i<5;i++)
{
buf[i]='\0';
}
buf[0]=f;
send(newsockfd,buf,5,0);
for(i=0;i<5;i++)
{
buf[i]='\0';
}
recv(newsockfd,buf,5,0);
printf("ACK: %s\n",buf);
if(f=='0')
{
f='1';
}
else
{
f='0';
}
}
return 0;
}
