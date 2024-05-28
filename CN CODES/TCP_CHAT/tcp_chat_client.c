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
int sockfd,len,result;
struct sockaddr_in address;
char name[800];
sockfd=socket(AF_INET,SOCK_STREAM,0);
address.sin_family=AF_INET;
address.sin_port=htons(7002);
address.sin_addr.s_addr=htonl(INADDR_ANY);
len=sizeof(address);
result=connect(sockfd,(struct sockaddr*)&address,len);
printf("Enter the message to be sent: \n");
fgets(name,800,stdin);
fputs(name,stdout);
while(name!="quit")
{
write(sockfd,name,sizeof(name));
printf("\nMessage sent to server\n");
read(sockfd,name,sizeof(name));
printf("\n Reading from server: %s \n",name);
int i=strncmp("quit",name,4);
if(i==0)
{
break;
}
printf("\nType your message\n");
fgets(name,800,stdin);
}
close(sockfd);
return(0);
}
