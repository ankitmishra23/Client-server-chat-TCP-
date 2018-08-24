#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netinet/ip.h>
int main()
{
	int client;
	struct sockaddr_in ca,sa;
	char buf[100],buf2[100];
	client=socket(AF_INET,SOCK_STREAM,0);
	if(client==-1)
	{
		printf("socket not created\n");
		return 0;
	}
	printf("socket created\n");
	ca.sin_family=AF_INET;
	ca.sin_port=htons(3000);
	ca.sin_addr.s_addr=inet_addr("127.0.0.1");
	sa.sin_family=AF_INET;
	sa.sin_port=htons(6000);
	sa.sin_addr.s_addr=inet_addr("127.0.0.1");
	int c=connect(client,(struct sockaddr *)&sa,sizeof(sa));
	if(c==-1)
	{
		printf("connection failed\n");
		return 0;
	}
	printf("connection established\n");
	while(!strcmp("exit",buf)==0){
	printf("enter the msg -->\n");
	gets(buf);
	send(client,buf,strlen(buf),0);
	printf("msg from server-->");
	int len=sizeof(ca);
	int len1=recv(client,buf2,100,0);
	buf2[len1]='\0';
	printf("%s\n",buf2);
	}
	close(client);
return 0;
}
	
