#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netinet/ip.h>
int main()
{
	int server,status;
	struct sockaddr_in sa,ca;
	char buf[100],buf2[100];
	server=socket(AF_INET,SOCK_STREAM,0);
	if(server==-1)
	{
		printf("socket not created\n");
		return 0;
	}
	printf("socket created\n");
	sa.sin_family=AF_INET;
	sa.sin_port=htons(6000);
	sa.sin_addr.s_addr=inet_addr("127.0.0.1");
	status=bind(server,(struct sockaddr *)&sa,sizeof(sa));
	if(status==-1)
	{
		printf("bind failed\n");
		return ;
	}
	printf("bind success\n");
	ca.sin_family=AF_INET;
	ca.sin_port=htons(3000);
	ca.sin_addr.s_addr=inet_addr("127.0.0.1");
	int k=listen(server,5);
	if(k==-1)
	{
		printf("listening failed\n");
		return 0;
	}
	printf("listen success\n");
	int len=sizeof(ca);
	int fd=accept(server,(struct sockaddr*)&ca,&len);
	if(fd==-1)
	{
		printf("second socket not created\n");
		return 0;
	}
	printf("second socket created\n");
	while(!strcmp("exit",buf)==0){
	int t=recv(fd,buf,100,0);
	buf[t]='\0';
	printf("message from client-->%s\n",buf);
	printf("enter the reply-->");
	gets(buf2);
	printf("\n");
	send(fd,buf2,strlen(buf2),0);
	}
	close(fd);
return 0;
}
