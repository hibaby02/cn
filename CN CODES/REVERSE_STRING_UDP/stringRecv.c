#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
int main()
{
int sfd,slen;
struct sockaddr_in s;
sfd=socket(AF_INET,SOCK_DGRAM,0);
s.sin_family=AF_INET;
s.sin_addr.s_addr=htonl(INADDR_ANY);
s.sin_port=htons(8889);
slen=sizeof(s);
bind(sfd,(struct sockaddr*)&s,slen);
while(1)
{
char ch[20];
printf("server on \n");

recvfrom(sfd,&ch,20,0,(struct sockaddr*)&s,&slen);
//ch++;
int len = strlen(ch);
 
    // for loop
    for (int i = 0, j = len - 1; i <= j; i++, j--) {
        // swapping characters
        char c = ch[i];
        ch[i] = ch[j];
        ch[j] = c;
    }
sendto(sfd,&ch,20,0,(struct sockaddr*)&s,slen);

}
return 0;
}
