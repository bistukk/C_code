#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
#include <string.h>
void menu()
{
	printf("******************************\n");
	printf("******************************\n");
	printf("*******1.ADD    2.DELET ******\n");
	printf("*******3.SEARCH 4.MODIFY******\n");
	printf("*******5.SORT   6.PRINT ******\n");
	printf("*******    0.EXIT   **********\n");
	printf("******************************\n");
	printf("******************************\n");
	printf("��ѡ��:->");
}

enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SORT,
	PRINT
};

int main()
{
	int input = 0;
	Contact con;
	InitContact(&con);
	do
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			ADDContact(&con);
			break;
		case DEL:
			DELContact(&con);
			break;
		case SEARCH:
			SEARCHContact(&con);
			break;
		case MODIFY:
			MODIFYContact(&con);
			break;
		case SORT:
			SORTContact(&con);
			break;
		case PRINT:
			PRINTContact(&con);
			break;
		case EXIT:
			printf("�˳�ͨѶ¼\n");
			exit(-1);
			break;
		default:
			printf("ѡ���������ѡ��!\n");
			break;
		}
	} while(1);
	return 0;
}