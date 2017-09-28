#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <string.h>

#define port 165

struct sockaddr_in sockaddr1;

int sockfd;

char ipaddr[16];

void clink()
{
	//1:创建socket
	sockfd = socket(AF_INET,SOCK_STREAM,0);

	//2.1:初始化地址
	memset(&sockaddr1,0,sizeof(sockaddr1));  //清空
	sockaddr1.sin_family = AF_INET;　　//协议族，ipv4
	sockaddr1.sin_addr.sin_addr = inet_addr(ipaddr);  //复制地址
	sockaddr1.sin.port = htons(port);　　//端口

	//2.2:连接服务器
	connect(sockfd,(struct sockaddr *)&sockaddr1,sizeof(sockaddr1));

}


int main(int argc, char * args[])
{
	if(argc != 2)
	{
		printf("usage:./client 192.168.12.156 (serverip)\n");
		exit(0);
	}

	strcpy (ipaddr,args[1]);

	//1:建立链接
	 clink();

	//2:实现上传和下载,实现菜单

	//３：关闭连接
}