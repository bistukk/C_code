#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

void InitContact(Contact* pc)
{
	pc->sz = 0;
	memset(pc->data, 0, sizeof(pc->sz));
}

void ADDContact(Contact* pc)
{
	if (pc->sz == Max)
	{
		printf("ͨѶ¼����\n");
		return;
	}
	printf("����������:->");
	scanf("%s", pc->data[pc->sz].name);
	printf("����������:->");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("�������Ա�:->");
	scanf("%s", pc->data[pc->sz].sex);
	printf("������绰:->");
	scanf("%s", pc->data[pc->sz].tele);
	printf("������סַ:->");
	scanf("%s", pc->data[pc->sz].addr);
	printf("���ӳɹ�\n");
	pc->sz++;
}

void PRINTContact(const Contact* pc)
{
	int i = 0;
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
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
	//�ж�ͨѶ¼�Ƿ�Ϊ��
	if (pc->sz == 0)
	{
		printf("û����ϵ�ˣ�����ɾ��\n");
		return;
	}

	//�ж�Ҫɾ������ϵ���Ƿ����
	char tmpname[Max_Name];
	printf("������Ҫɾ���˵�����:\n");
	scanf("%s", tmpname);
	int pos = Findbyname(pc, tmpname);
	if (pos == -1)
	{
		printf("Ҫ������ϵ�˲����ڣ�\n");
		return;//��ϵ�˲�����
	}
	//ɾ����ϵ��
	else
	{
		int i = 0;
		for (i = pos; i < pc->sz - 1; i++)
		{
			pc->data[i] = pc->data[i + 1];
		}
		pc->sz--;
	}
	printf("ɾ���ɹ�!\n");
}

void SEARCHContact(Contact* pc)
{
	char tmpname[Max_Name];
	printf("������Ҫ�����˵�����:\n");
	scanf("%s", tmpname);
	int pos = Findbyname(pc, tmpname);
	if (pos == -1)
	{
		printf("Ҫ���ҵ���ϵ�˲����ڣ�\n");
		return;
	}
	else
	{
		printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
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
	printf("������Ҫ�޸��˵�����:\n");
	scanf("%s", tmpname);
	int pos = Findbyname(pc, tmpname);
	if (pos == -1)
	{
		printf("Ҫ�޸ĵ���ϵ�˲����ڣ�\n");
		return;
	}
	else
	{
		printf("����������:->");
		scanf("%s", pc->data[pos].name);
		printf("����������:->");
		scanf("%d", &(pc->data[pos].age));
		printf("�������Ա�:->");
		scanf("%s", pc->data[pos].sex);
		printf("������绰:->");
		scanf("%s", pc->data[pos].tele);
		printf("������סַ:->");
		scanf("%s", pc->data[pos].addr);
		printf("�޸ĳɹ�\n");
	}
}

static int cmp_byname(const void* e1, const void* e2)
{
	return strcmp((*(*(Contact*)e1).data).name, (*(*(Contact*)e2).data).name);
}
void SORTContact(Contact* pc)
{
	qsort(pc->data, pc->sz, sizeof(pc->data[0]), cmp_byname);
	printf("����ɹ�!\n");
	return 0;
}
