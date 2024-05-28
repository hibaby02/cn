#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>

int main()
{
int serv_sockfd,cli_sockfd;
int serv_len,cli_len;
struct sockaddr_in serv_address,cli_address;
char a[100],b[100];
serv_address.sin_family=AF_INET;
serv_address.sin_port=htons(9002);
serv_address.sin_addr.s_addr=htonl(INADDR_ANY);
serv_len=sizeof(serv_address);
serv_sockfd=socket(AF_INET,SOCK_STREAM,0);
bind(serv_sockfd,(struct sockaddr*)&serv_address,serv_len);
listen(serv_sockfd,1);

while(1)
{
printf("Server is waiting..\n");
cli_len=sizeof(cli_address);
cli_sockfd=accept(serv_sockfd,(struct sockaddr*)&cli_address,&cli_len);
printf("Connect to client\n");
read(cli_sockfd,a,sizeof(a));
printf("Reading message from client:\n");
puts(a);
write(cli_sockfd,b,sizeof(b));
gets(b);
close(cli_sockfd);
}
}
