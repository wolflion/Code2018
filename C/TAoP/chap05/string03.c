
#include <stdio.h>
#include <conio.h>

/*string03.c*/
void string03()
{
    char *str = "Apple iPod";  // strָ���ַ����ĵ�һ���ַ�('A'); str��ָ�����
    //char str2[11] = "Apple iPod";  // ���飨ָ�볣����  str2������������ʾ�����1��Ԫ�صĵ�ַ�� str2��ָ�볣�������ܽ���str2++��str2--����
    int i;
    printf("�ַ���strΪ: ");
    for(i=0;*str != '\0';i++)
    {
        printf("%c",*str);
        str++;  // ����и�str++�أ���Ȼ��ô *str��'\0'�ж���
    }
    //getchar();
    //return 0;
}

/*string04.c*/
void string04()
{
    char *str = "Apple iPod";
    int i;
    printf("�ַ���strΪ: ");
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

    printf("�ַ���str1Ϊ: %s\n",str1);
    printf("�ַ���str2Ϊ: %s\n",str2);
    //system("pause");
    //return 0;
}

/*string07.c*/
void string07()
{
    char *str1 = "Apple iPod";
    char str2[10] = "Apple iPod";  // ����ռ䲻��

    printf("�ַ���str1Ϊ: %s\n",str1);
    printf("�ַ���str2Ϊ: %s\n",str2);
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
