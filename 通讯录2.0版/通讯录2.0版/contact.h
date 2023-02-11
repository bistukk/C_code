#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define Max_Name 20
#define Max_Sex 10
#define Max_Tele 20
#define Max_Addr 10
#define Max 100
#define Default_Sz 3
#define Inc_Sz 2

typedef struct PeoInfo
{
	char name[Max_Name];
	int age;
	char sex[Max_Sex];
	char tele[Max_Tele];
	char addr[Max_Addr];
}PeoInfo;

typedef struct Contact
{
	PeoInfo* data;//ָ��̬����Ŀռ䣬���������ϵ�˵���Ϣ��
	int sz;//��¼��ǰͨѶ¼����Ч��Ϣ�ĸ�����
	int capacity;//��¼��ǰͨѶ¼���������
}Contact;

//��ʼ��ͨѶ¼
void InitContact(Contact* pc);

//������ϵ��
void ADDContact(Contact* pc);

//ɾ����ϵ��
void DELContact(Contact* pc);

//������ϵ��
void SEARCHContact(Contact* pc);

//�޸���ϵ��
void MODIFYContact(Contact* pc);

//����
void SORTContact(Contact* pc);

//��ӡ��ϵ����Ϣ
void PRINTContact(const Contact* pc);

//����ͨѶ¼
void Destroy_Contact(Contact* pc);

