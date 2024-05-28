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
char ch;
sockfd=socket(AF_INET,SOCK_STREAM,0);
address.sin_family=AF_INET;
address.sin_port=htons(9002);
address.sin_addr.s_addr=htonl(INADDR_ANY);
len=sizeof(address);
result=connect(sockfd,(struct sockaddr*)&address,len);
printf("Enter the character to be sent: \n");
scanf("%c",&ch);
write(sockfd,&ch,sizeof(ch));
printf("\nCharacter sent\n");
read(sockfd,&ch,sizeof(ch));
printf("\n Incremented character from server: %c\n",ch);
//close(sockfd);
return(0);
}

