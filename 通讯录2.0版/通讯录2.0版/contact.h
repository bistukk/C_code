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
	PeoInfo* data;//指向动态申请的空间，用来存放联系人的信息；
	int sz;//记录当前通讯录中有效信息的个数；
	int capacity;//记录当前通讯录的最大容量
}Contact;

//初始化通讯录
void InitContact(Contact* pc);

//增加联系人
void ADDContact(Contact* pc);

//删除联系人
void DELContact(Contact* pc);

//查找联系人
void SEARCHContact(Contact* pc);

//修改联系人
void MODIFYContact(Contact* pc);

//排序
void SORTContact(Contact* pc);

//打印联系人信息
void PRINTContact(const Contact* pc);

//销毁通讯录
void Destroy_Contact(Contact* pc);

