#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define TTL 64
#define BUF_SIZE 30
void error_handling(char *message);

int main(int argc, char *argv[])
{
	int send_sock;
	struct sockaddr_in mul_adr;
	int time_live = TTL;
	FILE *fp;
	char buf[BUF_SIZE];
	if(argc != 3){
		printf("Usage : %s <GroupIP> <PORT>\n", argv[0]);
		exit(1);
	}
	
	send_sock = socket(PF_INET, SOCK_STREAM,0);   // 多播数据通信是通过UDP完成
	memset(&mul_adr,0,sizeof(mul_adr));
	mul_adr.sin_family = AF_INET;
	mul_adr.sin_addr.s_addr = inet_addr(argv[1]);   // Multicast IP   将IP地址设置为多播地址
	mul_adr.sin_port = htons(atoi(argv[2]));        // Multicast Port
	
	setsockopt(send_sock,IPPROTO_IP,
		IP_MULTICAST_TTL,(void*)&time_live,sizeof(time_live));  // 指定套接字TTL信息
	if((fp = fopen("news.txt","r"))==NULL)
		error_handling("fopen() error");
	
	while(!feof(fp))   // Broadcasting
	{
		fgets(buf,BUF_SIZE,fp);
		sendto(send_sock,buf,strlen(buf),
			0,(struct sockaddr*)&mul_adr,sizeof(mul_adr));
		sleep(2);  // 主要是为了给传播数据提供一定的时间间隔而添加的，没有其他特殊意义
	}   // 35-41，实际传输数据的区域。基于UDP传输，需要用到sendto
	fclose(fp);
	close(send_sock);
	return 0;
}

void error_handling(char *message)
{
	fputs(message,stderr);
	fputc('\n',stderr);
	exit(1);
}
