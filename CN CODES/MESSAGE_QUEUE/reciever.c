#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int msqid,len;
	long int msg_to_rec=0;
	struct msgbuf
	{
		long mtype;
		char mtext[100];
	} recv;
	key_t key;
	key=10;
	msqid=msgget(key,IPC_CREAT|0666);
	if(msqid==-1)
	{
		printf("msgget failed");
		exit(1);
	}
	if(msgrcv(msqid,&recv,20,msg_to_rec,0)<0)
	{
		printf("msg failed");
		exit(1);
	}
	printf("msg from sender : %s\n",recv.mtext);
	if(strncmp(recv.mtext,"end",3)==0)
	{
		exit(1);
	}
	//msgctl(msqid,IPC_RMID,0);
	return 0;
}
