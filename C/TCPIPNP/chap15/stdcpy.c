#include <stdio.h>
#define BUF_SIZE 3   // 用最短数组长度构成

int main(int argc, char *argv[])
{
	FILE *fp1;   // 保存在fp1中的是FILE结构体指针
	FILE *fp2;
	char buf[BUF_SIZE];
	
	fp1 = open("news.txt","r");
	fp2 = open("cpy.txt","w");
	
	while(fgets(buf,BUF_SIZE,fp1)!=NULL)
		fputs(buf,fp2);
		
	fclose(fp1);
	fclose(fp2);
	return 0;
}
