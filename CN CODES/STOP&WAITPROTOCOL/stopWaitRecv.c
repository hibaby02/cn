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
int sockfd;
struct sockaddr_in serv_addr;
int i;
char buf[50];
sockfd=socket(AF_INET,SOCK_STREAM,0);
serv_addr.sin_family=AF_INET;
serv_addr.sin_addr.s_addr=inet_addr("127.0.0.1");
serv_addr.sin_port=5567;
connect(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
while(1)
{
sleep(1);
for(i=0;i<5;i++)
{
buf[i]='\0';
}
recv(sockfd,buf,5,0);
//sleep(1);
printf("FRAME: %s\n",buf);
if(buf[0]=='0')
{
buf[0]='1';
}
else
{
buf[0]='0';
}
send(sockfd,buf,5,0);
}
return 0;
}
