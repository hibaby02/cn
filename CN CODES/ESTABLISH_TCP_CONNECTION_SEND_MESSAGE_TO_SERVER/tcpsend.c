#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<unistd.h>

int main()
{
int sockfd,len,result;
struct sockaddr_in address;
char name[100],ser[100];
sockfd=socket(AF_INET,SOCK_STREAM,0);
address.sin_family=AF_INET;
address.sin_port=htons(9002);
address.sin_addr.s_addr=htonl(INADDR_ANY);
len=sizeof(address);
result=connect(sockfd,(struct sockaddr*)&address,len);
printf("Enter the message to be sent: \n");
gets(name);
write(sockfd,name,sizeof(name));
printf("\nMessage sent\n");
read(sockfd,ser,sizeof(ser));
printf("\n Reading from server: \n");
puts(ser);
close(sockfd);
return(0);
}

