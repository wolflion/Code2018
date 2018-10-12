#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
void error_handling(char *message)

int main(int argc, char *argv[])
{
	char *addr = "127.232.124.79";
	struct sockaddr_in addr_inet;
	
	if(!inet_aton(addr, &addr_inet.sin_addr))  // 将转换后的IP地址信息保存到sockaddr_in的in_addr型变量才有意义
		error_handling("Conversion error");
	else
		printf("Network ordered integer add: %#x \n",
			addr_inet.sin_addr.s_addr);
	return 0;
}
void error_handling(char *message)
{
	fputs(message,stderr);
	fputc('\n',stderr);
	exit(1);
}
