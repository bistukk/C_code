#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

void InitContact(Contact* pc)
{
	pc->data = (PeoInfo*)malloc(Default_Sz * sizeof(PeoInfo));
	if (pc->data == NULL)
	{
		perror("InitContact");
		return;
	}
	pc->sz = 0;//初始化默认是0;
	pc->capacity = Default_Sz;
}

void Destroy_Contact(Contact* pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->sz = 0;
	pc->capacity=0;
}

void ADDContact(Contact* pc)
{
	if (pc->sz == pc->capacity)
	{
		PeoInfo* ptr = realloc(pc->data, (pc->capacity + Inc_Sz) * sizeof(PeoInfo));
		if (ptr != NULL)
		{
			pc->data = ptr;
			pc->capacity += Inc_Sz;
			printf("增容成功!\n");
		}
		else
		{
			perror("ADDContact");
			printf("增加联系人失败\n");
			return;
		}
	}
	printf("请输入名字:->");
	scanf("%s", pc->data[pc->sz].name);
	printf("请输入年龄:->");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("请输入性别:->");
	scanf("%s", pc->data[pc->sz].sex);
	printf("请输入电话:->");
	scanf("%s", pc->data[pc->sz].tele);
	printf("请输入住址:->");
	scanf("%s", pc->data[pc->sz].addr);
	printf("增加成功\n");
	pc->sz++;
}

void PRINTContact(const Contact* pc)
{
	int i = 0;
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n", "姓名", "年龄", "性别", "电话", "地址");
	for (i = 0; i < pc->sz; i++)
	{
		printf("%-20s\t%-5d\t%-5s\t%-12s\t%-20s\n",
			pc->data[i].name,
			pc->data[i].age,
			pc->data[i].sex,
			pc->data[i].tele,
			pc->data[i].addr);
	}
}

static int Findbyname(Contact* pc, char name[])
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(name, pc->data[i].name) == 0)
		{
			return i;
		}
	}
	return -1;
}

void DELContact(Contact* pc)
{
	//判断通讯录是否为空
	if (pc->sz == 0)
	{
		printf("没有联系人，无需删除\n");
		return;
	}

	//判断要删除的联系人是否存在
	char tmpname[Max_Name];
	printf("请输入要删除人的姓名:\n");
	scanf("%s", tmpname);
	int pos = Findbyname(pc, tmpname);
	if (pos == -1)
	{
		printf("要查找联系人不存在！\n");
		return;//联系人不存在
	}
	//删除联系人
	else
	{
		int i = 0;
		for (i = pos; i < pc->sz - 1; i++)
		{
			pc->data[i] = pc->data[i + 1];
		}
		pc->sz--;
	}
	printf("删除成功!\n");
}

void SEARCHContact(Contact* pc)
{
	char tmpname[Max_Name];
	printf("请输入要查找人的姓名:\n");
	scanf("%s", tmpname);
	int pos = Findbyname(pc, tmpname);
	if (pos == -1)
	{
		printf("要查找的联系人不存在！\n");
		return;
	}
	else
	{
		printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n", "姓名", "年龄", "性别", "电话", "地址");
		printf("%-20s\t%-5d\t%-5s\t%-12s\t%-20s\n",
			pc->data[pos].name,
			pc->data[pos].age,
			pc->data[pos].sex,
			pc->data[pos].tele,
			pc->data[pos].addr);
	}
}

void MODIFYContact(Contact* pc)
{
	char tmpname[Max_Name];
	printf("请输入要修改人的姓名:\n");
	scanf("%s", tmpname);
	int pos = Findbyname(pc, tmpname);
	if (pos == -1)
	{
		printf("要修改的联系人不存在！\n");
		return;
	}
	else
	{
		printf("请输入名字:->");
		scanf("%s", pc->data[pos].name);
		printf("请输入年龄:->");
		scanf("%d", &(pc->data[pos].age));
		printf("请输入性别:->");
		scanf("%s", pc->data[pos].sex);
		printf("请输入电话:->");
		scanf("%s", pc->data[pos].tele);
		printf("请输入住址:->");
		scanf("%s", pc->data[pos].addr);
		printf("修改成功\n");
	}
}

//static int cmp_byname(const void* e1, const void* e2)
//{
//	return strcmp((*(*(Contact*)e1).data).name, (*(*(Contact*)e2).data).name);
//}
//void SORTContact(Contact* pc)
//{
//	qsort(pc->data, pc->sz, sizeof(pc->data[0]), cmp_byname);
//	printf("排序成功!\n");
//	return 0;
//}