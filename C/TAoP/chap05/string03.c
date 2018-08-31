
#include <stdio.h>
#include <conio.h>

/*string03.c*/
void string03()
{
    char *str = "Apple iPod";  // str指向字符串的第一个字符('A'); str是指针变量
    //char str2[11] = "Apple iPod";  // 数组（指针常量）  str2是数组名，表示数组第1个元素的地址。 str2是指针常量，不能进行str2++或str2--操作
    int i;
    printf("字符串str为: ");
    for(i=0;*str != '\0';i++)
    {
        printf("%c",*str);
        str++;  // 这边有个str++呢，不然怎么 *str跟'\0'判断呢
    }
    //getchar();
    //return 0;
}

/*string04.c*/
void string04()
{
    char *str = "Apple iPod";
    int i;
    printf("字符串str为: ");
    for(i=0;str[i] != '\0';i++)
    {
        printf("%c",str[i]);
    }
    //getchar();
    //return 0;
}

/*string05.c*/
void string05()
{
    char *str1 = "Apple iPod";
    char str2[] = "Apple iPod";

    printf("字符串str1为: %s\n",str1);
    printf("字符串str2为: %s\n",str2);
    //system("pause");
    //return 0;
}

/*string07.c*/
void string07()
{
    char *str1 = "Apple iPod";
    char str2[10] = "Apple iPod";  // 分配空间不足

    printf("字符串str1为: %s\n",str1);
    printf("字符串str2为: %s\n",str2);
    //system("pause");
    //return 0;
}


/*string10.c*/
void string10()
{
    char *str1 = "Learning pointer now!";
    char str2[] = "Go ahead";
    char *str3;
    char str4[20];

    str3 = "I want to buy iPad\n";
    printf("C or C++: ");
    scanf("%s",str4);

    printf("\n%s\n",str1);
    printf("%s\n",str2);
    printf("%s\n",str3);
    printf("Learning %s now\n",str4);
    //system("pause");
    //return 0;
}

int main()
{
    string03();
    string04();
    string05();
    string07();
    string10();
    system("pause");
    return 0;
}
